#pragma once

#include "Scene.h"
#include "WorkingDirectory.h"
#include "Input.h"
#include "SceneStateMachine.h"
#include "Object.h"
#include "C_Sprite.h"
#include "ObjectCollection.h"
#include "ResourceAllocator.h"
#include "C_KeyboardMovement.h"
#include "C_Health.h"
#include "C_Animation.h"


class Scene_Game : public Scene {
public:
	Scene_Game(SceneStateMachine&, ResourceAllocator<sf::Texture>&);

	void onCreate();
	void onDestroy();

	virtual void ProcessInput();
	virtual void Update(float);
	virtual void LateUpdate(float) override;
	virtual void Draw(Window&);

private:
	Input input;
	SceneStateMachine& sceneManager;
	ObjectCollection objects;
	ResourceAllocator<sf::Texture>& textureAllocator;

	sf::Texture backgroundTexture;
	sf::Texture foregroundTexture;
	sf::Sprite backgroundSprite;
	sf::Sprite foregroundSprite;
};
