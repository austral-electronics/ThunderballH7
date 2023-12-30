# Thunderball H7 OEM – Industrial & Marine Rugged IP67 Calculator / IoT Gateway – STM32H7 Ecosystem
*[www.austral-elec.com](http://austral-eng.com/en/accueil-english-2/) - Intelligent Technologies for Marine, Industrial IoT and Unmanned Vehicles*  

[![ThunderballH7](/SDK/images/Thunderball_H7_OEM.png)](https://austral-eng.com/en/thunderball-h7-oem-industrial-marine-rugged-ip67-mission-calculator-iot-gateway/)

## Table of contents
1. [DATASHEET AND WIRING](#hardware)  
2. [STM32H7 ST DOCUMENTATION](#st)  
3. [INSTALL A VSCODE BASED SDK FOR STM32H7](#install)  
3.1. [Note and requirement](#note)  
3.2. [Clone this template with Git](#git)  
3.3. [Install Visual Studio Code](#vscode)  
3.4. [Install STM32 Tools](#st_tools)  
3.5. [Install the compilation toolchain](#toolchain)  
3.6. [Install the debugger tool](#openocd)  
4. [EVALUATE THE AUTOTEST TEMPLATE](#test)  
4.1. [Note and requirement](#note_autotest)  
4.2. [Change the IP Address](#ip)  
4.3. [Modify and Compile the Web pages](#web)  
4.4. [Compile the application](#compile)  
4.5. [Debug the template using the ST-LINK/V2](#debug)  
4.6. [Run the template using the USB Bootloader](#bootload)  
4.7. [How to test a product with this autotest](#autotest)  
5. [MODIFY THE DEVICE CONFIGURATION WITH STM32CUBEMX](#cubemx)  
6. [FAQ & TROUBLESHOOTING](#faq)  
6.1. [Ethernet not working](#ethernet)  
7.   [DISCLAIMERS](#disclamers)  

## 1. DATASHEET AND WIRING <a name="hardware"></a>

**Download a PDF Hardware specifications and installation** : [Here](https://github.com/austral-electronics/ThunderballH7/tree/main/SDK/doc/Thunderball_H7_OEM_03_Datasheet.pdf)

## 2. STM32H7 ST DOCUMENTATION <a name="st"></a>

## 3. INSTALL A VSCODE BASED SDK FOR STM32H7 <a name="install"></a>
### 3.1. Note and requirement <a name="note"></a>
### 3.2. Clone this template with Git <a name="git"></a>
#### Installing Git for windows
Follow instruction in the link below:
https://vladmihalcea.com/tutorials/git/windows-git-ssh-authentication-to-github/

### 3.3. Install Visual Studio Code <a name="vscode"></a>
### 3.4. Install STM32 Tools <a name="st_tools"></a>
### 3.5. Install the compilation toolchain <a name="toolchain"></a>
### 3.6. Install the debugger tool <a name="openocd"></a>
### 4. EVALUATE THE AUTOTEST TEMPLATE <a name="test"></a>
### 4.1. Note and requirement <a name="note_autotest"></a>
### 4.2. Change the IP Address <a name="ip"></a>
### 4.3. Modify and Compile the Web pages <a name="web"></a>
### 4.4. Compile the application <a name="compile"></a>
### 4.5. Debug the template using the ST-LINK/V2 <a name="debug"></a>
### 4.6. Run the template using the USB Bootloader <a name="bootload"></a>
### 4.7. How to test a product with this autotest <a name="autotest"></a>
## 5. MODIFY THE DEVICE CONFIGURATION WITH STM32CUBEMX <a name="cubemx"></a>
## 6. FAQ & TROUBLESHOOTING <a name="faq"></a>
### 6.1. Ethernet not working <a name="ethernet"></a>
## 7. DISCLAIMERS <a name="disclamers"></a>

## Setup CubeMx for Ethernet option
1. Create the CubeMx project and follow instruction from st:    
        https://community.st.com/s/article/How-to-create-project-for-STM32H7-with-Ethernet-and-LwIP-stack-working
    If it is a VScode project with a makefile, add "DATA_IN_D2_SRAM" in C defines of the makefile


2.  Use origin web page by diseabling custom web page (@ lign 91) in file LWIP\Target\lwipopts.h:
    HTTPD_USE_CUSTOM_FSDATA 0

3. Generate fsdata.c by executing ./makeFSdata.exe in the folder: C:\git\RHP\Middlewares\Third_Party\LwIP\src\apps\http
    cd .\Middlewares\Third_Party\LwIP\src\apps\http\
    .\makefsdata.exe
    cd ../../../../../..
    make

4. Exclude fsdata.c from compilation. right clic on file fsdata.c and then "Ressource configuration/exclude". If fsdata.c is hidden, right clic on project and the refresh.

5. In the main.c file replace MPU_Config function by this one:

    void MPU_Config(void)
    {
        MPU_Region_InitTypeDef MPU_InitStruct;

        /* Disables the MPU */
        HAL_MPU_Disable();
        /**Initializes and configures the Region and the memory to be protected 
        */
        MPU_InitStruct.Enable = MPU_REGION_ENABLE;
        MPU_InitStruct.Number = MPU_REGION_NUMBER2;
        MPU_InitStruct.BaseAddress = 0x30040000;
        MPU_InitStruct.Size = MPU_REGION_SIZE_256B;
        MPU_InitStruct.SubRegionDisable = 0x0;
        MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
        MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
        MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
        MPU_InitStrues and configures the Region and the memory to be protected 
        */
        MPU_InitStruct.Enable = MPU_REGION_ENABLE;
        MPU_InitStruct.Number = MPU_REGION_NUMBER1;
        MPU_InitStruct.BaseAddress = 0x30044000;
        MPU_InitStruct.Size = MPU_REGION_SIZE_16KB;
        MPU_InitStruct.SubRegionDisable = 0x0;
        MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
        MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
        MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;

        HAL_MPU_ConfigRegion(&MPU_InitStruct);

        /**Initializct.TypeExtField = MPU_TEX_LEVEL0;
        MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
        MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
        MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
        MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
        MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

        HAL_MPU_ConfigRegion(&MPU_InitStruct);

        MPU_InitStruct.Enable = MPU_REGION_ENABLE;
        MPU_InitStruct.Number = MPU_REGION_NUMBER0;
        MPU_InitStruct.BaseAddress = 0x30040000;
        MPU_InitStruct.Size = MPU_REGION_SIZE_16KB;
        MPU_InitStruct.SubRegionDisable = 0x0;
        MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
        MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
        MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
        MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
        MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
        MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
        
        HAL_MPU_ConfigRegion(&MPU_InitStruct);

        /* Enables the MPU */
        HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
        }

## Setup vscode for flashing and debugging

1. Download GCC cross compiler:
    https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm

2. Download make for windows (binary & depedencies):
    http://gnuwin32.sourceforge.net/packages/make.htm


3. Download OpenOCD:
    https://gnutoolchains.com/arm-eabi/openocd/

4. Unzip GCC cross compiler and OpenOCD in a folder "toolchain" in the folder that contain the project folder. Take care replace space with '-' char in path directories

5. Install make for windows somewhere and add the path of make to environment variables

6. If needed modify in the file c_cpp_properties.json the compilerPath
7. If needed modify in the file launch.json the serverpath and gdbPath
7. If needed modify in the makefile the openocd path and compiler path 

8. make or make FLASH=Y to compile project and deploy project in the target

## Installing Git for windows
Follow instruction in the link below:
https://vladmihalcea.com/tutorials/git/windows-git-ssh-authentication-to-github/

## Disclaimers <a name="disclamers"></a>
*Copyright (C) 2022 [Austral Electronics SARL](http://austral-eng.com/en/accueil-english-2/). Changes to the specifications and features in this manual may be made by Austral without prior notice. Specifications and information provided in this manual are for informational use only. Austral assumes no responsibility or liability for any errors or inaccuracies that may appear in this manual including the product & / or software. All trademarks mentioned in this manual are property of their respective owners. This product contains copyrighted software which are released under multiple open source licenses including but not limited to the GNU GPL, LGPL, and MIT BSD licenses. Such software is provided without warranty. Copies of these licenses are included in the software itself in further detail. For the latest up to date information, please visit our Github Repository at https://github.com/austral-electronics/ThunderballH7*


