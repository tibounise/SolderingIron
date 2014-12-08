#include "SolderingIron.h"

SolderingIron::SolderingIron() {
	this->ui.status = UI::IDLE;
	this->ui.renderSolderingScreen();
}