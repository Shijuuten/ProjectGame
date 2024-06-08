#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "Screen.h"
#include "Button.h"
#include "Text.h"
#include <vector>

namespace Engine {
    class MainMenuScreen : public Screen {
    public:
        void Init(Game* game) override;
        void Update(Game* game) override;
        void Render(Game* game) override;
    private:
        int currentButtonIndex = 0;
        std::vector<Button*> buttons;
        Text* text;
        Sprite* BGSprite = NULL;
    };
}

#endif
