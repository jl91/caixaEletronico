#include <stdio.h>
#include "functions.c"
#include "menus.c"
#include "money.c"

#define LOAD_ATM_WITH_MONEY  1
#define DRAW_SOME_MONEY  2
#define STATISTICS 3
#define END 9

int option = 0;
//Defining functions Prototype
void goBackToOptions();
void chooseProcess(int option);

//Implementations
void goBackToOptions() {
	printMenu();
	option = chooseMenuOption(option);
	chooseProcess(option);
}

void chooseProcess(int option) {
	switch (option) {

	case LOAD_ATM_WITH_MONEY:
		loadATMWithMoney();
		goBackToOptions();
		break;

	case DRAW_SOME_MONEY:
		drawSomeMoney();
		break;

	case STATISTICS:
		statistics();
		break;

	case END:
		end();
		break;
	}
}


int main() {
	printHeader();
	goBackToOptions();

	return 0;
}
