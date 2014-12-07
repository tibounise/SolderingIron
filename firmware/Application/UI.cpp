#include "UI.h"

UI::UI() {

}

void UI::renderSolderingScreen() {

}

void UI::renderRemoteModeScreen() {
	this->framebuffer.drawProgmemBuffer(bmp_screen_connected);
	this->framebuffer.show();
}

void UI::renderWhiteScreen() {
	this->framebuffer.clear();
	this->framebuffer.show();
}

void UI::renderBlackScreen() {

}