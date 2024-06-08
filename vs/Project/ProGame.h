#ifndef PROGAME_H
#define PROGAME_H

#include "Game.h"
#include "MainMenuScreen.h"
#include "InGame.h"
#include "DeathScreen.h"
#include "WinScreen.h"

namespace Engine {
    class ProGame :
        public Engine::Game {
    public:
        ProGame(Setting* setting);
        ~ProGame();
        void Init() override;
        void Update() override;
        void Render() override;

    private:
        MainMenuScreen mainMenuScreen;
        InGame inGameScreen;
        Screen* currentScreen;
        DeathScreen deathScreen;
        WinScreen winScreen;
    };
}
#endif