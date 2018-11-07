ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/IDP205.cpp.o \

PLATFORM_CORE_OBJS = \
	core/UART2.cpp.o \
	core/wiring_analog.c.o \
	core/USBCore.cpp.o \
	core/WMath.cpp.o \
	core/hooks.c.o \
	core/UNO_compat.cpp.o \
	core/WInterrupts.c.o \
	core/UART.cpp.o \
	core/UART1.cpp.o \
	core/UART3.cpp.o \
	core/CDC.cpp.o \
	core/main.cpp.o \
	core/wiring_digital.c.o \
	core/wiring_shift.c.o \
	core/new.cpp.o \
	core/wiring_pulse.c.o \
	core/api/IPAddress.cpp.o \
	core/api/Stream.cpp.o \
	core/api/Common.cpp.o \
	core/api/Print.cpp.o \
	core/api/String.cpp.o \
	core/api/PluggableUSB.cpp.o \
	core/wiring_pulse.S.o \
	core/UART0.cpp.o \
	core/wiring.c.o \
	core/abi.cpp.o \
	core/Tone.cpp.o \

PLATFORM_VARIANT_OBJS = \
	variant/variant.c.o \

LIBRARIES_OBJS = \

TARGETS = \
	IDP205.hex \

all: $(TARGETS)

IDP205.hex: IDP205.elf
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./IDP205.elf" "./IDP205.hex"

IDP205.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega4809  -o "./IDP205.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-size" -A "./IDP205.elf"

project/IDP205.cpp.o: ../../IDP205.cpp project/IDP205.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"

project/IDP205.cpp.d: ;

-include project/IDP205.cpp.d 


core/UART2.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/UART2.cpp core/UART2.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UART2.cpp.d: ;

-include core/UART2.cpp.d

core/wiring_analog.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/USBCore.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WMath.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/hooks.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/UNO_compat.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/UNO_compat.cpp core/UNO_compat.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UNO_compat.cpp.d: ;

-include core/UNO_compat.cpp.d

core/WInterrupts.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/UART.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/UART.cpp core/UART.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UART.cpp.d: ;

-include core/UART.cpp.d

core/UART1.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/UART1.cpp core/UART1.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UART1.cpp.d: ;

-include core/UART1.cpp.d

core/UART3.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/UART3.cpp core/UART3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UART3.cpp.d: ;

-include core/UART3.cpp.d

core/CDC.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/main.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/wiring_digital.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_shift.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/new.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/wiring_pulse.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/api/IPAddress.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/IPAddress.cpp core/api/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/api/IPAddress.cpp.d: ;

-include core/api/IPAddress.cpp.d

core/api/Stream.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/Stream.cpp core/api/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/api/Stream.cpp.d: ;

-include core/api/Stream.cpp.d

core/api/Common.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/Common.cpp core/api/Common.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/api/Common.cpp.d: ;

-include core/api/Common.cpp.d

core/api/Print.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/Print.cpp core/api/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/api/Print.cpp.d: ;

-include core/api/Print.cpp.d

core/api/String.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/String.cpp core/api/String.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/api/String.cpp.d: ;

-include core/api/String.cpp.d

core/api/PluggableUSB.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/PluggableUSB.cpp core/api/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/api/PluggableUSB.cpp.d: ;

-include core/api/PluggableUSB.cpp.d

core/wiring_pulse.S.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UART0.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/UART0.cpp core/UART0.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/UART0.cpp.d: ;

-include core/UART0.cpp.d

core/wiring.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/abi.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/Tone.cpp.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d


variant/variant.c.o: /home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018/variant.c variant/variant.c.d
	@$(call mymkdir,$(dir $@))
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega4809 -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_UNO_WIFI_REV2 -DARDUINO_ARCH_MEGAAVR  -DUNO_WIFI_REV2_328MODE "-I/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino/api/deprecated" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/cores/arduino" -I"/home/tom/.arduinocdt/packages/arduino/hardware/megaavr/1.6.23/variants/uno2018" "$<" -o "$@"
	"/home/tom/.arduinocdt/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
variant/variant.c.d: ;

-include variant/variant.c.d


