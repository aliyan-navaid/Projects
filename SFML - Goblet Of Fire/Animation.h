#pragma once

#include <vector>

struct FrameData {
	int id;
	int x;
	int y;
	int width;
	int height;
	float displayTimeSeconds;
};

enum class FacingDirection {
	None,
	Left,
	Right
};

class Animation
{
public:
	Animation(FacingDirection direction);

	void addFrame(int textureID, int x, int y,
				  int width, int height, float ft);

	const FrameData* getCurrentFrame() const;

	bool updateFrame(float dt);

	/*
		When we transition to an animation 
		e.g: from IDLE to WALK
	*/
	void reset();

	void setDirection(FacingDirection direction);
	FacingDirection getDirection() const;

private:
	void incrementFrame();

	std::vector<FrameData> frames;
	int currentFrameIndex;
	float currentFrameTime;

	FacingDirection direction;
};

