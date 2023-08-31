#This is a Generic Makefile
#@copywrite: Mohamed Nabil

CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m3 -gdwarf-2
LIBS=
INCS=-I .
#-I . means include is in this file

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
##################
Project_name=High_Pressure_Detection_System

##################

all: $(Project_name).bin
	@echo "=========[ Build is Done ]========"
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@	
	
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c  $(INCS) $< -o $@
	
$(Project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
	
clean_all:
	rm *.o *.bin *.elf
	
clean:
	rm *.bin *.elf 	
	
	