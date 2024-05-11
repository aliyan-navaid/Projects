#pragma once

#include "Component.h"
#include "C_Animation.h"
#include "Input.h"

class C_KeyboardMovement : public Component {
public:
	C_KeyboardMovement(Object* owner);
	
	void awake() override;

	void setInput(Input* input);
	void setMovementSpeed(int moveSpeed);

	void update(float dt) override;

private:
	Input* input;
	int moveSpeed;

	std::shared_ptr<C_Animation> animation;
};