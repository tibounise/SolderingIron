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