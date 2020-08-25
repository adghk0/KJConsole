#include "KJComponent.h"

void KJConsole::KJComponent::clearComponenets()
{
	components = new ArrayList<KJComponent*>();
}

void KJConsole::KJComponent::init(int width, int height, int x, int y)
{
	// 값 지정
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->name = nullptr;
	this->visible = true;
	this->container = nullptr;
	clearComponenets();

	// 색상 지정 (back: Black, fore: White)
	setColorSet(0x0f);
}

void KJConsole::KJComponent::setContainer(KJComponent* container)
{
	this->container = container;
}

void KJConsole::KJComponent::printContainer()
{
	this->print();
	for (int i = 0; i < length(); i++)
		this->components->get(i)->print();
}

void KJConsole::KJComponent::setColorSet(char set)
{
	this->colorset = set;
}

KJConsole::KJComponent::KJComponent()
{
	init(0, 0, 0, 0);
}

KJConsole::KJComponent::KJComponent(KJComponent* component)
{
	init(component->width, component->height, component->x, component->y);
	this->colorset = component->colorset;
	this->name = new char[sizeof(component->name)];
	strcpy_s(name, sizeof(name), component->name);
}

KJConsole::KJComponent::KJComponent(char* name)
{
	init(0, 0, 0, 0);
	this->name = name;
}

KJConsole::KJComponent::KJComponent(int width, int height)
{
	init(width, height, 0, 0);
}

KJConsole::KJComponent::KJComponent(int width, int height, int x, int y)
{
	init(width, height, x, y);
}

void KJConsole::KJComponent::setColor(int color, int background)
{
	setColorSet((color & 0x0f) | ((background & 0x0f) << 4));
}

int KJConsole::KJComponent::getColor()
{
	return colorset;
}

void KJConsole::KJComponent::setName(char* name)
{
	this->name = name;
}

char* KJConsole::KJComponent::getName()
{
	return this->name;
}

void KJConsole::KJComponent::setVisible(bool visible)
{
	this->visible = visible;
}

bool KJConsole::KJComponent::isVisible()
{
	return visible;
}

int KJConsole::KJComponent::getWidth()
{
	return width;
}

int KJConsole::KJComponent::getHeight()
{
	return height;
}

int KJConsole::KJComponent::getX()
{
	return x;
}

int KJConsole::KJComponent::getY()
{
	return y;
}
int KJConsole::KJComponent::getOriginX()
{
	if (container != nullptr)
		return container->getOriginX() + container->getX();
	else return 0;
}

int KJConsole::KJComponent::getOriginY()
{
	if (container != nullptr)
		return container->getOriginY() + container->getY();
	return 0;
}

int KJConsole::KJComponent::getContainerWidth()
{
	if (container == nullptr)
		return -1;
	return container->getWidth();
}


int KJConsole::KJComponent::getContainerHeight()
{
	if (container == nullptr)
		return -1;
	return container->getHeight();
}

KJConsole::KJComponent* KJConsole::KJComponent::getContainer()
{
	return container;
}

void KJConsole::KJComponent::setWidth(int width)
{
	this->width = width;
}

void KJConsole::KJComponent::setHeight(int height)
{
	this->height = height;
}

void KJConsole::KJComponent::setX(int x)
{
	this->x = x;
}

void KJConsole::KJComponent::setY(int y)
{
	this->y = y;
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

bool KJConsole::KJComponent::add(KJComponent* component)
{
	component->setContainer(this);
	return this->components->add(component);
}

bool KJConsole::KJComponent::add(KJComponent* component, int index)
{
	component->setContainer(this);
	return this->components->add(component, index);
}

KJConsole::KJComponent* KJConsole::KJComponent::get(int index)
{
	return components->get(index);
}

bool KJConsole::KJComponent::del(int index)
{
	components->get(index)->setContainer(nullptr);
	return components->del(index);
}

bool KJConsole::KJComponent::del(KJComponent* component)
{
	for (int i = 0; i < components->size(); i++)
		if (components->get(i) == component) {
			components->get(i)->setContainer(nullptr);
			return components->del(i);
		}
	return false;
}

int KJConsole::KJComponent::length()
{
	return components->size();
}

void KJConsole::KJComponent::print()
{
	int ox = getOriginX(), oy = getOriginY();
	char* buffer = new char[width + 1];
	Console::setConsoleColorSet(colorset);
	
	for (int i = 0; i < width; i++)
		buffer[i] = ' ';
	buffer[width] = 0;

	for (int i = 0; i < height; i++) {
		Console::setConsolePosition(ox + x, oy + y + i);
		Console::printLine(buffer);
	}
}
