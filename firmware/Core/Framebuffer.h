#include "SSD1306.h"

class Framebuffer {
public:
    Framebuffer();
    void drawBitmap(uint8_t *bitmap, uint8_t height, uint8_t width);
    void clear();
private:
    uint8_t buffer[1024];
    SSD1306 oled;
};