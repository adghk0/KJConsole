#include "KJComponent.h"

void KJConsole::KJComponent::setColorSet(char set)
{
	this->colorset = set;
}

KJConsole::KJComponent::KJComponent()
{
	KJComponent(0, 0, 0, 0);
}

KJConsole::KJComponent::KJComponent(char* name)
{
	KJComponent(0, 0, 0, 0);
	this->name = name;
}

KJConsole::KJComponent::KJComponent(int width, int height)
{
	KJComponent(width, height, 0, 0);
}

KJConsole::KJComponent::KJComponent(int width, int height, int x, int y)
{
	// 값 지정
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->name = nullptr;

	// 색상 지정 (back: Black, fore: White)
	setColorSet(0x0f);
}

void KJConsole::KJComponent::setColor(int color, int background)
{
	setColorSet((color & 0x0f) | ((background & 0x0f) << 4));
}

void KJConsole::KJComponent::setName(char* name)
{
	this->name = name;
}

char* KJConsole::KJComponent::getName()
{
	return this->name;
}

void KJConsole::KJComponent::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void KJConsole::KJComponent::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void KJConsole::KJComponent::setBounds(int width, int height, int x, int y)
{
	setSize(width, height);
	setPosition(x, y);
}

void KJConsole::KJComponent::print()
{
	Console::setConsolePosition(x, y);
	Console::setConsoleColorSet(colorset);
	Console::printLine(name);
}
