#include "Framebuffer.h"

Framebuffer::Framebuffer() {
	this->clear();
}

void Framebuffer::drawBitmap(const uint8_t *progmem_bitmap, uint8_t height, uint8_t width, uint8_t pos_x, uint8_t pos_y) {
    uint8_t current_byte;
    uint8_t byte_width = (width + 7)/8;

    for (uint8_t current_y = 0; current_y < height; current_y++) {
        for (uint8_t current_x = 0; current_x < width; current_x++) {
            current_byte = pgm_read_byte(progmem_bitmap + current_y*byte_width + current_x/8);
            if (current_byte & (128 >> (current_x&7))) {
                this->drawPixel(current_x+pos_x,current_y+pos_y,1);
            } else {
                this->drawPixel(current_x+pos_x,current_y+pos_y,0);
            }
        }
    }
}

void Framebuffer::drawBuffer(const uint8_t *progmem_buffer) {
    uint8_t current_byte;

    for (uint8_t y_pos = 0; y_pos < 64; y_pos++) {
        for (uint8_t x_pos = 0; x_pos < 128; x_pos++) {
            current_byte = pgm_read_byte(progmem_buffer + y_pos*16 + x_pos/8);
            if (current_byte & (128 >> (x_pos&7))) {
                this->drawPixel(x_pos,y_pos,1);
            } else {
                this->drawPixel(x_pos,y_pos,0);
            }
        }
    }
}

void Framebuffer::drawPixel(uint8_t pos_x, uint8_t pos_y, uint8_t pixel_status) {
    if (pos_x > 127 || pos_y > 63) {
        return;
    }

    if (pixel_status) {
        this->buffer[pos_x+(pos_y/8)*128] |= (1 << (pos_y&7));
    } else {
        this->buffer[pos_x+(pos_y/8)*128] &= ~(1 << (pos_y&7));
    }
}

void Framebuffer::drawVLine(uint8_t pos_x, uint8_t start, uint8_t length) {

}

void Framebuffer::drawHLine(uint8_t pos_y, uint8_t start, uint8_t length) {
    for (uint8_t i = 0; i < length; ++i) {
        this->drawPixel(i+start,pos_y,1);
    }
}

void Framebuffer::clear() {
	for (uint16_t buffer_location = 0; buffer_location < 1024; buffer_location++) {
		this->buffer[buffer_location] = 0x00;
	}
}

void Framebuffer::show() {
	this->oled.sendFramebuffer(this->buffer);
}