#include "Framebuffer.h"

Framebuffer::Framebuffer() {
	this->clear();
}

void Framebuffer::drawBitmap(uint8_t *bitmap, uint8_t height, uint8_t width, uint8_t pos_x, uint8_t pos_y) {
    
}

void Framebuffer::drawProgmemBuffer(const uint8_t *progmem_buffer) {
	for (uint16_t progmem_byte = 0; progmem_byte < 1024; progmem_byte++) {
		this->buffer[progmem_byte] = pgm_read_byte(progmem_buffer+progmem_byte);
	}
}

void Framebuffer::clear() {
	for (uint16_t buffer_location = 0; buffer_location < 1024; buffer_location++) {
		this->buffer[buffer_location] = 0b01110101;
	}
}

void Framebuffer::show() {
	this->oled.sendFramebuffer(this->buffer);
}