MCU = atmega1284p
F_CPU = 20000000L

SRC = main.c
TARGET = solderingiron

CXX = avr-g++
CC = avr-gcc

clean:
  rm -f *.o *.hex *.obj

program: $(TARGET).hex
	avrdude -p $(MCU) -c $(PROGRAMMER) -U flash:w:$(TARGET).hex

fuse:
	avrdude -p $(MCU) -c $(PROGRAMMER)