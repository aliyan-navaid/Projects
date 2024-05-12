#include "C_Health.h"

C_Health::C_Health(Object* owner)
	: Component(owner), health(100)
{
}

void C_Health::changeHealth(int x)
{
	health += x;
}

void C_Health::setHealth(int x)
{
	health = x;
}

int C_Health::getHealth()
{
	return health;
}






