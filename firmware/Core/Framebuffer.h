#include <stdint.h>
#include "../HAL/SSD1306.h"

class Framebuffer {
public:
    Framebuffer();
    void drawBitmap(uint8_t *bitmap, uint8_t height, uint8_t width, uint8_t pos_x, uint8_t pos_y);
    void clear();
    void show();
private:
    uint8_t buffer[1024];
    SSD1306 oled;
};