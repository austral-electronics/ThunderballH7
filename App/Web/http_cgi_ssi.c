/*
 * http_cgi_ssi.c
 *
 *  Created on: 11-Oct-2021
 *      Author: controllerstech
 */


#include"http_cgi_ssi.h"
#include "lwip/tcp.h"
#include "lwip/apps/httpd.h"
#include "stm32h7xx_hal.h"
#include "string.h"

/************************ SSI HANDLER ***************************/

// From https://controllerstech.com/stm32-ethernet-6-1-http-webserver-cgi/

int indx = 0;
/* we will use character "x", "y","z" as tag for SSI */
char const* TAGCHAR[]={"x", "y", "z"};
char const** TAGS=TAGCHAR;

uint16_t ssi_handler (int iIndex, char *pcInsert, int iInsertLen)
{
	switch (iIndex) {
		case 0:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 1:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 2:
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

// From https://controllerstech.com/stm32-ethernet-6-1-http-webserver-ssi/

const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

const tCGI FORM_CGI = {"/form.cgi", CGIForm_Handler};
char name[30];

const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 0)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (strcmp(pcParam[i], "fname") == 0)  // if the fname string is found
			{
				memset(name, '\0', 30);
				strcpy(name, pcValue[i]);
			}

			else if (strcmp(pcParam[i], "lname") == 0)  // if the fname string is found
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
	httpd_init();
	http_set_ssi_handler((tSSIHandler)ssi_handler, (char const**) TAGS, 3);
	http_set_cgi_handlers (&FORM_CGI, 1);
}