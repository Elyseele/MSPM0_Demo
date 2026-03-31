################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"/home/elysia/Software/ti/CCS2050/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/usercode" -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi" -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/Debug" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source" -gdwarf-3 -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1515133747: ../tjc_usart_usart.syscfg
	@echo 'SysConfig - building file: "$<"'
	"/home/elysia/Software/ti/CCS2050/ccs/utils/sysconfig_1.27.0/sysconfig_cli.sh" -s "/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/.metadata/product.json" --script "/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/tjc_usart_usart.syscfg" -o "." --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1515133747 ../tjc_usart_usart.syscfg
device.opt: build-1515133747
device.cmd.genlibs: build-1515133747
ti_msp_dl_config.c: build-1515133747
ti_msp_dl_config.h: build-1515133747
Event.dot: build-1515133747

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"/home/elysia/Software/ti/CCS2050/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/usercode" -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi" -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/Debug" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source" -gdwarf-3 -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g351x_ticlang.o: /home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g351x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"/home/elysia/Software/ti/CCS2050/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/usercode" -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi" -I"/home/elysia/Software/ti/MSPM0_Project/tjc_usart_hmi/Debug" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source" -gdwarf-3 -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


