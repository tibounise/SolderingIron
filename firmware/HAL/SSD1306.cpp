#include "SSD1306.h"

SSD1306::SSD1306() {
    i2c = I2C::I2C(SSD1306_DEFAULT_ADDRESS);

    sendCommand(SSD1306_DISPLAYOFF);

    sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
    sendCommand(0x80);

    sendCommand(SSD1306_SETMULTIPLEX);
    sendCommand(0x3F);
    
    sendCommand(SSD1306_SETDISPLAYOFFSET);
    sendCommand(0x00);
    
    sendCommand(SSD1306_SETSTARTLINE | 0x00);
    
    sendCommand(SSD1306_CHARGEPUMP);
    sendCommand(0x14);
    
    sendCommand(SSD1306_MEMORYMODE);
    sendCommand(0x00);
    
    sendCommand(SSD1306_SEGREMAP | 0x1);

    sendCommand(SSD1306_COMSCANDEC);

    sendCommand(SSD1306_SETCOMPINS);
    sendCommand(0x12);

    sendCommand(SSD1306_SETCONTRAST);
    sendCommand(0xCF);

    sendCommand(SSD1306_SETPRECHARGE);
    sendCommand(0xF1);

    sendCommand(SSD1306_SETVCOMDETECT);
    sendCommand(0x40);

    sendCommand(SSD1306_DISPLAYALLON_RESUME);

    sendCommand(SSD1306_NORMALDISPLAY);

    sendCommand(SSD1306_DISPLAYON);
}

void SSD1306::sendCommand(uint8_t command) {
    i2c.write(0x00);
    i2c.write(command);
}

void SSD1306::sendData(uint8_t data) {
    i2c.write(0x40);
    i2c.write(data);
}

void SSD1306::sendFramebuffer(uint8_t *buffer) {
    sendCommand(SSD1306_COLUMNADDR);
    sendCommand(0x00);
    sendCommand(127);

    sendCommand(SSD1306_PAGEADDR);
    sendCommand(0);
    sendCommand(7);

    for (uint8_t packet; packet < 64; packet++) {
        i2c.start();
        i2c.write(0x40);
        for (int packet_byte = 0; packet_byte < 16; packet_byte++) {
            i2c.write(buffer[packet*64 + packet_byte]);
        }
        i2c.stop();
    }
}