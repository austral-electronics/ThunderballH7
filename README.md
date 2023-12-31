# Thunderball H7 OEM – Industrial & Marine Rugged IP67 Calculator / IoT Gateway – STM32H7 Ecosystem
*[www.austral-elec.com](http://austral-eng.com/en/accueil-english-2/) - Intelligent Technologies for Marine, Industrial IoT and Unmanned Vehicles*  

[![ThunderballH7](/SDK/images/Thunderball_H7_OEM.png)](https://austral-eng.com/en/thunderball-h7-oem-industrial-marine-rugged-ip67-mission-calculator-iot-gateway/)

# Applications
The **Thunderball H7 OEM is designed for SWaP-sensitive, robust and real-time applications using remote HMI.**  
It will be embedded into a third-party system in a harsh environment, like wearable edge computing, boats, vehicles, drones, machines, outdoor and underground platforms… and for a wide range of use cases:  
- Interfacing : sensors, actuators, PLCs, mission computer…  
- Datalog : Data collection, Black box…  
- Dashboard : HTML5 dashboard on all browsers and Industrial or marine Multifunction Displays.  
- IoT gateway : Marine IoT, IIoT, Cloud IoT…  
- Marine : Autopilot, Attitude control, Foiler Flight Control System, Wind calculation…  
- Drones / Robotics : ROS2 Client node, Command control, Guidance…  
- Overall Equipment Effectiveness (OEE) : Fleet management, Asset tracking, Machine monitoring, Energy Management, Security systems…  
- Automation : Building, boat and transportation automation, Climate control…  

**Sectors** : Marine, Industry 4.0, Drones, Robotics, Off-Highway Vehicles, Smart Farming …  

[Product Web Page](https://austral-eng.com/en/thunderball-h7-oem-industrial-marine-rugged-ip67-mission-calculator-iot-gateway/)  
## Table of contents
1. [DATASHEET AND WIRING](#hardware)  
2. [STM32H7 ST DOCUMENTATION](#st)  
3. [INSTALL A VSCODE BASED SDK FOR STM32H7](#install)  
3.1. [Note and requirement](#note)  
3.2. [Clone this template with Git](#git)  
3.3. [Install Visual Studio Code](#vscode)  
3.4. [Install STM32 Tools](#st_tools)  
3.5. [Install the compilation toolchain](#toolchain)  
3.6. [Install the OpenOCD debugger tool](#openocd)  
3.7. [Setup VsCode for the debugger](#setup)  
3.8. [Install debug tools](#debug_tools)  
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
7.1. [Ethernet not working](#ethernet)  
8. [DISCLAIMERS](#disclamers)  

## 1. DATASHEET AND WIRING <a name="hardware"></a>
[Hardware specifications and installation guide](https://github.com/austral-electronics/ThunderballH7/tree/main/SDK/doc/Thunderball_H7_OEM_03_Datasheet.pdf)

## 2. STM32H7 ST DOCUMENTATION <a name="st"></a>
[STM32 Embedded Software](https://www.st.com/en/embedded-software/stm32-embedded-software.html)  
[STM32 MCUs Software development tools](https://community.st.com/t5/stm32-mcus-software-development/ct-p/mcu-software-development-tools)  
[STM32Cube MCU Package for STM32H7 series](https://www.st.com/en/embedded-software/stm32cubeh7.html)  
[STM32H743 Datasheet](https://www.st.com/resource/en/datasheet/stm32h743vi.pdf)

## 3. INSTALL A VSCODE BASED SDK FOR STM32H7 <a name="install"></a>
### 3.1. Note and requirement <a name="note"></a>
 - **Note**  
ST offers [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) as code editor, it is the easy way to code rapidly.  
But VSCode is the preferred tool for professionals working on different platforms, OS and languages, especially for the large number of plug-ins.  
Installation of the SDK for visual studio code has recently (March 2023) been simplified by the creation of a VSCode plugin for STM32.  
🔴🔴🔴 **The documentation below does not take the new VSCode for STM32 plugin into account at present.** 🔴🔴🔴  
    - [VSCode for STM32 extension 1.0.0 released](https://community.st.com/t5/other-tools-mcus/vscode-for-stm32-extension-1-0-0-released/td-p/143795)  
    - [STM32 for VSCode VSCode plugin](https://marketplace.visualstudio.com/items?itemName=bmd.stm32-for-vscode)  
    - [How to install the STM32 VS Code Extension?](https://www.youtube.com/watch?v=guNg5OVhakU)  
    - [Get started with Project Manager in the STM32 VS Code Extension](https://www.youtube.com/watch?v=Yhqsh8h_meE)  
    - [Konfiguracja VSCode z STM32 (STM32 VSCode Extension)](https://www.youtube.com/watch?v=1SpRZAZHpTA)  
 - **Requirement**  
This SDK is written for a Windows 10/11, 64 bits computer, but it can be adapted for development under Linux or Mac.  
[Installing STM32CubeMX on Linux or Mac](https://www.st.com/en/development-tools/stm32cubemx.html)

### 3.2. Clone this template with Git <a name="git"></a>
 - **Install Git for windows**  
[Installing Git for Windows tutorial](https://vladmihalcea.com/tutorials/git/windows-git-ssh-authentication-to-github/)

 - **Clone the repository**  
To make a "C:\git" directory and clone the template from github, type in a Windows console :  
```
cd c:\
mkdir git
cd git
git clone https://github.com/austral-electronics/ThunderballH7.git
cd ThunderballH7
dir
```  
Option : You can also install [TortoiseGit](https://tortoisegit.org/) (overlay icons showing the file status) 

### 3.3. Install Visual Studio Code <a name="vscode"></a>

 - [Install Visual Studio code for windows](https://code.visualstudio.com/download)  
 - Install somes plugins :  
    - [C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)  
    - [Cortex Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)  
    - [MemoryView](https://marketplace.visualstudio.com/items?itemName=mcu-debug.memory-view)
    - [GitLens](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens)  
    - [Git Graph](https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph)

### 3.4. Install ST STM32 Tools <a name="st_tools"></a>
 - [Install STM32CubeMX-Win](https://www.st.com/en/development-tools/stm32cubemx.html)  
 - [Install the STM32Cube MCU Package for STM32H7 series](https://www.st.com/en/embedded-software/stm32cubeh7.html)  
 - [Install STM32CubePrg-W64](https://www.st.com/en/development-tools/stm32cubeprog.html) 

### 3.5. Install the compilation toolchain <a name="toolchain"></a>
 - [Download the Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
   select a Windows hosted cross toolchains for AArch32 bare-metal target (arm-none-eabi) in zip format  
   Note : This SDK is tested with [gcc-arm-none-eabi-10.3-2021.10-win32.zip](https://developer.arm.com/downloads/-/gnu-rm/10-3-2021-10)  
 - Unzip the Arm GNU Toolchain in the folder like "C:/git/toolchain". (Take care to replace space with '-' character in path directories)  
 - Download "make" for windows (binary & depedencies) from [The xPack Project](https://xpack.github.io/tags/windows-build-tools/)  
   Note :  
       - This SDK is tested with [xpack-windows-build-tools-4.2.1-2](https://xpack.github.io/tags/windows-build-tools/)  
       - You can also try the "make" from : http://gnuwin32.sourceforge.net/packages/make.htm  
 - Install the "xpack-windows-build-tools-XXX" directory in a folder like "C:/git/toolchain"
 - Add the path of "make" (C:\git\toolchain\xpack-windows-build-tools-XXX\bin) to [environment variables](https://phoenixnap.com/kb/windows-set-environment-variable) of Windows  
 - Test the make link in a Windows console or in a VSCode Terminal
```
C:\git>make -v
GNU Make 4.2.1
Built for x86_64-w64-mingw32
```
### 3.6. Install the debugger tool <a name="openocd"></a>
 - [Download pre-built OpenOCD for Windows](https://gnutoolchains.com/arm-eabi/openocd/)  
   Note : This SDK is tested with the 20211118 version
 - Unzip OpenOCD in a folder like "C:/git/toolchain". (Take care to replace space with '-' char in path directories)

### 3.7. Setup VSCode for the OpenOCD debugger and test the cross-compilation <a name="setup"></a>  
 - If needed modify the "compilerPath" in the file ".vccode/c_cpp_properties.json"  
 - If needed modify the "serverpath" and "gdbPath" in the file ".vccode/launch.json"  
 - If needed modify the "OPENOCD_PATH" and "GCC_PATH" in the "makefile" 
 - Test "make" and "make FLASH=Y" in a VSCode terminal to compile the project and deploy the project in the target

### 3.8. Install debug tools <a name="debug_tools"></a>
[Install PuTTY](https://www.putty.org/)    

### 4. EVALUATE THE AUTOTEST TEMPLATE <a name="test"></a>
### 4.1. Note and requirement <a name="note_autotest"></a>
 - **Note**  
   This template is intentionally as simple as possible, it is a bare metal example, without DMA or interrupt, using the STM32CubeMX Code Generator for peripherals configuration.  
   This template performs the functional test by operating all hardware peripherals as well as the basic software peripherals.  
   You can easily clone this example as the basis for your project, so you won't need the SDK directory.
   
 - **Requirement**
     - To Bootload a new image using the USB Bootloader:  
         - *Thunderball H7 OEM - STM32 H7 Calculator*  
         - *USB-A to USB-C cable (Android phone charging cable)*  
         - *A PC with STM32CubeProgrammer*  

     - To test the Web pages demo:  
         - *M12<->RJ45 Ethernet Cable*  
         - *M12 CANBus Cable (NMEA2000 Cable)*  
         - *12V Power Supply*  
     
     - To compile and test an RS232 Console on COM1 (stdio redirection) as well as the FRAM, RTC and backlight:  
         - *A Binder 620 to DB9 RS232 cable + an USB To Serial DB9 (RS232) Adapter Cable (see Datasheet for wiring)*
         - *A PC with this SDK*  
   
     - To debug in JTAG/SWD:  
         - *Thunderball H7 version with a blind Grommet in the base of the enclosure to access to JTAG/SWD JST connector (See the datasheet)*  
         - *ST-LINK/V2 Probe*  
         - *JST_2_Ribbon_JTAG_Cable - JTAG Adapter (See the datasheet)*  

     - To perform the entire functional test:  
         - *A small CANbus installation with a sensor that periodically transmits frames.*  
         - *A CANbus Analyser (See frames sended)*  
         - *A RS422 point-to-point cable (!!! with terminations and bias resistors !!!) to send data from TX+/TX- on one COM to RX+/RX- on another.*  
         - *A Binder 620 to RS232 RX only DB9 cable (see Datasheet for wiring)*
         - *Another USB To Serial DB9 (RS232) Adapter Cable*  
         - *Strap the RTS to CTS to fully test the COM1 port*  
   
### 4.2. Change the IP Address <a name="ip"></a>
The default IP Adress is static at 192.168.100.222, to change this address edit the file "LWIP/App/lwip.c" line 63

### 4.3. Modify and Compile the Web pages <a name="web"></a>
If you modify the web pages, you must first compile the web pages with makefsdata.exe before compiling the application.  
Put the file [makefsdata.exe](https://github.com/ARMmbed/lwip/tree/master/src/apps/httpd/makefsdata) in the folder middleware/third_party/lwip/scr/apps/httpd and run the executable.  
It will create the file fsdata.c, which must be excluded from the buid right-click on it in the project and resource configuration/exclude.  

Run in the VS Code terminal :  
```
cd .\Middlewares\Third_Party\LwIP\src\apps\http\
.\makefsdata.exe
cd ../../../../../..
``` 
### 4.4. Compile the application <a name="compile"></a>
1. make or make FLASH=Y to compile project and deploy project in the target
   
### 4.5. Debug the template using the ST-LINK/V2 <a name="debug"></a>
### 4.6. Run the template using the USB Bootloader <a name="bootload"></a>
### 4.7. How to test a product with this autotest <a name="autotest"></a>
## 5. MODIFY THE DEVICE CONFIGURATION WITH STM32CUBEMX <a name="cubemx"></a>

#### Setup CubeMx for Ethernet option
- Create the CubeMx project and follow instruction from st: https://community.st.com/s/article/How-to-create-project-for-STM32H7-with-Ethernet-and-LwIP-stack-working  
  If it is a VScode project with a makefile, add "DATA_IN_D2_SRAM" in C defines of the makefile  
- Use origin web page by diseabling custom web page (@ lign 91) in file LWIP\Target\lwipopts.h:  
    HTTPD_USE_CUSTOM_FSDATA 0

- Generate "fsdata.c" by executing "./makefsdata.exe" in the folder: "Middlewares\Third_Party\LwIP\src\apps\http"  

- Exclude fsdata.c from compilation. right clic on file "fsdata.c" and then "Ressource configuration/exclude".  
  If "fsdata.c" is hidden, right clic on project and the refresh.  

- In the main.c file replace MPU_Config function by this one:  
```
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
```
## 6. FAQ & TROUBLESHOOTING <a name="faq"></a>
### 6.1. Ethernet not working <a name="ethernet"></a>
## 7. DISCLAIMERS <a name="disclamers"></a>

*Copyright (C) 2022 [Austral Electronics SARL](http://austral-eng.com/en/accueil-english-2/). Changes to the specifications and features in this manual may be made by Austral without prior notice. Specifications and information provided in this manual are for informational use only. Austral assumes no responsibility or liability for any errors or inaccuracies that may appear in this manual including the product & / or software. All trademarks mentioned in this manual are property of their respective owners. This product contains copyrighted software which are released under multiple open source licenses including but not limited to the GNU GPL, LGPL, and MIT BSD licenses. Such software is provided without warranty. Copies of these licenses are included in the software itself in further detail. For the latest up to date information, please visit our Github Repository at https://github.com/austral-electronics/ThunderballH7*


