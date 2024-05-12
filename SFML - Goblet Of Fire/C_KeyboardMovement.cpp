#include "C_KeyboardMovement.h"
#include "Object.h"

C_KeyboardMovement::C_KeyboardMovement(Object* owner)
	: Component(owner), moveSpeed(100), input(nullptr), gravity(10.0f), xMove(0), yMove(0)
{
}

void C_KeyboardMovement::awake()
{
    animation = owner->GetComponent<C_Animation>();
}

void C_KeyboardMovement::setInput(Input* input) {
	this->input = input;
}

void C_KeyboardMovement::setReciever(Object* reciever)
{
    this->reciever = reciever;
}

void C_KeyboardMovement::setMovementSpeed(int moveSpeed) {
	this->moveSpeed = moveSpeed;
}

void C_KeyboardMovement::update(float dt) {
	if (input == nullptr)
		return;
    
    xMove = 0;
    yMove += gravity;

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

    if (input->isKeyPressed(Input::Key::Up))
    {
        // if on ground
        if (owner->transform->getPosition().y >= 436.529) {
            yMove = -300.0f;
        }
    }

    if (input->isKeyDown(Input::Key::F)) {
        isAttacking = true;
        if (abs(reciever->GetComponent<C_Transform>()->getPosition().x - owner->GetComponent<C_Transform>()->getPosition().x) <= 50)
        {
            std::cout << reciever->GetComponent<C_Health>()->getHealth() << " ";
            reciever->GetComponent<C_Health>()->changeHealth(-10);
        }
    }

    owner->transform->addPosition(xMove * dt, yMove*dt);

    if (owner->transform->getPosition().y >= 438.529) {
        owner->transform->setY(438.529);
        yMove = 0;
    }

    /* Animation */
    if (xMove == 0  && yMove==0 && !isAttacking)
    {
        animation->setAnimationState(AnimationState::Idle);
    }
    else if (yMove != 0)
    {
        animation->setAnimationState(AnimationState::Jump);
    }
    else if (xMove!=0)
    {
        animation->setAnimationState(AnimationState::Walk);
    }
    else if (isAttacking) {
        animation->setAnimationState(AnimationState::Attack);
    }
}
