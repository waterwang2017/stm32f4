SET PATH=D:\Keil_v5\ARM\ARMCC\Bin;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;d:\Git\cmd;C:\Users\28204\AppData\Local\Microsoft\WindowsApps;
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
"D:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" "armfly\armfly.axf" --i32combined --output "armfly\armfly.hex"
