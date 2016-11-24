#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* getHeader() {

	char* header = "";

	header = concat(header, "*************************************** \n");
	header = concat(header, "SEJA BEM VINDO AO ATM \n");
	header = concat(header, "*************************************** \n\n");

	return header;
}

char* loadMenu() {
	char* menu = "";

	menu = concat(menu, "*************************************** \n");
	menu = concat(menu, "Menu Principal \n");
	menu = concat(menu, "*************************************** \n\n");

	menu = concat(menu, "Pressione o número para efetuar a operação \n");
	menu = concat(menu, "1 – Carregar Notas \n");
	menu = concat(menu, "2 – Retirar Notas \n");
	menu = concat(menu, "3 – Estatística \n");
	menu = concat(menu, "9 – Fim \n");

	return menu;
}

void printHeader() {
	char* header = getHeader();
	printf("%s", header);
}

void printMenu() {
	char* menu = loadMenu();
	printf("%s", menu);
}

void printInvalidOption() {
	printf("%s", "\n*************************************** \n");
	printf("%s", "OPÇÃO INVÁLDA\n");
	printf("%s", "*************************************** \n\n");
}

int isValidMenuOption(int option) {

	if (option < 0 || option > 9 || (option > 3 && option < 9)) {
		return FALSE;
	}

	return TRUE;
}

int chooseMenuOption(int option) {
	char buf[50];
	fgets(buf, sizeof buf, stdin);
	int end = 0;
	if (sscanf(buf, "%d %n", &option, &end) != 1||
	buf[end] != '\0' ||
	isValidMenuOption(option) == FALSE
	) {
		printInvalidOption();
		printMenu();
		chooseMenuOption(option);
	}

	return option;
}
