#include "C_KeyboardMovement.h"
#include "Object.h"

C_KeyboardMovement::C_KeyboardMovement(Object* owner)
	: Component(owner), moveSpeed(100), input(nullptr)
{
}

void C_KeyboardMovement::awake()
{
    animation = owner->GetComponent<C_Animation>();
}

void C_KeyboardMovement::setInput(Input* input) {
	this->input = input;
}

void C_KeyboardMovement::setMovementSpeed(int moveSpeed) {
	this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::update(float dt) {
	if (input == nullptr)
		return;

	int xMove = 0;
    if (input->isKeyPressed(Input::Key::Left))
    {
        xMove = -moveSpeed;
        animation->SetAnimationDirection(FacingDirection::Left);
    }
    else if (input->isKeyPressed(Input::Key::Right))
    {
        xMove = moveSpeed;
        animation->SetAnimationDirection(FacingDirection::Right);
    }

    int yMove = 0;
    if (input->isKeyPressed(Input::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if (input->isKeyPressed(Input::Key::Down))
    {
        yMove = moveSpeed;
    }

    owner->transform->addPosition(xMove * dt, yMove * dt);

    /* Animation */
    if (xMove == 0 && yMove == 0)
    {
        animation->setAnimationState(AnimationState::Idle);
    }
    else
    {
        animation->setAnimationState(AnimationState::Walk);
    }
}
