#include "../Core/Framebuffer.h"

class UI {
public:
    UI();
    void renderSolderingScreen();
    void renderRemoteModeScreen();
    void renderWhiteScreen();
    void renderBlackScreen();
private:
    Framebuffer framebuffer;
};