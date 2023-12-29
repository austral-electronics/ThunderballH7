/*
 * http_ssi.c
 *
 *  Created on: 11-Oct-2021
 *      Author: controllerstech
 */


#include"http_ssi.h"
#include "lwip/tcp.h"
#include "lwip/apps/httpd.h"
#include "stm32h7xx_hal.h"
#include "string.h"

int indx = 0;
/* we will use character "x", "y","z" as tag for SSI */
char const* TAGCHAR[]={"x", "y", "z"};
char const** TAGS=TAGCHAR;

uint16_t ssi_handler (int iIndex, char *pcInsert, int iInsertLen)
{
	// DEBUG_UART("index:%i\r\n", &iIndex);
	// indx+=1;
	// sprintf(pcInsert, "%d", indx);
	// return strlen(pcInsert);
	switch (iIndex) {
		case 0:
			// DEBUG_UART("1\r\n");
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 1:
			// DEBUG_UART("2\r\n");
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 2:
			// DEBUG_UART("3\r\n");
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		default :
			break;
	}

	return 0;
}

/************************ CGI HANDLER ***************************/
const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
const char *CGILED_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

const tCGI FORM_CGI = {"/form.cgi", CGIForm_Handler};
// const tCGI LED_CGI = {"/com2.cgi", CGILED_Handler};
const tCGI LED_CGI = {"/led.cgi", CGILED_Handler};

char name[30];

tCGI CGI_TAB[2];

const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 0)
	{
		// DEBUG_UART("iNumParams: %i\r\n", iNumParams);
		for (int i=0; i<iNumParams; i++)
		{
			if (strcmp(pcParam[i], "C1Enable") == 0)  // if the fname string is found
			{
				memset(name, '\0', 30);
				strcpy(name, pcValue[i]);
				// DEBUG_UART("enable: %s\r\n",pcValue[i]);
			}
			else if (strcmp(pcParam[i], "physics") == 0)  // if the fname string is found
			{
				strcat(name, " ");
				strcpy(name, pcValue[i]);
				// DEBUG_UART("physics: %s\r\n",pcValue[i]);
			}
			else if (strcmp(pcParam[i], "fname") == 0)  // if the fname string is found
			{
				strcat(name, " ");
				strcpy(name, pcValue[i]);
				// DEBUG_UART("protocol: %s\r\n",pcValue[i]);
			}
			else if (strcmp(pcParam[i], "C1baudrate") == 0)  // if the fname string is found
			{
				strcat(name, " ");
				strcat(name, pcValue[i]);
				// DEBUG_UART("baudrate: %s\r\n",pcValue[i]);
			}
		}
	}
	return "/settings.html";
}

// const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
// {
// 	if (iIndex == 0)
// 	{
// 		for (int i=0; i<iNumParams; i++)
// 		{
// 			if (strcmp(pcParam[i], "fname") == 0)  // if the fname string is found
// 			{
// 				memset(name, '\0', 30);
// 				strcpy(name, pcValue[i]);
// 			}

// 			else if (strcmp(pcParam[i], "lname") == 0)  // if the fname string is found
// 			{
// 				strcat(name, " ");
// 				strcat(name, pcValue[i]);
// 			}
// 		}
// 	}

// 	return "/cgiform.html";
// }


const char *CGILED_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 1)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (strcmp(pcParam[i], "C2Enable") == 0)  // if the fname string is found
			{
				memset(name, '\0', 30);
				strcpy(name, pcValue[i]);
			}

			else if (strcmp(pcParam[i], "fname") == 0)  // if the fname string is found
			{
				strcat(name, " ");
				strcpy(name, pcValue[i]);
			}

			else if (strcmp(pcParam[i], "C2baudrate") == 0)  // if the fname string is found
			{
				strcat(name, " ");
				strcat(name, pcValue[i]);
			}
		}
	}

	return "/settings.html";
}

void http_server_init (void)
{
	// httpd_init();

	http_set_ssi_handler((tSSIHandler)ssi_handler, (char const**) TAGS, 3);

	CGI_TAB[0] = FORM_CGI;
	CGI_TAB[1] = LED_CGI;

//	http_set_cgi_handlers (&FORM_CGI, 1);
	http_set_cgi_handlers (CGI_TAB, 2);
}
