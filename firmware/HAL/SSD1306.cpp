#include "SSD1306.h"

SSD1306::SSD1306() {
    this->i2c = I2C::I2C(SSD1306_DEFAULT_ADDRESS);

    this->sendCommand(SSD1306_DISPLAYOFF);
    this->sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
}

void SSD1306::sendCommand(uint8_t command) {
    this->i2c->write(0x00);
    this->i2c->write(command);
}

void SSD1306::sendData(uint8_t data) {
    this->i2c->write(0x40);
    this->i2c->write(data);
}

void SSD1306::sendFramebuffer(uint8_t *buffer) {
    this->sendCommand(SSD1306_COLUMNADDR);
    this->sendCommand(0x00);
    this->sendCommand(127);

    this->sendCommand(SSD1306_PAGEADDR);
    this->sendCommand(0);
    this->sendCommand(7);

    for (uint8_t packet; packet < 64; packet++) {
        this->i2c->start();
        this->i2c->write(0x40);
        for (int packet_byte = 0; packet_byte < 16; packet_byte++) {
            this->i2c->write(buffer[packet*64 + packet_byte]);
        }
        this->i2c->stop();
    }
}