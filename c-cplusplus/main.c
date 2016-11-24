#include <stdio.h>
#include "functions.c"


int init(){
	printHeader();
	printMenu();
	chooseMenuOption(0);
	return 0;
}

int main (){
	init();

	return 0;
}
