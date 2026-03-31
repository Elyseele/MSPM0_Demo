################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
usercode/%.o: ../usercode/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"/home/elysia/Software/ti/CCS2050/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/home/elysia/Software/ti/MSPM0_Project/M0_SI5351" -I"/home/elysia/Software/ti/MSPM0_Project/M0_SI5351/Debug" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source/third_party/CMSIS/Core/Include" -I"/home/elysia/Software/ti/SDK/mspm0_sdk_2_10_00_04/source" -I"/home/elysia/Software/ti/MSPM0_Project/M0_SI5351/usercode" -gdwarf-3 -Wall -MMD -MP -MF"usercode/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


