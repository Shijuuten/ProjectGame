#ifndef PROGAME_H
#define PROGAME_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"
#include <vector>
#include <GLM/glm.hpp>

namespace Engine {
	class ProGame :
		public Engine::Game 
	{
	public:
		ProGame(Setting* setting);
		~ProGame();
		virtual void Init();
		virtual void Update();
		virtual void Render();
	private:
		Texture* dotTexture = NULL;
		vector<Sprite*> pillar;
		vector<Sprite*> platforms;
		vector<Sprite*> platforms2;
		vector<Sprite*> platforms3;
		vector<Sprite*> platforms4;
		vector<Sprite*> platforms5;
		vector<Sprite*> ground;
		vector<Sprite*> ground2;
		vector<Sprite*> ground3;
		vector<Sprite*> ground4;
		Sprite* monsterSprite = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* projectileSprite = NULL;
		Sprite* Chara2 = NULL;
		Sprite* death = NULL;

		Sprite* dotSprite1 = NULL;
		Sprite* dotSprite2 = NULL;
		Sprite* dotSprite3 = NULL;
		Sprite* dotSprite4 = NULL;

		Sprite* dotProject1 = NULL;
		Sprite* dotProject2 = NULL;
		Sprite* dotProject3 = NULL;
		Sprite* dotProject4 = NULL;

		Music* music = NULL;;
		Sound* sound = NULL;
		Text* text = NULL;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
		float mul = 1;
		bool isProjectileActive = false;
		

		glm::vec2 cameraPos;
		float cameraSpeed;

		void UpdateCamera();
	};
}
#endif