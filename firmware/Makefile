MCU = atmega1284p
AVRDUDE_DEVICE = m1284p
F_CPU = 20000000

INCLUDES = -I./include -I/usr/lib/avr/include
CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) $(DEVICE_SPECIFIC_CFLAGS) $(INCLUDES) -Os 
CPPFLAGS=-fno-exceptions $(INCLUDES) -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
CC=avr-gcc
CXX=avr-g++

OBJ2HEX=avr-objcopy 
LDFLAGS=-Wl,-gc-sections -Wl,-relax 

AVRDUDE=avrdude

TARGET=main
OBJECT_FILES=main.o Application/SolderingIron.o HAL/I2C.o


all: $(TARGET).hex

clean:
	rm -f *.o *.hex *.obj *.hex

%.hex: %.obj
	$(OBJ2HEX) -R .eeprom -O ihex $< $@

main.o: main.cpp
Application/SolderingIron.o: Application/SolderingIron.cpp
HAL/I2C.o: HAL/I2C.cpp

%.obj: $(OBJECT_FILES)
	$(CXX) $(CFLAGS) $(OBJECT_FILES) $(LDFLAGS) -o $@

program: $(TARGET).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c usbtiny -U flash:w:$(TARGET).hex
