#include "C_JUMP.h"

C_JUMP::C_JUMP(Object* owner)
	: Component(owner), velocity(0.0f,0.0f)
{}

void C_JUMP::awake()
{
	transform = owner->GetComponent<C_Transform>();
}

void C_JUMP::jump()
{
	// If on ground
	if (transform->getPosition().y - 438 <= 0.1)
		velocity.y = -20;
}

const sf::Vector2f& C_JUMP::getVelocity()
{
	return velocity;
}



