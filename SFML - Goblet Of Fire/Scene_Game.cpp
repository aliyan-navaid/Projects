#include "Scene_Game.h"

Scene_Game::Scene_Game(SceneStateMachine& sceneManager, ResourceAllocator<sf::Texture>& textureAllocator)
	: sceneManager(sceneManager), textureAllocator(textureAllocator) {
}

void Scene_Game::onCreate() {
	std::shared_ptr<Object> player = std::make_shared<Object>();

	auto movement = player->AddComponent<C_KeyboardMovement>();
	movement->setInput(&input);

	auto animation = player->AddComponent<C_Animation>();
	const int frameWidth = 150;
	const int frameHeight = 150;

	auto sprite = player->AddComponent<C_Sprite>();
	sprite->setTextureAllocator(&textureAllocator);
	int sumaraiTextureID = textureAllocator.Add(WorkingDirectory::get() + "Textures/Sumarai.png");


	/* IDLE Animation */
	// The character in the sprites faces right so we set that	as the initial direction.
	std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
	idleAnimation->addFrame(sumaraiTextureID, 0, 0, frameWidth, frameHeight, 0.2f);
	idleAnimation->addFrame(sumaraiTextureID, 150, 0, frameWidth, frameHeight, 0.2f);
	idleAnimation->addFrame(sumaraiTextureID, 300, 0, frameWidth, frameHeight, 0.2f);
	idleAnimation->addFrame(sumaraiTextureID, 450, 0, frameWidth, frameHeight, 0.2f);
	idleAnimation->addFrame(sumaraiTextureID, 600, 0, frameWidth, frameHeight, 0.2f);
	idleAnimation->addFrame(sumaraiTextureID, 750, 0, frameWidth, frameHeight, 0.2f);

	/* Walk Animation */
	std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);
	walkAnimation->addFrame(sumaraiTextureID, 0, 150, frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 150, 150,frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 300, 150, frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 450, 150,frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 600, 150, frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 750, 150, frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 900, 150, frameWidth, frameHeight, 0.15f);
	walkAnimation->addFrame(sumaraiTextureID, 1050, 150,frameWidth, frameHeight, 0.15f);

	animation->addAnimation(AnimationState::Idle, idleAnimation);
	animation->addAnimation(AnimationState::Walk, walkAnimation);
	objects.Add(player);
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
}

void Scene_Game::LateUpdate(float dt) {
	objects.lateUpdate(dt);
}

void Scene_Game::Draw(Window& window) {
	objects.draw(window);
}
