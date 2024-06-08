#include "DeathScreen.h"
#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"

void Engine::DeathScreen::Init(Game* game) {
    Setting* setting = game->GetSetting();
    // Create a Texture
    Texture* texture = new Texture("YesNo.png");
    Texture* textureBG = new Texture("BigBG.png");

    // Create Sprites
    Sprite* playSprite = new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
    playSprite->SetNumXFrames(2);
    playSprite->SetNumYFrames(2);
    playSprite->AddAnimation("normal", 0, 0);
    playSprite->AddAnimation("hover", 0, 1);
    playSprite->AddAnimation("press", 0, 1);
    playSprite->SetSize(566, 268);
    playSprite->SetAnimationDuration(200);

    Sprite* exitSprite = new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
    exitSprite->SetNumXFrames(2);
    exitSprite->SetNumYFrames(2);
    exitSprite->AddAnimation("normal", 2, 2);
    exitSprite->AddAnimation("hover", 2, 3);
    exitSprite->AddAnimation("press", 2, 3);
    exitSprite->SetSize(566, 268);
    exitSprite->SetAnimationDuration(200);

    //background panel
    BGSprite = new Sprite(textureBG, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
    BGSprite->SetSize(setting->screenWidth, setting->screenHeight);

    // Create Buttons
    Button* playButton = new Button(playSprite, "play");
    playButton->SetPosition((setting->screenWidth / 2) - (playSprite->GetScaleWidth() / 2), 400);
    buttons.push_back(playButton);
    Button* exitButton = new Button(exitSprite, "exit");
    exitButton->SetPosition((setting->screenWidth / 2) - (exitSprite->GetScaleWidth() / 2), 250);
    buttons.push_back(exitButton);

    // Set play button into active button
    currentButtonIndex = 0;
    buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);

    // Create Text
    text = new Text("Retro.ttf", 100, game->GetDefaultTextShader());
    text->SetText("Game Over");
    text->SetScale(1.5);
    text->SetPosition((setting->screenWidth/2)-450, setting->screenHeight - 300);
    text->SetColor(250, 249, 246);

    text2 = new Text("Retro.ttf", 100, game->GetDefaultTextShader());
    text2->SetText("Play Again?");
    text2->SetScale(0.5);
    text2->SetPosition((setting->screenWidth / 2) - 180, setting->screenHeight - 450);
    text2->SetColor(250, 249, 246);

    // Add input mappings
    game->GetInputManager()->AddInputMapping("next", SDLK_DOWN);
    game->GetInputManager()->AddInputMapping("prev", SDLK_UP);
    game->GetInputManager()->AddInputMapping("press", SDLK_RETURN);
}

void Engine::DeathScreen::Update(Game* game) {
    // Set background
    game->SetBackgroundColor(0, 0, 0);

    if (game->GetInputManager()->IsKeyReleased("next")) {
        // Set previous button to normal state
        buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::NORMAL);
        // Next Button
        currentButtonIndex = currentButtonIndex < buttons.size() - 1 ? currentButtonIndex + 1 : currentButtonIndex;
        // Set current button to hover state
        buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);
    }

    if (game->GetInputManager()->IsKeyReleased("prev")) {
        // Set previous button to normal state
        buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::NORMAL);
        // Prev Button
        currentButtonIndex = currentButtonIndex > 0 ? currentButtonIndex - 1 : currentButtonIndex;
        // Set current button to hover state
        buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);
    }

    if (game->GetInputManager()->IsKeyReleased("press")) {
        // Set current button to press state
        Button* b = buttons[currentButtonIndex];
        b->SetButtonState(Engine::ButtonState::PRESS);
        // If play button then go to InGame, exit button then exit
        if ("play" == b->GetButtonName()) {
            game->SetScreenState(Engine::ScreenState::IN_GAME);
        }
        else if ("exit" == b->GetButtonName()) {
            game->SetState(Engine::State::EXIT);
        }
    }

    // Update All buttons
    for (Button* b : buttons) {
        b->Update(game->GetGetGameTime());
    }
}

void Engine::DeathScreen::Render(Game* game) {
    //render background
    BGSprite->Draw();
    // Render all buttons
    for (Button* b : buttons) {
        b->Draw();
    }
    // Render title 
    text->Draw();
    text2->Draw();
}
