#include "ProGame.h"

using namespace Engine;

ProGame::ProGame(Setting* setting) :Game(setting)
{

}

ProGame::~ProGame(){

	delete dotTexture;
	delete monsterSprite;
	delete dotSprite1;
	delete dotSprite2;
	delete dotSprite3;
	delete dotSprite4;
	delete dotProject1;
	delete dotProject2;
	delete dotProject3;
	delete dotProject4;
	delete music;
	delete text;
}

void ProGame::Init() {

	// Generate Platforms
	//pilar
	Texture* pillarTexture = new Texture("platNaik.png");
	vec2 awal = vec2(2500, -191);

	int pillarPerRow = 1; // Jumlah pillar di baris pertama
	int pillarCount = 0; // Menghitung jumlah pillar yang telah dibuat
	for (int row = 0; pillarCount < 10; row++) {
		for (int i = 0; i < pillarPerRow && pillarCount < 10; i++) {
			Sprite* pillarSprite = new Sprite(pillarTexture, defaultSpriteShader, defaultQuad);
			// Hitung posisi X untuk menempatkan pillar di tengah
			float posX = awal.x - (i * 300);
			// Posisi Y dimulai dari bawah dan naik ke atas setiap baris
			float posY = awal.y + (7 - row) * 64;
			pillarSprite->SetPosition(posX, posY);
			pillarSprite->SetSize(64, 64);
			pillarSprite->SetBoundingBoxSize(pillarSprite->GetScaleWidth() - (16 * pillarSprite->GetScale()), pillarSprite->GetScaleHeight());
			pillar.push_back(pillarSprite);
			pillarCount++;
		}
		pillarPerRow++; // Tambah jumlah pillar di baris berikutnya
	}

	//piramid kiri jatuh
	Texture* platformTexture = new Texture("platNaik.png");
	vec2 start = vec2(7440, -191);

	int platformsPerRow = 1; // Jumlah platform di baris pertama
	int platformCount = 0; // Menghitung jumlah platform yang telah dibuat
	for (int row = 0; platformCount < 10; row++) {
		for (int i = 0; i < platformsPerRow && platformCount < 10; i++) {
			Sprite* platformSprite = new Sprite(platformTexture, defaultSpriteShader, defaultQuad);
			// Hitung posisi X untuk menempatkan platform di tengah
			float posX = start.x - (i * 64);
			// Posisi Y dimulai dari bawah dan naik ke atas setiap baris
			float posY = start.y + (7 - row) * 64;
			platformSprite->SetPosition(posX, posY);
			platformSprite->SetSize(64, 64);
			platformSprite->SetBoundingBoxSize(platformSprite->GetScaleWidth() - (16 * platformSprite->GetScale()), platformSprite->GetScaleHeight());
			platforms.push_back(platformSprite);
			platformCount++;
		}
		platformsPerRow++; // Tambah jumlah platform di baris berikutnya
	}
	//piramid kanan jatuh
	Texture* platform2Texture = new Texture("platNaik.png");
	vec2 start2 = vec2(7650, -191);

	int platforms2PerRow = 1; // Jumlah platform di baris pertama
	int platform2Count = 0; // Menghitung jumlah platform yang telah dibuat
	for (int row = 0; platform2Count < 10; row++) {
		for (int i = 0; i < platforms2PerRow && platform2Count < 10; i++) {
			Sprite* platform2Sprite = new Sprite(platform2Texture, defaultSpriteShader, defaultQuad);
			// Hitung posisi X untuk menempatkan platform di tengah
			float posX = start2.x + (i * 64);
			// Posisi Y dimulai dari bawah dan naik ke atas setiap baris
			float posY = start2.y + (7 - row) * 64;
			platform2Sprite->SetPosition(posX, posY);
			platform2Sprite->SetSize(64, 64);
			platform2Sprite->SetBoundingBoxSize(platform2Sprite->GetScaleWidth() - (16 * platform2Sprite->GetScale()), platform2Sprite->GetScaleHeight());
			platforms2.push_back(platform2Sprite);
			platform2Count++;
		}
		platforms2PerRow++; // Tambah jumlah platform di baris berikutnya
	}
	//piramid kanan
	Texture* platform3Texture = new Texture("platNaik.png");
	vec2 start3 = vec2(6700, -191);

	int platforms3PerRow = 1; // Jumlah platform di baris pertama
	int platform3Count = 0; // Menghitung jumlah platform yang telah dibuat
	for (int row = 0; platform3Count < 10; row++) {
		for (int i = 0; i < platforms3PerRow && platform3Count < 10; i++) {
			Sprite* platform3Sprite = new Sprite(platform3Texture, defaultSpriteShader, defaultQuad);
			// Hitung posisi X untuk menempatkan platform di tengah
			float posX = start3.x + (i * 64);
			// Posisi Y dimulai dari bawah dan naik ke atas setiap baris
			float posY = start3.y + (7 - row) * 64;
			platform3Sprite->SetPosition(posX, posY);
			platform3Sprite->SetSize(64, 64);
			platform3Sprite->SetBoundingBoxSize(platform3Sprite->GetScaleWidth() - (16 * platform3Sprite->GetScale()), platform3Sprite->GetScaleHeight());
			platforms3.push_back(platform3Sprite);
			platform3Count++;
		}
		platforms3PerRow++; // Tambah jumlah platform di baris berikutnya
	}
	//piramid kiri
	Texture* platform4Texture = new Texture("platNaik.png");
	vec2 start4 = vec2(6500, -191);

	int platforms4PerRow = 1; // Jumlah platform di baris pertama
	int platform4Count = 0; // Menghitung jumlah platform yang telah dibuat
	for (int row = 0; platform4Count < 10; row++) {
		for (int i = 0; i < platforms4PerRow && platform4Count < 10; i++) {
			Sprite* platform4Sprite = new Sprite(platform4Texture, defaultSpriteShader, defaultQuad);
			// Hitung posisi X untuk menempatkan platform di tengah
			float posX = start4.x - (i * 64);
			// Posisi Y dimulai dari bawah dan naik ke atas setiap baris
			float posY = start4.y + (7 - row) * 64;
			platform4Sprite->SetPosition(posX, posY);
			platform4Sprite->SetSize(64, 64);
			platform4Sprite->SetBoundingBoxSize(platform4Sprite->GetScaleWidth() - (16 * platform4Sprite->GetScale()), platform4Sprite->GetScaleHeight());
			platforms4.push_back(platform4Sprite);
			platform4Count++;
		}
		platforms4PerRow++; // Tambah jumlah platform di baris berikutnya
	}
	//piramid ending
	Texture* platform5Texture = new Texture("platNaik.png");
	vec2 start5 = vec2(9800, 0);

	int platforms5PerRow = 1; // Jumlah platform di baris pertama
	int platform5Count = 0; // Menghitung jumlah platform yang telah dibuat
	for (int row = 0; platform5Count < 28; row++) {
		for (int i = 0; i < platforms5PerRow && platform5Count < 28; i++) {
			Sprite* platform5Sprite = new Sprite(platform5Texture, defaultSpriteShader, defaultQuad);
			// Hitung posisi X untuk menempatkan platform di tengah
			float posX = start5.x - (i * 64);
			// Posisi Y dimulai dari bawah dan naik ke atas setiap baris
			float posY = start5.y + (7 - row) * 64;
			platform5Sprite->SetPosition(posX, posY);
			platform5Sprite->SetSize(64, 64);
			platform5Sprite->SetBoundingBoxSize(platform5Sprite->GetScaleWidth() - (16 * platform5Sprite->GetScale()), platform5Sprite->GetScaleHeight());
			platforms5.push_back(platform5Sprite);
			platform5Count++;
		}
		platforms5PerRow++; // Tambah jumlah platform di baris berikutnya
	}

	//jalur atas
	Texture* platAtasTexture = new Texture("platAtas.png");
	vec2 hajime = vec2(2750, 450);
	for (int i = 0; i < 10; i++) {
		Sprite* platAtasSprite = new Sprite(platAtasTexture, defaultSpriteShader, defaultQuad);
		platAtasSprite->SetPosition(hajime.x + i * 120, hajime.y);
		platAtasSprite->SetSize(64, 64);
		platAtasSprite->SetBoundingBoxSize(platAtasSprite->GetScaleWidth() - (16 * platAtasSprite->GetScale()), platAtasSprite->GetScaleHeight());
		platAtas.push_back(platAtasSprite);
	}
	Texture* platAtas2Texture = new Texture("platAtas.png");
	vec2 hajime2 = vec2(4150, 550);
	for (int i = 0; i < 18; i++) {
		Sprite* platAtas2Sprite = new Sprite(platAtas2Texture, defaultSpriteShader, defaultQuad);
		platAtas2Sprite->SetPosition(hajime2.x + i * 64, hajime2.y);
		platAtas2Sprite->SetSize(64, 64);
		platAtas2Sprite->SetBoundingBoxSize(platAtas2Sprite->GetScaleWidth() - (16 * platAtas2Sprite->GetScale()), platAtas2Sprite->GetScaleHeight());
		platAtas2.push_back(platAtas2Sprite);
	}
	Texture* platAtas3Texture = new Texture("platAtas.png");
	vec2 hajime3 = vec2(5350, 400);
	for (int i = 0; i < 9; i++) {
		Sprite* platAtas3Sprite = new Sprite(platAtas3Texture, defaultSpriteShader, defaultQuad);
		platAtas3Sprite->SetPosition(hajime3.x + i * 115, hajime3.y);
		platAtas3Sprite->SetSize(64, 64);
		platAtas3Sprite->SetBoundingBoxSize(platAtas3Sprite->GetScaleWidth() - (16 * platAtas3Sprite->GetScale()), platAtas3Sprite->GetScaleHeight());
		platAtas3.push_back(platAtas3Sprite);
	}
	
	//jalur bawah
	Texture* groundTexture = new Texture("TilesAtas.png");	
	vec2 mulai = vec2(3, 1);
	for (int i = 0; i < 25; i++) {
		Sprite* groundSprite = new Sprite(groundTexture, defaultSpriteShader, defaultQuad);
		groundSprite->SetPosition(mulai.x + i * 150,mulai.y);
		groundSprite->SetSize(150, 64);
		groundSprite->SetBoundingBoxSize(groundSprite->GetScaleWidth() - (16 * groundSprite->GetScale()), groundSprite->GetScaleHeight());
		ground.push_back(groundSprite);
	}
	
	Texture* ground2Texture = new Texture("TilesAtas.png");
	vec2 mulai2 = vec2(3900, 1);
	for (int i = 0; i < 8; i++) {
		Sprite* ground2Sprite = new Sprite(ground2Texture, defaultSpriteShader, defaultQuad);
		ground2Sprite->SetPosition(mulai2.x + i * 150, mulai2.y);
		ground2Sprite->SetSize(150, 64);
		ground2Sprite->SetBoundingBoxSize(ground2Sprite->GetScaleWidth() - (16 * ground2Sprite->GetScale()), ground2Sprite->GetScaleHeight());
		ground2.push_back(ground2Sprite);
	}

	Texture* ground3Texture = new Texture("TilesAtas.png");
	vec2 mulai3 = vec2(5250, 1);
	for (int i = 0; i < 15; i++) {
		Sprite* ground3Sprite = new Sprite(ground3Texture, defaultSpriteShader, defaultQuad);
		ground3Sprite->SetPosition(mulai3.x + i * 150, mulai3.y);
		ground3Sprite->SetSize(150, 64);
		ground3Sprite->SetBoundingBoxSize(ground3Sprite->GetScaleWidth() - (16 * ground3Sprite->GetScale()), ground3Sprite->GetScaleHeight());
		ground3.push_back(ground3Sprite);
	}

	Texture* ground4Texture = new Texture("TilesAtas.png");
	vec2 mulai4= vec2(7650, 1);
	for (int i = 0; i < 25; i++) {
		Sprite* ground4Sprite = new Sprite(ground4Texture, defaultSpriteShader, defaultQuad);
		ground4Sprite->SetPosition(mulai4.x + i * 150, mulai4.y);
		ground4Sprite->SetSize(150, 64);
		ground4Sprite->SetBoundingBoxSize(ground4Sprite->GetScaleWidth() - (16 * ground4Sprite->GetScale()), ground4Sprite->GetScaleHeight());
		ground4.push_back(ground4Sprite);
	}

	// Simpan posisi awal setiap kelompok platform
	for (Sprite* s : pillar) {
		initialPlatformPositions.push_back(s->GetPosition());
	}
	for (Sprite* s : platforms) {
		initialPlatform2Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platforms2) {
		initialPlatform3Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platforms3) {
		initialPlatform4Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platforms4) {
		initialPlatform5Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platforms5) {
		initialPlatform6Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platAtas) {
		initialPlatform7Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platAtas2) {
		initialPlatform8Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platAtas3) {
		initialPlatform9Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platAtas4) {
		initialPlatform10Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : platAtas5) {
		initialPlatform11Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : ground) {
		initialPlatform12Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : ground2) {
		initialPlatform13Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : ground3) {
		initialPlatform14Positions.push_back(s->GetPosition());
	}
	for (Sprite* s : ground4) {
		initialPlatform15Positions.push_back(s->GetPosition());
	}

	//Create background
	Texture* bgTexture = new Texture("bg.png");
	backgroundSprite = new Sprite(bgTexture, defaultSpriteShader, defaultQuad);
	backgroundSprite->SetSize(setting->screenWidth, setting->screenHeight);

	
	Texture* monsterTexture = new Texture("monster.png");
	monsterSprite = new Sprite(monsterTexture, defaultSpriteShader, defaultQuad);
	monsterSprite->SetPosition(0, 66);
	monsterSprite->SetNumXFrames(6);
	monsterSprite->SetNumYFrames(3);
	monsterSprite->SetAnimationDuration(70);
	monsterSprite->SetScale(2.0f);
	monsterSprite->AddAnimation("attack", 13, 14);
	monsterSprite->AddAnimation("idle", 0, 3);
	monsterSprite->AddAnimation("run", 6, 11);
	monsterSprite->AddAnimation("die", 0, 14);
	initialMonsterPos = monsterSprite->GetPosition();
	// If frame size / sprite size is contain blank space or padding then you must resize the bounding box
	// or collision shape to improve collision detection accuracy
	//Chara2->SetBoundingBoxSize(Chara2->GetScaleWidth() - (8 * Chara2->GetScale()),
		//Chara2->GetScaleHeight() - (1 * Chara2->GetScale()));

	// Projectile Texture
	Texture* ProjectileTexture = new Texture("Flamme.png");
	projectileSprite = new Sprite(ProjectileTexture, defaultSpriteShader, defaultQuad);
	projectileSprite->SetPosition(100, 5);
	projectileSprite->SetNumXFrames(6);
	projectileSprite->SetNumYFrames(1);
	projectileSprite->SetAnimationDuration(70);
	projectileSprite->SetScale(5);
	projectileSprite->SetAnimationDuration(90);
	projectileSprite->AddAnimation("Idle-1", 0, 5);
	projectileSprite->SetBoundingBoxSize(projectileSprite->GetScaleWidth() - (25 * projectileSprite->GetScale()),
		projectileSprite->GetScaleHeight() - (10 * projectileSprite->GetScale()));

	Texture* chara2Texture = new Texture("idle2.png");
	Chara2 = new Sprite(chara2Texture, defaultSpriteShader, defaultQuad);
	Chara2->SetNumXFrames(4);
	Chara2->SetNumYFrames(2);
	Chara2->AddAnimation("idle", 0, 7);
	Chara2->AddAnimation("walk", 6, 11);
	Chara2->PlayAnim("idle");
	Chara2->SetPosition(1150, 0);
	Chara2->SetFlipHorizontal(1);
	Chara2->SetScale(3);
	Chara2->SetAnimationDuration(90);
	Chara2->SetBoundingBoxSize(Chara2->GetScaleWidth() - (8 * Chara2->GetScale()),
		Chara2->GetScaleHeight() - (1 * Chara2->GetScale()));



	// This dot sprite is for visual debugging (to see the actual bounding box) 
	dotTexture = new Texture("dot.png");
	dotSprite1 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotSprite2 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotSprite3 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotSprite4 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);

	dotProject1 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotProject2 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotProject3 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotProject4 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);

	// Add input mapping 
	inputManager->AddInputMapping("Run Right", SDLK_RIGHT);
	inputManager->AddInputMapping("Run Left", SDLK_LEFT);
	inputManager->AddInputMapping("Jump", SDLK_UP);
	inputManager->AddInputMapping("Attack", SDLK_x);
	inputManager->AddInputMapping("Run Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
	inputManager->AddInputMapping("Run Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	inputManager->AddInputMapping("Jump", SDL_CONTROLLER_BUTTON_A);
	inputManager->AddInputMapping("Attack", SDL_CONTROLLER_BUTTON_X);
	inputManager->AddInputMapping("Quit", SDLK_ESCAPE);
	inputManager->AddInputMapping("Quit", SDL_CONTROLLER_BUTTON_Y);

	//camera
	cameraPos = glm::vec2(-100.0f, 0.0f); // Posisi awal kamera
	cameraSpeed = 2.0f;

	//// Playing music
	//music = new Music("2021-08-16_-_8_Bit_Adventure_-_www.FesliyanStudios.com.ogg");
	//music->SetVolume(40);
	//music->Play(true);

	sound = new Sound("jump.wav");
	sound->SetVolume(10);

	text = new Text("lucon.ttf", 24, defaultTextShader);
	text->SetScale(1.0f);
	text->SetColor(255, 255, 255);
	text->SetPosition(0, setting->screenHeight - (text->GetFontSize() * text->GetScale()));

	//Set the background color
	SetBackgroundColor(0, 0, 0);

	// Set debug
	debug = true;

	isProjectileActive = false;
}

void ProGame::UpdateCamera() {
	vec2 monsterPos = monsterSprite->GetPosition();
	float screenWidth = setting->screenWidth;
	float screenHeight = setting->screenHeight;

	// Kamera mengikuti monster di sepanjang sumbu x dan y
	cameraPos.x = monsterPos.x - screenWidth / 2.0f + monsterSprite->GetScaleWidth() / 2.0f;
	//cameraPos.y = monsterPos.y - screenHeight / 2.0f + monsterSprite->GetScaleHeight() / 2.0f;

	// Batasi pergerakan kamera agar tidak keluar dari batas level
	float levelWidth = 2000.0f;
	//float levelHeight = 2000.0f;

	if (cameraPos.x < 0) cameraPos.x = 0;
	if (cameraPos.y < 0) cameraPos.y = 0;
	if (cameraPos.x > levelWidth - screenWidth) cameraPos.x = levelWidth - screenWidth;
	//if (cameraPos.y > levelHeight - screenHeight) cameraPos.y = levelHeight - screenHeight;
}


void ProGame::Update() {

	// If user press "Quit" key then exit
	if (inputManager->IsKeyReleased("Quit")) {
		state = State::EXIT;
		return;
	}

	text->SetText(("[FPS = " + to_string(currentFrameRate)) +
		"] Right-Left-Up-X to Move, Jump, Attack");

	monsterSprite->PlayAnim("idle");

	// Move monster sprite using keyboard and speed setting
	vec2 oldMonsterPos = monsterSprite->GetPosition();
	float x = oldMonsterPos.x, y = oldMonsterPos.y;
	if (inputManager->IsKeyPressed("Run Right")) {
		monsterSprite->PlayAnim("run");
		x += 0.55f * GetGameTime();
		monsterSprite->SetFlipHorizontal(false);
	}

	if (inputManager->IsKeyPressed("Run Left")) {
		monsterSprite->PlayAnim("run");
		x -= 0.55f * GetGameTime();
		monsterSprite->SetFlipHorizontal(true);
	}

	monsterSprite->SetPosition(x, y);
	//colide
	//pilar 
	for (Sprite* s : pillar) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	//piramid
	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platforms2) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platforms3) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platforms4) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platforms5) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	//jalur atas
	for (Sprite* s : platAtas) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platAtas2) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platAtas3) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	for (Sprite* s : platAtas4) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}
	//jalur bawah
	for (Sprite* s : ground) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}

	for (Sprite* s : ground2) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}

	for (Sprite* s : ground3) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}

	for (Sprite* s : ground4) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}

	if (inputManager->IsKeyPressed("Jump") && !jump) {
		//Set gravity and yVelocity
		float ratio = (GetGameTime() / 16.7f);
		gravity = 0.12f * ratio;
		yVelocity = 1.8f;
		jump = true;
		sound->Play(false);
	}

	if (y > 0) {
		yVelocity -= gravity;
	}
	else if (y < 0) {
		jump = false;
		yVelocity = 0;
		y = 0;
	}


	y += yVelocity * GetGameTime();
	monsterSprite->SetPosition(x, y);
	//pillar
	for (Sprite* s : pillar) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	//piramid
	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platforms2) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platforms3) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platforms4) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platforms5) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}

	//jalur atas
	for (Sprite* s : platAtas) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platAtas2) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platAtas3) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : platAtas4) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}

	//jalur bawah
	for (Sprite* s : ground) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : ground2) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : ground3) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}
	for (Sprite* s : ground4) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}

	if (inputManager->IsKeyPressed("Attack") && !isProjectileActive) {
		monsterSprite->PlayAnim("attack");
		// Aktifkan proyektil dan atur posisi awalnya
		isProjectileActive = true;
		float monsterX = monsterSprite->GetPosition().x;
		float monsterY = monsterSprite->GetPosition().y;
		projectileSprite->SetPosition(monsterX, monsterY);

	}
	vec2 oldMonsterPos2 = Chara2->GetPosition();
	BoundingBox* projectileBB = projectileSprite->GetBoundingBox();
	BoundingBox* CharaBB = Chara2->GetBoundingBox();
	if (projectileBB->CollideWith(CharaBB)) {
		// Apply knockback to monster (replace with your desired knockback calculation)
		x = oldMonsterPos2.x + 250;
		Chara2->SetPosition(x, y);

		isProjectileActive = false;
		projectileSprite->SetPosition(-100, -100);
	}

	if (isProjectileActive) {

		// Gerakkan proyektil
		float x1 = projectileSprite->GetPosition().x;
		float y1 = projectileSprite->GetPosition().y;
		float velocity = 0.5f; // Atur kecepatan proyektil

		// Tentukan arah proyektil (kiri atau kanan)
		int direction = monsterSprite->IsFlipHorizontal() ? -1 : 1;
		x1 += velocity * direction * GetGameTime();

		// Batasi pergerakan proyektil sesuai batas layar
		float maxX = setting->screenWidth - projectileSprite->GetScaleWidth();
		float minX = 0;
		if (x1 > maxX || x1 < minX) {
			isProjectileActive = false; // Nonaktifkan proyektil jika mencapai batas layar
		}
		projectileSprite->Update(GetGameTime());
		projectileSprite->SetPosition(x1, y1);
		projectileSprite->PlayAnim("Idle-1");
	}
	else {
		// Atur ulang posisi proyektil saat tidak aktif
		projectileSprite->SetPosition(-100, -100); // Atur posisi di luar layar
	}

	if (inputManager->IsKeyPressed("Attack")) {
		monsterSprite->PlayAnim("attack");
	}
	if (inputManager->IsKeyReleased("Attack")) {
		projectileSprite->PlayAnim("Idle");
	}
	// Tambahkan logika untuk reset level jika monster jatuh di bawah layar
	if (y <= 0) {
		// Reset posisi monster ke posisi awal
		monsterSprite->SetPosition(initialMonsterPos.x, initialMonsterPos.y);
		yVelocity = 0;
		jump = false;
		// Reset posisi platform ke posisi awal
		for (size_t i = 0; i < pillar.size(); i++) {
			pillar[i]->SetPosition(initialPlatformPositions[i].x, initialPlatformPositions[i].y);
		}
		for (size_t i = 0; i < platforms.size(); i++) {
			platforms[i]->SetPosition(initialPlatform2Positions[i].x, initialPlatform2Positions[i].y);
		}
		for (size_t i = 0; i < platforms2.size(); i++) {
			platforms2[i]->SetPosition(initialPlatform3Positions[i].x, initialPlatform3Positions[i].y);
		}
		for (size_t i = 0; i < platforms3.size(); i++) {
			platforms3[i]->SetPosition(initialPlatform4Positions[i].x, initialPlatform4Positions[i].y);
		}
		for (size_t i = 0; i < platforms4.size(); i++) {
			platforms4[i]->SetPosition(initialPlatform5Positions[i].x, initialPlatform5Positions[i].y);
		}
		for (size_t i = 0; i < platforms5.size(); i++) {
			platforms5[i]->SetPosition(initialPlatform6Positions[i].x, initialPlatform6Positions[i].y);
		}
		for (size_t i = 0; i < platAtas.size(); i++) {
			platAtas[i]->SetPosition(initialPlatform7Positions[i].x, initialPlatform7Positions[i].y);
		}
		for (size_t i = 0; i < platAtas2.size(); i++) {
			platAtas2[i]->SetPosition(initialPlatform8Positions[i].x, initialPlatform8Positions[i].y);
		}
		for (size_t i = 0; i < platAtas3.size(); i++) {
			platAtas3[i]->SetPosition(initialPlatform9Positions[i].x, initialPlatform9Positions[i].y);
		}
		for (size_t i = 0; i < platAtas4.size(); i++) {
			platAtas4[i]->SetPosition(initialPlatform10Positions[i].x, initialPlatform10Positions[i].y);
		}
		for (size_t i = 0; i < platAtas5.size(); i++) {
			platAtas5[i]->SetPosition(initialPlatform11Positions[i].x, initialPlatform11Positions[i].y);
		}
		for (size_t i = 0; i < ground.size(); i++) {
			ground[i]->SetPosition(initialPlatform12Positions[i].x, initialPlatform12Positions[i].y);
		}
		for (size_t i = 0; i < ground2.size(); i++) {
			ground2[i]->SetPosition(initialPlatform13Positions[i].x, initialPlatform13Positions[i].y);
		}
		for (size_t i = 0; i < ground3.size(); i++) {
			ground3[i]->SetPosition(initialPlatform14Positions[i].x, initialPlatform14Positions[i].y);
		}
		for (size_t i = 0; i < ground4.size(); i++) {
			ground4[i]->SetPosition(initialPlatform15Positions[i].x, initialPlatform15Positions[i].y);
		}
	}

	// Update monster sprite animation
	monsterSprite->Update(GetGameTime());

	// Update kamera
	UpdateCamera();

	// Pindahkan posisi semua sprite berdasarkan posisi kamera
	vec2 cameraOffset = -cameraPos;
	backgroundSprite->SetPosition(cameraOffset.x, cameraOffset.y);
	for (Sprite* s : pillar) {
		vec2 pillarPos = s->GetPosition();
		s->SetPosition(pillarPos.x + cameraOffset.x, pillarPos.y + cameraOffset.y);
	}
	for (Sprite* s : platforms) {
		vec2 platformPos = s->GetPosition();
		s->SetPosition(platformPos.x + cameraOffset.x, platformPos.y + cameraOffset.y);
	}
	for (Sprite* s : platforms2) {
		vec2 platform2Pos = s->GetPosition();
		s->SetPosition(platform2Pos.x + cameraOffset.x, platform2Pos.y + cameraOffset.y);
	}
	for (Sprite* s : platforms3) {
		vec2 platform3Pos = s->GetPosition();
		s->SetPosition(platform3Pos.x + cameraOffset.x, platform3Pos.y + cameraOffset.y);
	}
	for (Sprite* s : platforms4) {
		vec2 platform4Pos = s->GetPosition();
		s->SetPosition(platform4Pos.x + cameraOffset.x, platform4Pos.y + cameraOffset.y);
	}
	for (Sprite* s : platforms5) {
		vec2 platform5Pos = s->GetPosition();
		s->SetPosition(platform5Pos.x + cameraOffset.x, platform5Pos.y + cameraOffset.y);
	}
	for (Sprite* s : platAtas) {
		vec2 platAtasPos = s->GetPosition();
		s->SetPosition(platAtasPos.x + cameraOffset.x, platAtasPos.y + cameraOffset.y);
	}
	for (Sprite* s : platAtas2) {
		vec2 platAtas2Pos = s->GetPosition();
		s->SetPosition(platAtas2Pos.x + cameraOffset.x, platAtas2Pos.y + cameraOffset.y);
	}
	for (Sprite* s : platAtas3) {
		vec2 platAtas3Pos = s->GetPosition();
		s->SetPosition(platAtas3Pos.x + cameraOffset.x, platAtas3Pos.y + cameraOffset.y);
	}
	for (Sprite* s : platAtas4) {
		vec2 platAtas4Pos = s->GetPosition();
		s->SetPosition(platAtas4Pos.x + cameraOffset.x, platAtas4Pos.y + cameraOffset.y);
	}
	for (Sprite* s : ground) {
		vec2 groundPos = s->GetPosition();
		s->SetPosition(groundPos.x + cameraOffset.x, groundPos.y + cameraOffset.y);
	}
	for (Sprite* s : ground2) {
		vec2 ground2Pos = s->GetPosition();
		s->SetPosition(ground2Pos.x + cameraOffset.x, ground2Pos.y + cameraOffset.y);
	}
	for (Sprite* s : ground3) {
		vec2 ground3Pos = s->GetPosition();
		s->SetPosition(ground3Pos.x + cameraOffset.x, ground3Pos.y + cameraOffset.y);
	}
	for (Sprite* s : ground4) {
		vec2 ground4Pos = s->GetPosition();
		s->SetPosition(ground4Pos.x + cameraOffset.x, ground4Pos.y + cameraOffset.y);
	}
	monsterSprite->SetPosition(monsterSprite->GetPosition().x + cameraOffset.x, monsterSprite->GetPosition().y + cameraOffset.y);
	projectileSprite->SetPosition(projectileSprite->GetPosition().x + cameraOffset.x, projectileSprite->GetPosition().y + cameraOffset.y);
	Chara2->SetPosition(Chara2->GetPosition().x + cameraOffset.x, Chara2->GetPosition().y + cameraOffset.y);


	if (debug) {
		//Shape for debug
		BoundingBox* bb = Chara2->GetBoundingBox();
		dotSprite1->SetPosition(bb->GetVertices()[0].x - (0.5f * dotSprite1->GetScaleWidth()),
			bb->GetVertices()[0].y - (0.5f * dotSprite1->GetScaleHeight()));
		dotSprite2->SetPosition(bb->GetVertices()[1].x - (0.5f * dotSprite2->GetScaleWidth()),
			bb->GetVertices()[1].y - (0.5f * dotSprite2->GetScaleHeight()));
		dotSprite3->SetPosition(bb->GetVertices()[2].x - (0.5f * dotSprite3->GetScaleWidth()),
			bb->GetVertices()[2].y - (0.5f * dotSprite3->GetScaleHeight()));
		dotSprite4->SetPosition(bb->GetVertices()[3].x - (0.5f * dotSprite4->GetScaleWidth()),
			bb->GetVertices()[3].y - (0.5f * dotSprite3->GetScaleHeight()));

		BoundingBox* bb1 = projectileSprite->GetBoundingBox();
		dotProject1->SetPosition(bb1->GetVertices()[0].x - (0.5f * dotProject1->GetScaleWidth()),
			bb1->GetVertices()[0].y - (0.5f * dotProject1->GetScaleHeight()));
		dotProject2->SetPosition(bb1->GetVertices()[1].x - (0.5f * dotProject2->GetScaleWidth()),
			bb1->GetVertices()[1].y - (0.5f * dotProject2->GetScaleHeight()));
		dotProject3->SetPosition(bb1->GetVertices()[2].x - (0.5f * dotProject3->GetScaleWidth()),
			bb1->GetVertices()[2].y - (0.5f * dotProject3->GetScaleHeight()));
		dotProject4->SetPosition(bb1->GetVertices()[3].x - (0.5f * dotProject4->GetScaleWidth()),
			bb1->GetVertices()[3].y - (0.5f * dotProject3->GetScaleHeight()));

	}

}

void ProGame::Render() {

	backgroundSprite->Draw();
	text->Draw();
	for (Sprite* s : pillar) {
		s->Draw();
	}
	for (Sprite* s : platforms) {
		s->Draw();
	}
	for (Sprite* s : platforms2) {
		s->Draw();
	}
	for (Sprite* s : platforms3) {
		s->Draw();
	}
	for (Sprite* s : platforms4) {
		s->Draw();
	}
	for (Sprite* s : platforms5) {
		s->Draw();
	}
	for (Sprite* s : platAtas) {
		s->Draw();
	}
	for (Sprite* s : platAtas2) {
		s->Draw();
	}
	for (Sprite* s : platAtas3) {
		s->Draw();
	}
	for (Sprite* s : ground) {
		s->Draw();
	}
	for (Sprite* s : ground2) {
		s->Draw();
	}
	for (Sprite* s : ground3) {
		s->Draw();
	}
	for (Sprite* s : ground4) {
		s->Draw();
	}
	monsterSprite->Draw();
	projectileSprite->Draw();
	Chara2->Draw();

	if (debug) {
		dotSprite1->Draw();
		dotSprite2->Draw();
		dotSprite3->Draw();
		dotSprite4->Draw();
		dotProject1->Draw();
		dotProject2->Draw();
		dotProject3->Draw();
		dotProject4->Draw();

	}
}

int main(int argc, char** argv) {
	Setting* setting = new Setting();
	setting->windowTitle = "Platform Jump";
	setting->screenWidth = 1366;
	setting->screenHeight = 768;
	setting->windowFlag = WindowFlag::FULLSCREEN;
	setting->vsync = true;
	Game* game = new ProGame(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;
}