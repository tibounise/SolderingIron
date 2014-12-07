#include "Framebuffer.h"

Framebuffer::Framebuffer() {
	this->clear();
}

void Framebuffer::drawBitmap(uint8_t *bitmap, uint8_t height, uint8_t width, uint8_t pos_x, uint8_t pos_y) {
    
}

void Framebuffer::clear() {
	for (uint16_t buffer_location = 0; buffer_location < 1024; buffer_location++) {
		this->buffer[buffer_location] = 0b01110101;
	}
}

void Framebuffer::show() {
	this->oled.sendFramebuffer(this->buffer);
}