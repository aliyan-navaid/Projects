#pragma once

#include "Component.h"
#include "Object.h"

class C_Health : public Component {
public:
	C_Health(Object* owner);

	void changeHealth(int x);
	void setHealth(int x);
	int getHealth();

private:
	int health;
};

