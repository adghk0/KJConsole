/*
KJComponent class
Made by Eom Kyoungjun
Copyright 2020. Eom Kyoungjun. All rights reversed.
*/
#pragma once
#include "../System/KJConsoleSystem.h"
#include "../System/ArrayList.h"

namespace KJConsole {
	// class KJComponent
	// the component class
	class KJComponent {
	private:
		// the child components
		ArrayList<KJComponent*>* components;
		KJComponent* container;

		// void clearComponenets()
		// make a new componenets arraylist
		void clearComponenets();

		// void init(int width, int height, int x, int y)
		// initializing this object
		void init(int width, int height, int x, int y);

		// void setContainer(KJComponent* container)
		// set the container.
		// > Parameter - the container
		void setContainer(KJComponent* container);

	protected:
		// the width of the component
		int width;
		// the height of the component
		int height;
		// the x position of the component
		int x;
		// the y position of the component
		int y;
		// the color of the component
		char colorset;
		// the component's name
		char* name;
		// the value of visible
		bool visible;

		// void printContainer()
		// print all components
		void printContainer();

		// void setColorSet(char set)
		// > Parameter - the color set (background 4bit, foreground 4bit)
		void setColorSet(char set);

	public:
		// Constructor
		KJComponent();
		// Constructor
		// > Parameter - the component which is same from the new component
		KJComponent(KJComponent* component);
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
		int getColor();
		// void setName(char* name)
		// > Parameter - the name of the component
		void setName(char* name);
		// char* getName()
		// > Returns - the name of the component
		char* getName();
		// void setVisible(bool visible)
		// > Parameter - the visible of the component
		void setVisible(bool visible);
		// bool isVisible();
		// > Returns - is the visible component
		bool isVisible();

		// int getWidth()
		// > Returns - the width of the component
		int getWidth();
		// int getHeight()
		// > Returns - the height of the component
		int getHeight();
		// int getX()
		// > Returns - the x-position of the component
		int getX();
		// int getY()
		// > Returns - the y-position of the component
		int getY();
		// int getOriginX()
		// get origin x-position
		// > Returns - origin x-position
		int getOriginX();
		// int getOriginY()
		// get origin y-position
		// > Returns - origin y-position
		int getOriginY();
		// int getContainerWidth()
		// > Returns - container's width
		int getContainerWidth();
		// int getContainerHeight()
		// > Returns - container's height
		int getContainerHeight();
		// KJComponent* getContainer()
		// get the container which has this component
		// > Returns - the container
		KJComponent* getContainer();

		// void setWidth(int width)
		// > Parameter - the new width of the component
		void setWidth(int width);
		// void setHeight(int height)
		// > Parameter - the new height of the component
		void setHeight(int height);
		// void setX(int x)
		// > Parameter - the new x-position of the component
		void setX(int x);
		// void setY(int y)
		// > Parameter - the new y-position of the component
		void setY(int y);

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

		// bool add(KJComponent* component)
		// add a componenet at the last position.
		// > Parameter - a adding component
		// > Returns - the success or failure of the adding
		bool add(KJComponent* component);
		// bool add(KJComponent* component, int index)
		// add a componenet at the index.
		// > Parameter - component: a adding component, index: the index 
		// > Returns - the success or failure of the adding
		bool add(KJComponent* component, int index);
		// KJComponent* get(int index)
		// get a component at the index
		// > Parameter - the index
		// > Returns - a component at the index
		KJComponent* get(int index);
		// bool del(int index)
		// delete a component at the index
		// > Parameter - the index
		// > Returns - the success or failure of the deleting 
		bool del(int index);
		// bool del(KJComponent* component)
		// delete a component which is same from the component
		// > Parameter - the component
		// > Returns - the success or failure of the deleting 
		bool del(KJComponent* component);

		// int length()
		// > Returns - the number of component
		int length();

		// void print()
		// print this component.
		virtual void print();
	};
}
