SET PATH=D:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;D:\Git\cmd;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Users\dell\AppData\Local\Microsoft\WindowsApps;
SET CPU_TYPE=STM32F407IGTx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Flash
SET CPU_CLOCK=0x00B71B00
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\main.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\bsp.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\bsp_key.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\bsp_led.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\bsp_timer.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\bsp_uart_fifo.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_it.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\startup_stm32f407xx._ia"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_cortex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_flash.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_gpio.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_rcc.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_tim.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_uart.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_dma.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_tim_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_hal_flash_ex.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\system_stm32f4xx.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\hardfaulthandler._ia"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\segger_hardfaulthandler.__i"
"D:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\project.lnp"
"D:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\project.axf" --i32combined --output ".\Objects\project.hex"
