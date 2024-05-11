#include "Animation.h"

Animation::Animation(FacingDirection direction)
	: frames(0), currentFrameIndex(0), currentFrameTime(0.0f), direction(direction)
{
}

void Animation::addFrame(int textureID, int x, int y, int width, int height, float ft) {
	FrameData frame{ textureID, x, y, width, height, ft };
	frames.push_back(frame);
}

const FrameData* Animation::getCurrentFrame() const
{
	if (frames.size() > 0) {
		return &frames[currentFrameIndex];
	}
	return nullptr;
}

bool Animation::updateFrame(float dt)
{
	if (frames.size() <= 0) { return false; }

	currentFrameTime += dt;
	if (currentFrameTime >= frames[currentFrameIndex].displayTimeSeconds) {
		currentFrameTime = 0;
		incrementFrame();
		return true;
	}
	return false;
}

void Animation::reset()
{
	currentFrameIndex = 0;
	currentFrameTime = 0;
}

void Animation::setDirection(FacingDirection direction)
{
	// Makes sure we do not flip the sprite 
	// unless its a new direction.
	if (this->direction != direction)
	{
		this->direction = direction;
		for (auto& f : frames)
		{
			// Move Origin to top-right then flip
			f.x += f.width;
			f.width *= -1;
		}
	}
}

FacingDirection Animation::getDirection() const
{
	return direction;
}

void Animation::incrementFrame()
{
	currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}
