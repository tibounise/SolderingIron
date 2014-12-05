#include "SSD1306.h"

class Framebuffer {
public:
    Framebuffer();
    void drawBitmap();
private:
    uint8_t buffer[1024];
};