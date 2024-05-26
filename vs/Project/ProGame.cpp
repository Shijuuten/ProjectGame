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
	Texture* platformTexture = new Texture("platform.png");
	vec2 start = vec2(300, 33);
	for (int i = 0; i < 8; i++) {
		Sprite* platformSprite = new Sprite(platformTexture, defaultSpriteShader, defaultQuad);
		platformSprite->SetPosition(start.x + i * 210, start.y + i * 90);
		platformSprite->SetSize(150, 32);
		platformSprite->SetBoundingBoxSize(platformSprite->GetScaleWidth() - (16 * platformSprite->GetScale()), platformSprite->GetScaleHeight());
		platforms.push_back(platformSprite);
	}

	Texture* groundTexture = new Texture("TilesAtas.png");
	vec2 mulai = vec2(3, 1);
	for (int i = 0; i < 25; i++) {
		Sprite* groundSprite = new Sprite(groundTexture, defaultSpriteShader, defaultQuad);
		groundSprite->SetPosition(mulai.x + i * 150,1);
		groundSprite->SetSize(150, 32);
		groundSprite->SetBoundingBoxSize(groundSprite->GetScaleWidth() - (16 * groundSprite->GetScale()), groundSprite->GetScaleHeight());
		ground.push_back(groundSprite);
	}
	
	Texture* ground2Texture = new Texture("TilesAtas.png");
	vec2 mulai2 = vec2(3900, 1);
	for (int i = 0; i < 8; i++) {
		Sprite* ground2Sprite = new Sprite(ground2Texture, defaultSpriteShader, defaultQuad);
		ground2Sprite->SetPosition(mulai2.x + i * 150, mulai2.y);
		ground2Sprite->SetSize(150, 32);
		ground2Sprite->SetBoundingBoxSize(ground2Sprite->GetScaleWidth() - (16 * ground2Sprite->GetScale()), ground2Sprite->GetScaleHeight());
		ground2.push_back(ground2Sprite);
	}

	Texture* ground3Texture = new Texture("TilesAtas.png");
	vec2 mulai3 = vec2(5250, 1);
	for (int i = 0; i < 15; i++) {
		Sprite* ground3Sprite = new Sprite(ground3Texture, defaultSpriteShader, defaultQuad);
		ground3Sprite->SetPosition(mulai3.x + i * 150, mulai3.y);
		ground3Sprite->SetSize(150, 32);
		ground3Sprite->SetBoundingBoxSize(ground3Sprite->GetScaleWidth() - (16 * ground3Sprite->GetScale()), ground3Sprite->GetScaleHeight());
		ground3.push_back(ground3Sprite);
	}




	//Create background
	Texture* bgTexture = new Texture("bg.png");
	backgroundSprite = new Sprite(bgTexture, defaultSpriteShader, defaultQuad);
	backgroundSprite->SetSize(setting->screenWidth, setting->screenHeight);

	
	Texture* monsterTexture = new Texture("monster.png");
	monsterSprite = new Sprite(monsterTexture, defaultSpriteShader, defaultQuad);
	monsterSprite->SetPosition(0, 34);
	monsterSprite->SetNumXFrames(6);
	monsterSprite->SetNumYFrames(3);
	monsterSprite->SetAnimationDuration(70);
	monsterSprite->SetScale(2.0f);
	monsterSprite->AddAnimation("attack", 13, 14);
	monsterSprite->AddAnimation("idle", 0, 3);
	monsterSprite->AddAnimation("run", 6, 11);
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
	sound->SetVolume(100);

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
	cameraPos.y = monsterPos.y - screenHeight / 2.0f + monsterSprite->GetScaleHeight() / 2.0f;

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

	// Move monster sprite using keyboard
	vec2 oldMonsterPos = monsterSprite->GetPosition();
	float x = oldMonsterPos.x, y = oldMonsterPos.y;
	if (inputManager->IsKeyPressed("Run Right")) {
		monsterSprite->PlayAnim("run");
		x += 0.2f * GetGameTime();
		monsterSprite->SetFlipHorizontal(false);
	}

	if (inputManager->IsKeyPressed("Run Left")) {
		monsterSprite->PlayAnim("run");
		x -= 0.2f * GetGameTime();
		monsterSprite->SetFlipHorizontal(true);
	}

	monsterSprite->SetPosition(x, y);
	//colide
	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}

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

	if (inputManager->IsKeyPressed("Jump") && !jump) {
		//Set gravity and yVelocity
		float ratio = (GetGameTime() / 16.7f);
		gravity = 0.16f * ratio;
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


	// Update monster sprite animation
	monsterSprite->Update(GetGameTime());

	// Update kamera
	UpdateCamera();

	// Pindahkan posisi semua sprite berdasarkan posisi kamera
	vec2 cameraOffset = -cameraPos;
	backgroundSprite->SetPosition(cameraOffset.x, cameraOffset.y);
	for (Sprite* s : platforms) {
		vec2 platformPos = s->GetPosition();
		s->SetPosition(platformPos.x + cameraOffset.x, platformPos.y + cameraOffset.y);
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
	for (Sprite* s : platforms) {
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