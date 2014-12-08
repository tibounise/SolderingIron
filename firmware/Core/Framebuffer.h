#include <stdint.h>
#include <avr/pgmspace.h>
#include "../HAL/SSD1306.h"

class Framebuffer {
public:
    Framebuffer();
    void drawBitmap(const uint8_t *bitmap, uint8_t height, uint8_t width, uint8_t pos_x, uint8_t pos_y);
    void drawBuffer(const uint8_t *buffer);
    void drawPixel(uint8_t pos_x, uint8_t pos_y, uint8_t pixel_status);
    void drawVLine(uint8_t pos_x, uint8_t start, uint8_t length);
    void drawHLine(uint8_t pos_y, uint8_t start, uint8_t length);
    void clear();
    void show();
private:
    uint8_t buffer[1024];
    SSD1306 oled;
};