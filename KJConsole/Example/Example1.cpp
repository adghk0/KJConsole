#include "../KJConsole/KJConsole.h"

using namespace KJConsole;

int main() {
	KJComponent* comp = new KJComponent(10, 2, 0, 0);
	comp->setName((char*)"test");
	comp->print();

	KJLabel* label = new KJLabel(10, 2, 2, 2, (char*)"Hello Worasdasda\nld!");
	label->setColor(KJConsole::ConsoleColor::Black, KJConsole::ConsoleColor::Gray);
	//label->setLineSeperate(false);
	label->print();
	return 0;
}