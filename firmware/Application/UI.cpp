#include "UI.h"

UI::UI() {

}

void UI::renderSolderingScreen() {
	this->framebuffer.clear();

    this->drawText("Hello world",0,0,font_inconsola);

	switch (this->status) {
		case UI::IDLE:
			this->framebuffer.drawBitmap(bmp_idle,16,128,0,48);
			break;
		case UI::HEATING:
			this->framebuffer.drawBitmap(bmp_heating,16,128,0,48);
			break;
		case UI::READY:
			this->framebuffer.drawBitmap(bmp_ready,16,128,0,48);
			break;
	}
	
	this->framebuffer.show();
}

void UI::renderRemoteModeScreen() {
	this->framebuffer.clear();
	this->framebuffer.drawBitmap(bmp_screen_connected,48,108,10,8);
	this->framebuffer.show();
}

void UI::renderSplash() {
	this->framebuffer.drawBuffer(bmp_splash);
	this->framebuffer.show();
}

void UI::drawText(char *text, uint8_t pos_x, uint8_t pos_y, const uint8_t *font) {
  /*uint8_t offset_x = 0;
  for (int i = 0; i < strlen(text); ++i) {
    if (text[i] == '0') {
      this->framebuffer.drawBitmap(bmp_font_zero,13,8,pos_x+offset_x,pos_y);
    }
    if (text[i] == '1') {
      this->framebuffer.drawBitmap(bmp_font_one,13,8,pos_x+offset_x,pos_y);
    }
    if (text[i] == '2') {
      this->framebuffer.drawBitmap(bmp_font_two,13,8,pos_x+offset_x,pos_y);
    }
    offset_x += 9;
  }*/
    uint8_t offset_x = 0;

    // Read informations from the font
    uint8_t character_height = pgm_read_byte(font+1);
    uint8_t character_width = pgm_read_byte(font);
    uint8_t character_length = (character_height*character_width)/8;

    for (uint16_t current_char = 0; current_char < strlen(text); current_char++) {
        this->framebuffer.drawBitmap(4+font+(current_char-32)*character_length,character_height,character_width,pos_x+offset_x,pos_y);
        offset_x += character_width + 1;
    }
}

http://stackoverflow.com/questions/2156572/c-header-file-with-bitmapped-fonts