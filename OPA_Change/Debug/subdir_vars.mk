################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
SYSCFG_SRCS += \
../OPA_Change.syscfg 

C_SRCS += \
../OPA_Change.c \
./syscfg/ti_msp_dl_config.c \
D:/ti/mspm0_sdk_1_30_00_03/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c \
../delay.c \
../i2c.c \
../oled.c \
../opa.c \
../printf.c \
../uart.c 

GEN_CMDS += \
./syscfg/device_linker.cmd 

GEN_FILES += \
./syscfg/device_linker.cmd \
./syscfg/device.opt \
./syscfg/ti_msp_dl_config.c 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./OPA_Change.d \
./syscfg/ti_msp_dl_config.d \
./startup_mspm0g350x_ticlang.d \
./delay.d \
./i2c.d \
./oled.d \
./opa.d \
./printf.d \
./uart.d 

GEN_OPTS += \
./syscfg/device.opt 

OBJS += \
./OPA_Change.o \
./syscfg/ti_msp_dl_config.o \
./startup_mspm0g350x_ticlang.o \
./delay.o \
./i2c.o \
./oled.o \
./opa.o \
./printf.o \
./uart.o 

GEN_MISC_FILES += \
./syscfg/device.cmd.genlibs \
./syscfg/ti_msp_dl_config.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg" 

OBJS__QUOTED += \
"OPA_Change.o" \
"syscfg\ti_msp_dl_config.o" \
"startup_mspm0g350x_ticlang.o" \
"delay.o" \
"i2c.o" \
"oled.o" \
"opa.o" \
"printf.o" \
"uart.o" 

GEN_MISC_FILES__QUOTED += \
"syscfg\device.cmd.genlibs" \
"syscfg\ti_msp_dl_config.h" 

C_DEPS__QUOTED += \
"OPA_Change.d" \
"syscfg\ti_msp_dl_config.d" \
"startup_mspm0g350x_ticlang.d" \
"delay.d" \
"i2c.d" \
"oled.d" \
"opa.d" \
"printf.d" \
"uart.d" 

GEN_FILES__QUOTED += \
"syscfg\device_linker.cmd" \
"syscfg\device.opt" \
"syscfg\ti_msp_dl_config.c" 

C_SRCS__QUOTED += \
"../OPA_Change.c" \
"./syscfg/ti_msp_dl_config.c" \
"D:/ti/mspm0_sdk_1_30_00_03/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c" \
"../delay.c" \
"../i2c.c" \
"../oled.c" \
"../opa.c" \
"../printf.c" \
"../uart.c" 

SYSCFG_SRCS__QUOTED += \
"../OPA_Change.syscfg" 


