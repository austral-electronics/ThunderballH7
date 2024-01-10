# Thunderball H7 OEM – Industrial & Marine Rugged IP67 Calculator / IoT Gateway – STM32H7 Ecosystem
*[www.austral-elec.com](http://austral-eng.com/en/accueil-english-2/) - Intelligent Technologies for Marine, Industrial IoT and Unmanned Vehicles*  

[![ThunderballH7](/SDK/images/Thunderball_H7_OEM.jpg)](https://austral-eng.com/en/thunderball-h7-oem-industrial-marine-rugged-ip67-mission-calculator-iot-gateway/)

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
6.1. [Forum](#forum)  
6.2. [Ethernet does not work properly](#ethernet_pb)  
6.3. [RS485 does not work properly](#rs485_pb)  
6.4. [USB Bootloader does not work properly](#bootload_pb)  
7. [TUTORIALS](#tuto)  
7.1. [Ethernet](#ethernet_tuto)  
7.2. [FreeRTOS](#freertos_tuto)  
7.3. [CANbus](#canbus_tuto)  
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
    - [Git Graph](https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph)  
    - [~~GitLens~~](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens)
 
### 3.4. Install ST STM32 Tools <a name="st_tools"></a>
 - [Install STM32CubeMX-Win](https://www.st.com/en/development-tools/stm32cubemx.html) 🔴 Select CubeMX Version 6.4.0 🔴  
 - [Install the STM32Cube MCU Package for STM32H7 series](https://www.st.com/en/embedded-software/stm32cubeh7.html)  🔴 If required : Select Version 1.9.1 🔴  
 - [Install STM32CubePrg-W64](https://www.st.com/en/development-tools/stm32cubeprog.html)  
 - [~~Install STM32 ST-LINK Utility~~](https://www.st.com/en/development-tools/stsw-link004.html)  

### 3.5. Install the compilation toolchain <a name="toolchain"></a>
 - [Download the Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
   select a Windows hosted cross toolchains for AArch32 bare-metal target (arm-none-eabi) in zip format  
   Note : This SDK is tested with [gcc-arm-none-eabi-10.3-2021.10-win32.zip](https://developer.arm.com/downloads/-/gnu-rm/10-3-2021-10)  
 - Unzip the Arm GNU Toolchain in the folder like "C:/git/toolchain". (Take care to replace space with '-' character in path directories)
 - Test the "gcc" link in a Windows console or in a VSCode Terminal
```
C:\git\ThunderballH7> ..\\toolchain\\gcc-arm-none-eabi-10.3-2021.10\\bin\\\arm-none-eabi-gcc -v
...
gcc version 10.3.1 20210824 (release) (GNU Arm Embedded Toolchain 10.3-2021.10)
```
 - Download "make" for windows (binary & depedencies) from [The xPack Project](https://xpack.github.io/tags/windows-build-tools/)  
   Note :  
       - This SDK is tested with [xpack-windows-build-tools-4.2.1-2](https://xpack.github.io/tags/windows-build-tools/)  
       - You can also try the "make" from : http://gnuwin32.sourceforge.net/packages/make.htm  
 - Install the "xpack-windows-build-tools-XXX" directory in a folder like "C:/git/toolchain"
 - Add the path of "make" (C:\git\toolchain\xpack-windows-build-tools-XXX\bin) to [environment variables](https://phoenixnap.com/kb/windows-set-environment-variable) of Windows  
 - Test the "make" link in a Windows console or in a VSCode Terminal
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

## 4. EVALUATE THE AUTOTEST TEMPLATE <a name="test"></a>
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
    - A CGI page for your settings  
    - A SSI dynamic page to display datas  
  
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
    - Connect this RS232_RX cable to COM2  
    - Send any character with this COM2 console, you must see "COM2:x" in the COM1 console  
    - Test COM3 to COM5
      
 - **Test the bootloader software jump**  
    - This method may be necessary on products using the USB device port, that do not set BOOT0 by powering with a USB-C cable.  
    - Press 'b' in the COM1 console  
    - Test the bootload with STM32CubeProgrammer

## 5. MODIFY THE DEVICE CONFIGURATION WITH STM32CUBEMX <a name="cubemx"></a>

🔴 **This template was created in early 2022 using "STM32CubeMX" 6.4.0 and "STM32Cube MCU Package for STM32H7" 1.9.1** 🔴  
    
**These versions contain known bugs (Ethernet driver, HTTPD_USE_CUSTOM_FSDATA...) and have been upgraded since.**  
**Some modifications applied after the cubeMX code generation are probably no longer applicable with a newer package version.**  

**Warning : New problems appear with more recent versions of CubeMx using old package or in recent CubeMx and H7 Package.**  
**And ST doesn't provide example for Nucleo using cubeMX and LwIP and doesn't update Nucleo-H743 demos when drivers change.** 
**Changing package versions can be a laborious task.**  
     
With Windows Explorer, click "C:\git\ThunderballH7\ThunderballH7.ioc" to open CubeMX with the template configuration.  
You'll certainly need to change IP, DMAs, Baudrates, Interrupts, FATFS, FREERTOS... in your application if you use this simple template as a basis.  
The default STM32H743VIT6 Pinout is described in the datasheet and the CPU clock is adjust to the max (480Mhz).  

 - **Change IP Address Settings**
   Change the settings in CubeMX->LWIP->General Settings
  
[![ThunderballH7_web_page](/SDK/images/ThunderballH7_STM32CubeMX.png)](https://github.com/austral-electronics/ThunderballH7/edit/main/README.md)  
     
 - **Modifications applied to generated source code after CubeMX automatic code generation:**
    - Use origin web page by diseabling custom web page (@ line 93) in file "LWIP\Target\lwipopts.h": **HTTPD_USE_CUSTOM_FSDATA 0**    
    - Generate "fsdata.c" by executing "./makefsdata.exe" in the folder: "Middlewares\Third_Party\LwIP\src\apps\http"  
    - Compile the project with : make -j8 all  
     
 - **Todo creating a new project:**
    - Create the CubeMx project and follow instruction from st: https://community.st.com/s/article/How-to-create-project-for-STM32H7-with-Ethernet-and-LwIP-stack-working  
    - If it is a VScode project with a makefile, add "DATA_IN_D2_SRAM" in C defines (C_DEFS) of the makefile  
    - Exclude fsdata.c from compilation. right clic on file "fsdata.c" and then "Ressource configuration/exclude".  
      If "fsdata.c" is hidden, right clic on project and the refresh.  

## 6. FAQ & TROUBLESHOOTING <a name="faq"></a>

### 6.1. Forum <a name="forum"></a>
- [STM32 MCUs Embedded software Forum](https://community.st.com/t5/stm32-mcus-embedded-software/bd-p/mcu-embedded-software-forum)  

### 6.2. Ethernet does not work properly <a name="ethernet_pb"></a>
🔴 **There are 2 Ethernet driver bugs (H743 too fast & auto-negociation) in the "STM32Cube MCU Package for STM32H7" version 1.9.1 :** 🔴  
- [PHY driver for LAN8742 issue](https://community.st.com/t5/stm32-mcus-embedded-software/stm32h7-phy-driver-for-lan8742-2s-delay/td-p/112767)  
- [Ethernet low_level_init does not handle return code from LAN8742_init](https://github.com/STMicroelectronics/STM32CubeH7/issues/261)  
- [LAN8742 startup issue](https://community.st.com/t5/stm32cubemx-mcus/h743-and-lan8742-init/m-p/570179)

Waiting for an official Fix from ST :
- We had to introduce a delay of 500 to 1500ms at the boot (main.c, line 149)
- Without this tempo, Ethernet will be at 10Mbs from SWD debug reset and ethernet operation will not be ensured from a power up  
- The duration is depending of the soft reset vs power up and of the ethernet switch auto-negotiation time (switch model, 100MB or 1GB)  
- Note : A delay may be already in lan8742.c on a newer package  

To configure cubeMX, read the ST tutorials :  
- https://community.st.com/t5/stm32-mcus/how-to-create-project-for-stm32h7-with-ethernet-and-lwip-stack/ta-p/49308  
- https://community.st.com/t5/stm32-mcus/ethernet-not-working-on-stm32h7x3/ta-p/49479  
- https://github.com/stm32-hotspot/STM32H7-LwIP-Examples  

### 6.3. RS485 does not work properly <a name="rs485_pb"></a>
See Termination and biasing resistors problem on the datasheet  

### 6.4. USB Bootloader does not work properly <a name="bootload_pb"></a>
There is a new problem which appeared with STM32CubeProgrammer, this error has been [reported](https://community.st.com/t5/stm32cubeprogrammer-mcus/stm32cubeprogrammer-2-14-0-firmware-update-error-over-usb-in/td-p/601282) on the forums in October 2023.  
The USB bootload stops during flashing when the bootload launch was done with a software jump.  
We have found that performing a "Verify" before "Download" significantly improves the probability of success.  
🟢 It works properly with an hardware launch when powering using USB-C (when BOOT0 is maintained at 1 the entire flashing procedure) 🟢   

## 7. TUTORIALS <a name="tuto"></a>

### 7.1. Ethernet <a name="ethernet_tuto"></a>  

- **HTML, CCS, JS:**
  [HTML w3schools.com](https://www.w3schools.com/html/default.asp)
  
- **LwIP : Web Server, TCP, UDP, Ajax, CGI, SSI:**  
  [controllerstech.com](https://controllerstech.com/stm32-ethernet-tutorials/)  

- **Mongoose Web Server :**  
  [Device Web UI dashboard: STM32 :: CubeIDE :: Bare metal :: HTTP, Websocket, MQTT](https://www.youtube.com/watch?v=8htC_TSBeO0)  
  [Mongoose Web Server documentation](https://mongoose.ws/documentation/)  
  [Mongoose Web Server templates for Nucleo-H743ZI2](https://mongoose.ws/documentation/#nucleo-h743zi2)  

### 7.2. FreeRTOS <a name="freertos_tuto"></a>  
[UM1722](https://www.st.com/resource/en/user_manual/um1722-developing-applications-on-stm32cube-with-rtos-stmicroelectronics.pdf)  
[FreeRTOS emcraft](https://www.emcraft.com/products/1090#freertos)  

### 7.3. CANbus <a name="canbus_tuto"></a>  
[FDCAN in Normal mode](https://controllerstech.com/fdcan-normal-mode-stm32/)  

## 8. DISCLAIMERS <a name="disclamers"></a>

*Copyright (C) 2022 [Austral Electronics SARL](http://austral-eng.com/en/accueil-english-2/). Changes to the specifications and features in this manual may be made by Austral without prior notice. Specifications and information provided in this manual are for informational use only. Austral assumes no responsibility or liability for any errors or inaccuracies that may appear in this manual including the product & / or software. All trademarks mentioned in this manual are property of their respective owners. This product contains copyrighted software which are released under multiple open source licenses including but not limited to the GNU GPL, LGPL, and MIT BSD licenses. Such software is provided without warranty. Copies of these licenses are included in the software itself in further detail. For the latest up to date information, please visit our Github Repository at https://github.com/austral-electronics/ThunderballH7*


