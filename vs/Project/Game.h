#ifndef BASEGAME_H
#define BASEGAME_H

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <GL/glew.h>
#include <iostream>
#include "Setting.h"
#include "Shader.h"
#include "Quad.h"
#include "Input.h"
#include <GLM/gtc/matrix_transform.hpp>

using namespace std;

namespace Engine {
	enum class State {
		RUNNING,
		EXIT
	};

	enum class ScreenState {
		MAIN_MENU,
		IN_GAME,
		DEATH,
		Win
	};

	class Game
	{
	public:
		Game(Setting* setting);
		~Game();
		void SetBackgroundColor(int r, int g, int b);
		void Run();

		// Added getter functions
		Setting* GetSetting() const { return setting; }
		Shader* GetDefaultSpriteShader() const { return defaultSpriteShader; }
		Shader* GetDefaultTextShader() const { return defaultTextShader; }
		Quad* GetDefaultQuad() const { return defaultQuad; }
		Input* GetInputManager() const { return inputManager; }

		// Added state management functions
		void SetScreenState(ScreenState newState) { screenState = newState; }
		ScreenState GetScreenState() const { return screenState; }
		void SetState(State newState) { state = newState; }
		State GetState() const { return state; }

		// Make GetGameTime accessible
		float GetGetGameTime() const { return deltaTime; }
		unsigned int GetFrameRate() const { return currentFrameRate; }
	
	protected:
		Setting* setting = NULL;
		State state;
		ScreenState screenState; 

		unsigned int currentFrameRate = 0;
		mat4 defaultProjection;
		Shader* defaultSpriteShader = NULL;
		Shader* defaultTextShader = NULL;
		Quad* defaultQuad = NULL;
		Input* inputManager = NULL;
		
		mat4 CreateDefaultProjection();
		Shader* CreateDefaultSpriteShader();
		Shader* CreateDefaultTextShader();
		float GetGameTime();

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
	
	private:
		mat4 projection;
		float targetFrameTime = 0;
		float deltaTime = 0;
		unsigned int lastTime = 0, duration = 0, numFrame = 0;
		
		SDL_Window* InitInternal();
		void GameLoop(SDL_Window* window);
		void CalcDeltaTimeAndFramerate();
		void PollInput();
	};
}

#endif
