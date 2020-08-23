/*
KJComponent class
Made by Eom Kyoungjun
Copyright 2020. Eom Kyoungjun. All rights reversed.
*/
#pragma once
#include "../System/KJConsoleSystem.h"

namespace KJConsole {
	class KJComponent {
	protected:
		int width, height, x, y;
		char colorset;
		char* name;

		// 배경, 전경색 설정
		void setColorSet(char set);

	public:
		// Constructor
		KJComponent();
		// Constructor
		// > Parameter - name: the name of the component
		KJComponent(char* name);
		// Constructor
		// > Parameter - the width and height of the component
		KJComponent(int width, int height);
		// Constructor
		// > Parameter - the width, height, x-position and y-position of the component
		KJComponent(int width, int height, int x, int y);

		// void setColor(int color, int background)
		// > Parameter - the color and background color of the component
		void setColor(int color, int background);
		// void getColor()
		// > Returns - the color and background color of the component by a char (background 4bit, foreground 4bit)
		int getColor() { return colorset; }
		// void setName(char* name)
		// > Parameter - the name of component
		void setName(char* name);
		// char* getName()
		// > Returns - the name of component
		char* getName();

		// int getWidth()
		// > Returns - the width of the component
		int getWidth() { return width; }
		// int getHeight()
		// > Returns - the height of the component
		int getHeight() { return height; }
		// int getX()
		// > Returns - the x-position of the component
		int getX() { return x; }
		// int getY()
		// > Returns - the y-position of the component
		int getY() { return y; }

		// void setWidth(int width)
		// > Parameter - the new width of the component
		void setWidth(int width) { this->width = width; };
		// void setHeight(int height)
		// > Parameter - the new height of the component
		void setHeight(int height) { this->height = height; };
		// void setX(int x)
		// > Parameter - the new x-position of the component
		void setX(int x) { this->x = x; };
		// void setY(int y)
		// > Parameter - the new y-position of the component
		void setY(int y) { this->y = y; };

		// void setSize(int width, int height)
		// set the width and height of the component.
		// > Parameter - the width and height of the component
		void setSize(int width, int height);
		// void setPosition(int x, int y)
		// set the x-position and y-position of the component.
		// > Parameter - the x-position and y-position of the component
		void setPosition(int x, int y);
		// void setBounds(int width, int height, int x, int y)
		// set the width, height, x-position and y-position of the component.
		// > Parameter - the width, height, x-position and y-position of the component
		void setBounds(int width, int height, int x, int y);

		// void print()
		// print this component.
		void print();
	};
}
