SET PATH=D:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;D:\Git\cmd;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Users\dell\AppData\Local\Microsoft\WindowsApps;
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F407IGTx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=armfly
SET CPU_CLOCK=0x017D7840
"D:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via "armfly\startup_stm32f407xx._ia"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\main.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\gpio.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_it.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_msp.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_tim.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_tim_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_rcc.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_rcc_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_flash.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_flash_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_flash_ramfunc.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_gpio.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_dma_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_dma.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_pwr.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_pwr_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_cortex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\stm32f4xx_hal_exti.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\system_stm32f4xx.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\bsp_led.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\bsp_key.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\bsp.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\eventrecorder.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "armfly\retarget_io.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via "armfly\armfly.lnp"
