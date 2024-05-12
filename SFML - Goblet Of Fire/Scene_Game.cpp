#include "Scene_Game.h"

Scene_Game::Scene_Game(SceneStateMachine& sceneManager, ResourceAllocator<sf::Texture>& textureAllocator)
	: sceneManager(sceneManager), textureAllocator(textureAllocator) {
}

void Scene_Game::onCreate() {
	/* Map */
	backgroundTexture.loadFromFile(WorkingDirectory::get() + "Textures/map-background.png");
	backgroundSprite.setTexture(backgroundTexture);
	foregroundTexture.loadFromFile(WorkingDirectory::get() + "Textures/map-foreground.png");
	foregroundSprite.setTexture(foregroundTexture);

	/* Player 1*/
	std::shared_ptr<Object> player = std::make_shared<Object>();

	auto health = player->AddComponent<C_Health>();

	std::shared_ptr<Object> player2 = std::make_shared<Object>();
	auto movement = player->AddComponent<C_KeyboardMovement>();
	movement->setReciever(player2.get());
	movement->setInput(&input);

	auto sprite = player->AddComponent<C_Sprite>();
	sprite->setTextureAllocator(&textureAllocator);
	int sumaraiTextureID = textureAllocator.Add(WorkingDirectory::get() + "Textures/SumaraiClean.png");

	auto animation = player->AddComponent<C_Animation>();
	const int frameWidth = 150;
	const int frameHeight = 150;
	
	// IDLE Animation
	std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
	for (int i = 0; i <= 5; i++) {
		idleAnimation->addFrame(sumaraiTextureID, i*frameWidth, 0*frameHeight, frameWidth, frameHeight, 0.2f);
	}
	
	// Walk Animation
	std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);
	for (int i = 0; i <= 7; i++) {
		walkAnimation->addFrame(sumaraiTextureID, i*frameWidth, 1*frameHeight,frameWidth, frameHeight, 0.15f);
	}

	// Jump Animation
	std::shared_ptr<Animation> jumpAnimation = std::make_shared<Animation>(FacingDirection::Right);
	for (int i = 0; i <= 11; i++) {
		jumpAnimation->addFrame(sumaraiTextureID, i * frameWidth, 2 * frameHeight, frameWidth, frameHeight, 0.11f);
	}

	// Attack Animation
	std::shared_ptr<Animation> attackAnimation = std::make_shared<Animation>(FacingDirection::Right);
	for (int i = 0; i <= 5; i++) {
		attackAnimation->addFrame(sumaraiTextureID, i * frameWidth, 3 * frameHeight, frameWidth, frameHeight, 0.1f);
	}
	
	animation->addAnimation(AnimationState::Idle, idleAnimation);
	animation->addAnimation(AnimationState::Walk, walkAnimation);
	animation->addAnimation(AnimationState::Jump, jumpAnimation);
	animation->addAnimation(AnimationState::Attack, attackAnimation);

	// Must spawn at ground (y=438.53f)
	player->GetComponent<C_Transform>()->setPosition(100.0f, 438.529f);
	
	objects.Add(player);

	/***********
		Player 2
	************/
	auto health2 = player2->AddComponent<C_Health>();

	//auto movement = player->AddComponent<C_KeyboardMovement>();
	//movement->setInput(&input);

	auto sprite2 = player2->AddComponent<C_Sprite>();
	sprite2->setTextureAllocator(&textureAllocator);
	int sumaraiTextureID2 = textureAllocator.Add(WorkingDirectory::get() + "Textures/SumaraiClean.png");

	auto animation2 = player2->AddComponent<C_Animation>();
	
	// IDLE Animation
	std::shared_ptr<Animation> idleAnimation2 = std::make_shared<Animation>(FacingDirection::Right);
	for (int i = 0; i <= 5; i++) {
		idleAnimation2->addFrame(sumaraiTextureID2, i * frameWidth, 0 * frameHeight, frameWidth, frameHeight, 0.2f);
	}

	animation2->addAnimation(AnimationState::Idle, idleAnimation2);
	
	// Must spawn at ground (y=438.53f)
	player2->GetComponent<C_Transform>()->setPosition(300.0f, 438.529f);

	objects.Add(player2);
}

void Scene_Game::onDestroy()
{
}

void Scene_Game::ProcessInput() {
	input.update();
}

void Scene_Game::Update(float dt) {
	objects.processNewObjects();
	objects.update(dt);

	if (objects.get(0)->GetComponent<C_Health>()->getHealth() <= 0
		|| objects.get(1)->GetComponent<C_Health>()->getHealth() <= 0) {
		sceneManager.switchTo(0);
	}
}

void Scene_Game::LateUpdate(float dt) {
	objects.lateUpdate(dt);
}

void Scene_Game::Draw(Window& window) {
	window.draw(backgroundSprite);
	objects.draw(window);
	window.draw(foregroundSprite);
}
