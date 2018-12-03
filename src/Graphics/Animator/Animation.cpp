#pragma once

#include "Graphics/Animator/Animation.h"

Animation::Animation(std::string name, goat::Rect baseFrame, int numFrames, float frameTime) :
	name(name), baseFrame(baseFrame), numFrames(numFrames), frameTime(frameTime), currentTime(0)
{

}

float Animation::GetX()
{
	if (frameTime == 0) { return baseFrame.x; }
	int frame = (int)((currentTime) / (frameTime)) % numFrames;
	return baseFrame.x + baseFrame.w * frame;
}

float Animation::GetY()
{
	return baseFrame.y;
}

float Animation::GetW()
{
	return baseFrame.w;
}

float Animation::GetH()
{
	return baseFrame.h;
}

void Animation::addTime(float d)
{
	currentTime += d;
}

std::string Animation::getName() {
	return name;
}