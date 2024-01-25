/*
 * http_cgi_ssi.c
 *
 *  Tutorials : https://controllerstech.com/stm32-ethernet-6-1-http-webserver-cgi/
 *             https://lujji.github.io/blog/esp-httpd/
 *             https://github.com/lujji/esp-httpd
 */

#include"common.h"

/************************ SSI HANDLER ***************************/

int indx = 0;       // counter for SSI demo

const char *pcConfigSSITags[] = {
    "x",        // SSI_X
    "y",        // SSI_Y
    "z",        // SSI_Z
    "uptime",   // SSI_UPTIME
    "heap",     // SSI_FREE_HEAP
    "led"       // SSI_LED_STATE
};

enum {
    SSI_X,
    SSI_Y,
    SSI_Z,
    SSI_UPTIME,
    SSI_HEAP,
    SSI_LED,
};

uint16_t ssi_handler (int iIndex, char *pcInsert, int iInsertLen) {
RTC_TimeTypeDef sTime = {0};
switch (iIndex) {
	case SSI_X:             // "x" ssi_demo.shtml
		sprintf(pcInsert, "%d", ++indx);
		break;
	case SSI_Y:             // "y" ssi_demo.shtml
		sprintf(pcInsert, "%d", ++indx);
		break;
	case SSI_Z:             // "z" ssi_demo.shtml 
		sprintf(pcInsert, "%d", ++indx);
		break;
	case SSI_UPTIME:             // "uptime" cgi_ssi_demo.shtml 
        if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN)== HAL_OK) {
            RTC_DateTypeDef sDate = {0};
            HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); // Unlock RTC
            sprintf(pcInsert,"%lu:%lu:%lu",(uint32_t) (sTime.Hours),(uint32_t) (sTime.Minutes),(uint32_t) (sTime.Seconds));
            }
        else  sprintf(pcInsert, "--:--:--");
		break;
	case SSI_HEAP:             // "heap" cgi_ssi_demo.shtml 
        sprintf(pcInsert, "12345");
		return strlen(pcInsert);
		break;
	case SSI_LED:             // "led" cgi_ssi_demo.shtml 
        if (!HAL_GPIO_ReadPin(CMD_LED_GPIO_Port, CMD_LED_Pin)) sprintf(pcInsert, "On");
        else sprintf(pcInsert, "Off");
		break;
	default :
        return 0;
    }
return strlen(pcInsert);
}

/************************ CGI HANDLERS ***************************/

//----- FORM_CGI : cgi_demo.html -----
const char *CGI_Form_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
char name[30];
if (iIndex == 0) {
	for (int i=0; i<iNumParams; i++) {
		if (strcmp(pcParam[i], "fname") == 0) { // if the fname string is found
			memset(name, '\0', 30);
			strcpy(name, pcValue[i]);
		}
		else if (strcmp(pcParam[i], "lname") == 0) { // if the lname string is found
			strcat(name, " ");
			strcat(name, pcValue[i]);
		}
	}
}
return "/cgi_demo.html";
}

//----- GPIO_CGI : cgi_ssi_demo.html -----
const char *gpio_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
for (int i = 0; i < iNumParams; i++) {
    if (strcmp(pcParam[i], "on") == 0) {
        //uint8_t gpio_num = atoi(pcValue[i]);
        HAL_GPIO_WritePin(CMD_LED_GPIO_Port, CMD_LED_Pin, GPIO_PIN_SET);    // Backlight ON
    } else if (strcmp(pcParam[i], "off") == 0) {
        //uint8_t gpio_num = atoi(pcValue[i]);
        HAL_GPIO_WritePin(CMD_LED_GPIO_Port, CMD_LED_Pin, GPIO_PIN_RESET);  // Backlight OFF
    } else if (strcmp(pcParam[i], "toggle") == 0) {
        //uint8_t gpio_num = atoi(pcValue[i]);
        HAL_GPIO_TogglePin(CMD_LED_GPIO_Port, CMD_LED_Pin);                 // Toggle backlight
    }
}
return "/cgi_ssi_demo.shtml";
}

char *about_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
return "/about.html";
}

char *websocket_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
return "/websockets.html";
}

tCGI pCGIs[] = {
    {"/form.cgi",   (tCGIHandler) CGI_Form_Handler},
    {"/gpio",       (tCGIHandler) gpio_cgi_handler},
    {"/about",      (tCGIHandler) about_cgi_handler},
    {"/websockets", (tCGIHandler) websocket_cgi_handler}
};

/************************ Websockets ***************************/

// !!!!!! The websocket code from https://github.com/lujji/esp-httpd are not recommanded (memory errors) see Mongoose or Websocket2  !!!!

#ifdef WEBSOCKET
void websocket_task(void *pvParameter)
{
    struct tcp_pcb *pcb = (struct tcp_pcb *) pvParameter;

    for (;;) {
        if (pcb == NULL || pcb->state != ESTABLISHED) {
            printf("Connection closed, deleting task\n");
            break;
        }

        int uptime = xTaskGetTickCount() * portTICK_PERIOD_MS / 1000;
        int heap = (int) xPortGetFreeHeapSize();
        int led = !gpio_read(LED_PIN);

        /* Generate response in JSON format */
        char response[64];
        int len = snprintf(response, sizeof (response),
                "{\"uptime\" : \"%d\","
                " \"heap\" : \"%d\","
                " \"led\" : \"%d\"}", uptime, heap, led);
        if (len < sizeof (response))
            websocket_write(pcb, (unsigned char *) response, len, WS_TEXT_MODE);

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

/**
 * This function is called when websocket frame is received.
 *
 * Note: this function is executed on TCP thread and should return as soon
 * as possible.
 */
void websocket_cb(struct tcp_pcb *pcb, uint8_t *data, u16_t data_len, uint8_t mode)
{
    printf("[websocket_callback]:\n%.*s\n", (int) data_len, (char*) data);

    uint8_t response[2];
    uint16_t val;

    switch (data[0]) {
        case 'A': // ADC
            /* This should be done on a separate thread in 'real' applications */
            val = sdk_system_adc_read();
            break;
        case 'D': // Disable LED
            gpio_write(LED_PIN, true);
            val = 0xDEAD;
            break;
        case 'E': // Enable LED
            gpio_write(LED_PIN, false);
            val = 0xBEEF;
            break;
        default:
            printf("Unknown command\n");
            val = 0;
            break;
    }

    response[1] = (uint8_t) val;
    response[0] = val >> 8;

    websocket_write(pcb, response, 2, WS_BIN_MODE);
}

/**
 * This function is called when new websocket is open and
 * creates a new websocket_task if requested URI equals '/stream'.
 */
void websocket_open_cb(struct tcp_pcb *pcb, const char *uri)
{
    printf("WS URI: %s\n", uri);
    if (!strcmp(uri, "/stream")) {
        printf("request for streaming\n");
        xTaskCreate(&websocket_task, "websocket_task", 256, (void *) pcb, 2, NULL);
    }
}
#endif

/************************ Register handlers and start the server *********/

void httpd_task(void) {
http_set_cgi_handlers(pCGIs, sizeof (pCGIs) / sizeof (pCGIs[0]));
http_set_ssi_handler((tSSIHandler) ssi_handler, pcConfigSSITags, sizeof (pcConfigSSITags) / sizeof (pcConfigSSITags[0]));
//websocket_register_callbacks((tWsOpenHandler) websocket_open_cb, (tWsHandler) websocket_cb);
httpd_init();
}
