#pragma once

#include "Component.h"
#include "C_Animation.h"
#include "Input.h"
#include "C_Health.h"
#include "cmath"
#include "iostream"

class C_KeyboardMovement : public Component {
public:
	C_KeyboardMovement(Object* owner);
	
	void awake() override;

	void setInput(Input* input);
	void setReciever(Object* reciever);
	void setMovementSpeed(int moveSpeed);

	void update(float dt) override;

private:
	Input* input;
	int moveSpeed;
	float gravity;

	Object* reciever;

	int yMove;
	int xMove;

	bool isAttacking;

	std::shared_ptr<C_Animation> animation;
};