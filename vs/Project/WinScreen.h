#ifndef WINSCREEN_H
#define WINSCREEN_H

#include "Screen.h"
#include "Button.h"
#include "Text.h"
#include "Game.h"
#include <vector>

namespace Engine {
    class WinScreen : public Screen {
    public:
        void Init(Game* game) override;
        void Update(Game* game) override;
        void Render(Game* game) override;
    private:
        int currentButtonIndex = 0;
        std::vector<Button*> buttons;
        Text* text;
        Text* text2;
        Sprite* BGSprite = NULL;
    };
}

#endif
