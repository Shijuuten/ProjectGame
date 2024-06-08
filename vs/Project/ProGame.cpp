#include "ProGame.h"

Engine::ProGame::ProGame(Setting* setting) : Game(setting) {
    screenState = ScreenState::MAIN_MENU;
    currentScreen = nullptr;
}

Engine::ProGame::~ProGame() {}

void Engine::ProGame::Init()
{
    mainMenuScreen.Init(this);
    inGameScreen.Init(this);
    deathScreen.Init(this);
    winScreen.Init(this);
    currentScreen = &mainMenuScreen;
}

void Engine::ProGame::Update()
{
    if (screenState == ScreenState::MAIN_MENU) {
        currentScreen = &mainMenuScreen;
    }
    else if (screenState == ScreenState::IN_GAME) {
        currentScreen = &inGameScreen;
    }
    else if (screenState == ScreenState::DEATH) {
        currentScreen = &deathScreen;
    }
    else if (screenState == ScreenState::Win) {
        currentScreen = &winScreen;
    }
    currentScreen->Update(this);
}

void Engine::ProGame::Render()
{
    currentScreen->Render(this);
}

int main(int argc, char** argv) {
    Engine::Setting* setting = new Engine::Setting();
    setting->windowTitle = "Platform Jump";
    setting->screenWidth = 1366;
    setting->screenHeight = 768;
    setting->windowFlag = Engine::WindowFlag::FULLSCREEN;
    setting->vsync = true;
    Engine::Game* game = new Engine::ProGame(setting);
    game->Run();
    delete setting;
    delete game;

    return 0;
}