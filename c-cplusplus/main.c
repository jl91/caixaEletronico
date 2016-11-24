#include <stdio.h>
#include "functions.c"
#include "menus.c"
#include "money.c"

#define LOAD_ATM_WITH_MONEY  1
#define DRAW_SOME_MONEY  2
#define STATISTICS 3
#define END 9

int option = 0;

void chooseProcess(int option) {
	switch (option) {

	case LOAD_ATM_WITH_MONEY:
		loadATMWithMoney();
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
	printMenu();
	option = chooseMenuOption(option);
	chooseProcess(option);

	return 0;
}
