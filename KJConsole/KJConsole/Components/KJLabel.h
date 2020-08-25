#pragma once
#include "KJComponent.h"

namespace KJConsole {
	class KJLabel : public KJComponent {
	private:
		bool lineSeperate = true;

		// void init(int width, int height, int x, int y, char* text)
		// initializing this object
		void init(char* text);
	public:
		// Constructor
		// > Parameter - none
		KJLabel();
		// Constructor
		// make the label at (0, 0) whose size is (width, 1)
		// > Parameter - the width of the lable
		KJLabel(int width);
		// Constructor
		// > Parameter - the width and height of the label at (0, 0)
		KJLabel(int width, int height);
		// Constructor
		// > Parameter - the width, height and text of the label at (0, 0)
		KJLabel(int width, int height, char* text);
		// Constructor
		// > Parameter - the width, and height of the lable at (x, y)
		KJLabel(int width, int height, int x, int y);
		// Constructor
		// > Parameter - the width, height, and text of the lable at (x, y)
		KJLabel(int width, int height, int x, int y, char* text);

		// void setLineSeperate(bool lineSeperate) 
		// > Parameter - is doing lineSeperate
		void setLineSeperate(bool lineSeperate) { this->lineSeperate = lineSeperate; }
		// bool isLineSeperate()
		// > Returns - is doing lineSeperate
		bool isLineSeperate() { return lineSeperate; }

		// void print()
		virtual void print();

		// TODO: KJLabel - 정렬 기준에 따른 출력
	};
}