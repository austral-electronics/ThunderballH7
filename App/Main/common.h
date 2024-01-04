/**
 * --------------------------------------------------------------------
 * @file    common.h
 * @author  Austral Electronics
 * @version V1.0
 * @date    01/02/2022
 * @brief   Thunderball H7 : All includes required for the project
 * -------------------------------------------------------------------- */

#ifndef COMMON_H /* only include once */
#define COMMON_H

/*--------- C libraries -----------*/
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/*--------- Generic ST libraries -----------*/
#include "stm32h7xx_hal.h"

/*--------- Third party libraries -----------*/
#include "lwip/apps/httpd.h"

/*--------- Specific to application includes -----------*/
#include "autotest.h"
#include "boot.h"
#include "fram.h"
#include "retarget_stdio.h"
#include "http_cgi_ssi.h"

#endif
