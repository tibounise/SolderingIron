#include "UI.h"

UI::UI() {

}

void UI::renderSolderingScreen() {
	this->framebuffer.clear();

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

void UI::drawText(char *text, uint8_t pos_x, uint8_t pos_y) {
  uint8_t offset_x = 0;
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
  }
}