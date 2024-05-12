#include "Input.h"

bool Input::isKeyPressed(Key keycode) {
	return currentFrameKeys.getBit((int)keycode);
}

bool Input::isKeyDown(Key keycode) {
	bool lastFrame = previousFrameKeys.getBit((int)keycode);
	bool currentFrame = currentFrameKeys.getBit((int)keycode);

	/* If key pressed thisFrame but not in lastFrame */
	return currentFrame && !lastFrame;
}

bool Input::isKeyUp(Key keycode) {
	bool lastFrame = previousFrameKeys.getBit((int)keycode);
	bool currentFrame = currentFrameKeys.getBit((int)keycode);

	/* If key pressed lastFrame but not in currentFrame */
	return !currentFrame && lastFrame;
}

sf::Vector2i Input::getMouseBox(Window& window)
{
	return sf::Mouse::getPosition(window.getWindow());
}

void Input::update() {
	previousFrameKeys.setBitMask(currentFrameKeys);

	currentFrameKeys.setBit( 
		(int) Key::Left,
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A) 
	);

	currentFrameKeys.setBit(
		(int) Key::Right,
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D)
	);

	currentFrameKeys.setBit(
		(int) Key::Up,
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)
	);

	currentFrameKeys.setBit(
		(int) Key::Down,
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::S)
	);

	currentFrameKeys.setBit(
		(int) Key::ESC,
		sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
	);

	currentFrameKeys.setBit(
		(int)Key::MouseLeft,
		sf::Mouse::isButtonPressed(sf::Mouse::Left)
	);
	currentFrameKeys.setBit(
		(int)Key::F,
		sf::Keyboard::isKeyPressed(sf::Keyboard::F)
	);
}
