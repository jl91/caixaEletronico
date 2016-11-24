#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//CONSTANTS
#define TRUE 1
#define FALSE 0

char* concat(const char *s1, const char *s2) {
	char *result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

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
	scanf("%d", &option);
	if (isValidMenuOption(option) == FALSE) {
		printInvalidOption();
		printMenu();
		chooseMenuOption(option);
	}

	return option;

}

