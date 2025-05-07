################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
SYSCFG_SRCS += \
../ADC_Without_FIFO.syscfg 

C_SRCS += \
../ADC_Without_FIFO.c \
./ti_msp_dl_config.c \
D:/ti/mspm0_sdk_2_02_00_05/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c \
../adc.c 

GEN_CMDS += \
./device_linker.cmd 

GEN_FILES += \
./device_linker.cmd \
./device.opt \
./ti_msp_dl_config.c 

C_DEPS += \
./ADC_Without_FIFO.d \
./ti_msp_dl_config.d \
./startup_mspm0g350x_ticlang.d \
./adc.d 

GEN_OPTS += \
./device.opt 

OBJS += \
./ADC_Without_FIFO.o \
./ti_msp_dl_config.o \
./startup_mspm0g350x_ticlang.o \
./adc.o 

GEN_MISC_FILES += \
./device.cmd.genlibs \
./ti_msp_dl_config.h \
./Event.dot 

OBJS__QUOTED += \
"ADC_Without_FIFO.o" \
"ti_msp_dl_config.o" \
"startup_mspm0g350x_ticlang.o" \
"adc.o" 

GEN_MISC_FILES__QUOTED += \
"device.cmd.genlibs" \
"ti_msp_dl_config.h" \
"Event.dot" 

C_DEPS__QUOTED += \
"ADC_Without_FIFO.d" \
"ti_msp_dl_config.d" \
"startup_mspm0g350x_ticlang.d" \
"adc.d" 

GEN_FILES__QUOTED += \
"device_linker.cmd" \
"device.opt" \
"ti_msp_dl_config.c" 

C_SRCS__QUOTED += \
"../ADC_Without_FIFO.c" \
"./ti_msp_dl_config.c" \
"D:/ti/mspm0_sdk_2_02_00_05/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c" \
"../adc.c" 

SYSCFG_SRCS__QUOTED += \
"../ADC_Without_FIFO.syscfg" 


