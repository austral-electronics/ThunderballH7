# Thunderball H7 OEM


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



