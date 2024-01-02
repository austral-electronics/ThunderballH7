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
1. [DATASHEETS](#hardware)  
2. [ST AND VSCODE LINKS AND DOCUMENTATIONS](#st)  
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
4.5. [Debug the application using the ST-LINK/V2](#debug)  
4.6. [Deploy an image using the USB Bootloader](#bootload)  
4.7. [How to test a product with this Autotest](#autotest)  
5. [MODIFY THE DEVICE CONFIGURATION WITH STM32CUBEMX](#cubemx)  
6. [FAQ & TROUBLESHOOTING](#faq)  
7.1. [Ethernet not working](#ethernet)  
8. [DISCLAIMERS](#disclamers)  

## 1. DATASHEETS <a name="hardware"></a>
[ThunderballH7 Hardware specifications and installation guide](https://github.com/austral-electronics/ThunderballH7/tree/main/SDK/doc/Thunderball_H7_OEM_03_Datasheet.pdf)  
[STM32H743VIT6 Datasheet](https://www.st.com/resource/en/datasheet/stm32h743vi.pdf) 

## 2. ST AND VSCODE LINKS AND DOCUMENTATIONS <a name="st"></a>  
 - **ST Tools Download**  
[STM32 Embedded Software](https://www.st.com/en/embedded-software/stm32-embedded-software.html)  
[STM32 MCUs Software development tools](https://community.st.com/t5/stm32-mcus-software-development/ct-p/mcu-software-development-tools)  
[STM32Cube MCU Package for STM32H7 series](https://www.st.com/en/embedded-software/stm32cubeh7.html)  
[Installing STM32CubeMonitor](https://wiki.st.com/stm32mcu/wiki/STM32CubeMonitor:Installing_STM32CubeMonitor)  
- **ST Tools Tutorials**  
[Introduction to STM32CubeMX](https://wiki.stmicroelectronics.cn/stm32mcu/wiki/Category:STM32CubeMX)  
[Introduction to STM32Cube Expansion Packages](https://wiki.stmicroelectronics.cn/stm32mcu/wiki/Introduction_to_STM32Cube_Expansion_Packages)  
[Introduction and main principles of STM32CubeMonitor](https://wiki.st.com/stm32mcu/wiki/STM32CubeMonitor:Introduction_and_main_principles_of_STM32CubeMonitor)
- **ST STM32H743 Software Examples**  
[NUCLEO-H743ZI](https://github.com/STMicroelectronics/STM32CubeH7/tree/master/Projects/NUCLEO-H743ZI)  
[STM32H743I-EVAL](https://github.com/STMicroelectronics/STM32CubeH7/tree/master/Projects/STM32H743I-EVAL)  
- **VSCode Tutorials and plugins**  
[Get started with VSCode](https://code.visualstudio.com/docs)  
[Extensions for Visual Studio Code](https://marketplace.visualstudio.com/vscode)  

## 3. INSTALL A VSCODE BASED SDK FOR STM32H7 <a name="install"></a>
### 3.1. Note and requirement <a name="note"></a>
 - **Note**  
ST offers [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) as code editor, it is the easy way to code rapidly.  
VSCode is the preferred tool for companies and professionals working on different platforms, OS and languages, especially for the large number of plug-ins and the dark mode. Tool installation on a VSCode SDK is considerably more laborious.  
🔴 _**Installation of the SDK for VSCode has recently been simplified by the publication of a plugin for STM32.**_ 🔴  
🔴 _**The documentation below does not take the new VSCode for STM32 plugin into account at present.**_ 🔴  
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
 - [Install STM32 ST-LINK Utility](https://www.st.com/en/development-tools/stsw-link004.html)

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
The default IP Adress is static at 192.168.100.222.  
To change this address rapidly edit the file "LWIP/App/lwip.c" line 63 and recompile.  
Note : This setting will be erased by CubeMX's automatic code generation, and you will have to change the settings in CubeMX->LWIP->General Settings (See Chapter 5).

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
In a VSCode Terminal :  
 - **Clean and recompile the entire project**
 ```
make clean
make -j8 all
 ```
 - **Compile modified parts of the project**
 ```
make
 ```
 - **Compile and flash the STM32 using the JTAG/SWD tool**
 ```
make FLASH=Y
 ```
### 4.5. Debug the application using the ST-LINK/V2 <a name="debug"></a>

[![ThunderballH7_web_page](/SDK/images/ThunderballH7_debug.png)](https://github.com/austral-electronics/ThunderballH7/edit/main/README.md)  

- Cut off power supply
- Connect the ST-LINK/V2 probe to the JST JTAG/SWD connector (See the datasheet).  
- Power the ThunderballH7
- In VSCode, Flash and Run the application pressing "F5" or "Run" -> "Start Debugging"
- See the "DEBUG CONSOLE" in order to monitor the proper functioning  
- Stop the application with "Shift+F5"

[How to place breakpoints and watch variables, stack and memory](https://www.youtube.com/watch?v=g2Kf6RbdrIs)  
[VSCode Cortex-Debug Launch Configurations](https://www.electrorules.com/vscode-cortex-debug-launch-configurations/)  

### 4.6. Deploy an image using the USB Bootloader <a name="bootload"></a>
This procedure enables on-site software updates for prototypes and small series to be carried out by the customer or a technician, using a simple PC and USB cable.  

[![ThunderballH7_STM32CubeProgrammer](/SDK/images/ThunderballH7_STM32CubeProgrammer.png)](https://github.com/austral-electronics/ThunderballH7/edit/main/README.md)  
- Get a .bin image :
    - Compile the web pages and the application.  
    - The image generated is in "C:\git\ThunderballH7\build\ThunderballH7.bin"  
    - There is also a precompiled test image in "C:\git\ThunderballH7\SDK\Bin\ThunderballH7_autotest.bin"  
- Cut off power supply  
- Launch the STM32CubeProgrammer Software  
- Connect a USB-A to USB-C cable between PC and ThunderballH7  
- The backlight lights up for 2 seconds and you should hear the USB driver notification sound  
- In STM32CubeProgrammer :
    - If required, select "USB" 
    - In USB configuration -> Port you must have USB1 displayed, you can refresh to see it  
    - Click on "Connect"  
    - Open the .bin file with "Memory & File editing" -> "Open file"  
    - Flash with "Download"  
- Unplug the USB cable, an power up the supply.  

### 4.7. How to test a product with this Autotest <a name="autotest"></a>
 - **Test Ethernet**  
Connect the ThunderballH7 to an ethernet switch an power on
Open a windows/VSCode terminal and test the ping : PING 192.168.100.222  
Then open a very simple web pages at 192.168.100.222 with any browser, you will see a menu with 3 tabs:
    - A static page  
    - A settings page  
    - A dynamic page with variable refresh  
  
[![ThunderballH7_web_page](/SDK/images/ThunderballH7_web_page.png)](https://github.com/austral-electronics/ThunderballH7/edit/main/README.md)  

 - **Test COM1 RX & FRAM**  
    - Connect COM1 of the thunderballH7 to a PC using a USB <->RS232 adapter  
    - Open the device manager to see the COMx port name  
    - Open a Console with PuTTY (Serial, COMx, 115200 bauds)  
    - Power up the ThunderballH7, you must see in the serial console :  

[![ThunderballH7_web_page](/SDK/images/ThunderballH7_autotest.png)](https://github.com/austral-electronics/ThunderballH7/edit/main/README.md)  
 
 - **Test RTC, Backlight, COM1 TX/CTS/RTS**  
    - Strap RTS to CTS on COM1  
    - Press "space" in the serial console  
    - You must see :  
        - the time evolve  
        - a toggle on the backlight  
        - a toggle on the COM1 CTS  

 - **Test COM2 to COM5 in RS422/RS485 mode**  
    - A RS422 point-to-point cable (!!! with terminations and bias resistors !!!) is required to send data from TX+/TX- on one COM to RX+/RX- on another.  
    - Connect TX side to COM2 and RX side to COM3 and press "space"  
    - You must see "TX on COM2, RX on COM3 OK"  
    - Strap the next COM ports and restart the test with "space" for the others 3 combinaisons.  
      
 - **Test COM2 to COM5 in RS232 RX only mode**  
    - With a Binder 620 to RS232 RX only DB9 cable (see Datasheet for wiring) and another USB <->RS232 adapter  
    - Open another PuTTY serial console (Serial, COMy, 115200 bauds)  
    - Connect this cable to COM2  
    - Send any character with this console, you must see "COM2:X" in the COM1 console  
    - Test COM3 to COM5
      
 - **Test the bootloader software jump**  
    - This method may be necessary on older hardware versions or products using the USB device mode, that do not set BOOT0 by powering with a USB-C cable.  
    - Press 'b' in the COM1 console  
    - Test the bootload with STM32CubeProgrammer  

## 5. MODIFY THE DEVICE CONFIGURATION WITH STM32CUBEMX <a name="cubemx"></a>

With Windows Explorer, click "C:\git\ThunderballH7\ThunderballH7.ioc" to open CubeMX with the template configuration.  
You'll certainly need to change IP, DMAs, Baudrates, Interrupts, FATFS, FREERTOS... in your application if you use this simple template as a basis.  
The default STM32H743VIT6 Pinout and Clock configuration (400Mhz) is described in the datasheet.  

 - **Change IP Address Settings**
   Change the settings in CubeMX->LWIP->General Settings
  
[![ThunderballH7_web_page](/SDK/images/ThunderballH7_STM32CubeMX.png)](https://github.com/austral-electronics/ThunderballH7/edit/main/README.md)  

 - **Modifications applied to source code after CubeMX automatic code generation:**

    🔴 **This template was created in 2021 using "STM32CubeMX" 6.4.0 and "STM32Cube MCU Package for STM32H7" 1.9.1** 🔴  
    🔴 **These versions are buggy (Ethernet, MPU_Config...) and have certainly been upgraded since** 🔴  
    🔴 **Some modifications are probably no longer applicable with a newer package version** 🔴  

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


