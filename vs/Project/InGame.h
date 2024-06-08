#ifndef INGAME_H
#define INGAME_H

#include "Game.h"
#include "Screen.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"
#include <vector>

namespace Engine {
	class InGame : public Screen {
	public:
		void Init(Game* game) override;
		void Update(Game* game) override;
		void Render(Game* game) override;
	private:
		Texture* dotTexture = NULL;
		vector<Sprite*> pillar;
		vector<Sprite*> platforms;
		vector<Sprite*> platforms2;
		vector<Sprite*> platforms3;
		vector<Sprite*> platforms4;
		vector<Sprite*> platforms5;
		vector<Sprite*> platAtas;
		vector<Sprite*> platAtas2;
		vector<Sprite*> platAtas3;
		vector<Sprite*> platAtas4;
		vector<Sprite*> platAtas5;
		vector<Sprite*> ground;
		vector<Sprite*> ground2;
		vector<Sprite*> ground3;
		vector<Sprite*> ground4;
		Sprite* monsterSprite = NULL;
		Sprite* projectileSprite = NULL;
		Sprite* Chara2 = NULL;
		Sprite* death = NULL;

		Sprite* backgroundSprite = NULL;
		Sprite* dotSprite1 = NULL;
		Sprite* dotSprite2 = NULL;
		Sprite* dotSprite3 = NULL;
		Sprite* dotSprite4 = NULL;

		Sprite* dotProject1 = NULL;
		Sprite* dotProject2 = NULL;
		Sprite* dotProject3 = NULL;
		Sprite* dotProject4 = NULL;

		Music* music = NULL;
		Sound* sound = NULL;
		Sound* soundD = NULL;
		Text* text = NULL;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
		float mul = 1;
		bool isProjectileActive = false;

		glm::vec2 initialMonsterPos;
		glm::vec2 initialChara2;
		std::vector<glm::vec2> initialPlatformPositions;
		std::vector<glm::vec2> initialPlatform2Positions;
		std::vector<glm::vec2> initialPlatform3Positions;
		std::vector<glm::vec2> initialPlatform4Positions;
		std::vector<glm::vec2> initialPlatform5Positions;
		std::vector<glm::vec2> initialPlatform6Positions;
		std::vector<glm::vec2> initialPlatform7Positions;
		std::vector<glm::vec2> initialPlatform8Positions;
		std::vector<glm::vec2> initialPlatform9Positions;
		std::vector<glm::vec2> initialPlatform10Positions;
		std::vector<glm::vec2> initialPlatform11Positions;
		std::vector<glm::vec2> initialPlatform12Positions;
		std::vector<glm::vec2> initialPlatform13Positions;
		std::vector<glm::vec2> initialPlatform14Positions;
		std::vector<glm::vec2> initialPlatform15Positions;

		bool isMonsterDead = false;

		glm::vec2 cameraPos;
		float cameraSpeed;

		void UpdateCamera();
	};
}

#endif