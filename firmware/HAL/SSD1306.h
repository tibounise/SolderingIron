#include "I2C.h"

#define SSD1306_DEFAULT_ADDRESS 0x3C

class SSD1306 {
public:
    SSD1306();
    void SSD1306::sendFramebuffer(uint8_t *buffer);
private:
    void SSD1306::sendCommand(uint8_t command);
    void SSD1306::sendData(uint8_t data);
};