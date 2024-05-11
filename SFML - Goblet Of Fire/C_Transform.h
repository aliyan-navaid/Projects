#pragma once

#include "Component.h"

class C_Transform : public Component {
public:
	C_Transform(Object* owner);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);

	void addPosition(float x, float y);
	void addPosition(sf::Vector2f pos);

	void setX(float x);
	void setY(float y);

	void addX(float x);
	void addY(float y);

	const sf::Vector2f& getPosition() const;

private:
	sf::Vector2f position;
};

