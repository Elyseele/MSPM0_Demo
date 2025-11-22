################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/CCSTheia/CCSTheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"syscfg/device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/ti/CCSTheia/Project/OPA_Change" -I"D:/ti/CCSTheia/Project/OPA_Change/Debug" -I"D:/ti/mspm0_sdk_1_30_00_03/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_1_30_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"D:/ti/CCSTheia/Project/OPA_Change/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1975911263: ../OPA_Change.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/ti/CCSTheia/CCSTheia151/ccs/utils/sysconfig_1.21.1/sysconfig_cli.bat" --script "D:/ti/CCSTheia/Project/OPA_Change/OPA_Change.syscfg" -o "syscfg" -s "D:/ti/mspm0_sdk_1_30_00_03/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/device_linker.cmd: build-1975911263 ../OPA_Change.syscfg
syscfg/device.opt: build-1975911263
syscfg/device.cmd.genlibs: build-1975911263
syscfg/ti_msp_dl_config.c: build-1975911263
syscfg/ti_msp_dl_config.h: build-1975911263
syscfg: build-1975911263

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/CCSTheia/CCSTheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"syscfg/device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/ti/CCSTheia/Project/OPA_Change" -I"D:/ti/CCSTheia/Project/OPA_Change/Debug" -I"D:/ti/mspm0_sdk_1_30_00_03/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_1_30_00_03/source" -gdwarf-3 -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"D:/ti/CCSTheia/Project/OPA_Change/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/ti/mspm0_sdk_1_30_00_03/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/CCSTheia/CCSTheia151/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c @"syscfg/device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/ti/CCSTheia/Project/OPA_Change" -I"D:/ti/CCSTheia/Project/OPA_Change/Debug" -I"D:/ti/mspm0_sdk_1_30_00_03/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_1_30_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"D:/ti/CCSTheia/Project/OPA_Change/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


