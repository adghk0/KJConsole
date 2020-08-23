#include "../KJConsole/KJConsole.h"

using namespace KJConsole;

class Test : public KJComponent {
public:
	Test() : KJComponent(10, 10, 10, 10) {
	
	}

	void printTest() {
		printContainer();
	}
};

int main() {
	KJComponent* comp = new KJComponent(10, 5, 0, 0);
	comp->setName((char*)"test");
	comp->setColor(KJConsole::ConsoleColor::Black, KJConsole::ConsoleColor::DarkCyan);

	KJLabel* label = new KJLabel(10, 2, 2, 2, (char*)"Hello Wor\nld!");
	label->setColor(KJConsole::ConsoleColor::Black, KJConsole::ConsoleColor::Gray);
	label->setLineSeperate(false);

	Test* te = new Test();
	te->add(comp);
	te->add(label);
	
	te->printTest();

	Sleep(1000);
	return 0;
}