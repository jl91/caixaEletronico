#include <stdio.h>

//Defining functions Prototype
void printLoadingATMMoneyMessage();
void printLoadedATMMoneyMessage();
void generateNotes();
void loadATMWithMoney();
void drawSomeMoney();
void statistics();
void printDrawMoneyMessage();
int isValidValueToDrawMoney(int value);
int isValidBank(int bank);
void chooseBestOptionToDrawMoney(int value);
char * getBankName(int bankCode);

//CONSTANTS
#define BANK_BANCO_DO_BRASIL 1
#define BANK_SANTANDER 2
#define BANK_ITAU 3
#define BANK_CAIXA 4

//Implementations
int twoReaisNotes = 0;
int fiveReaisNotes = 0;
int tenReaisNotes = 0;
int twentyReaisNotes = 0;
int fiftyReaisNotes = 0;
int oneHundredReaisNotes = 0;
int limit = 0;

int currentValue = 0;
int currentBank = 0;

void printLoadingATMMoneyMessage() {
	printf("%s", " \n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n");
	printf("%s", " \n Carregando ATM com notas\n");
	printf("%s", " \n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  \n");
}

void printLoadedATMMoneyMessage() {
	printf("%s", " \n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n");
	printf("%s", " \n ATM CARREGADA COM \n ");
	printf("- %d notas de %s ", twoReaisNotes, ": R$ 2,00 \n");
	printf("- %d notas de %s ", fiveReaisNotes, ": R$ 5,00 \n");
	printf("- %d notas de %s ", tenReaisNotes, ": R$ 10,00 \n");
	printf("- %d notas de %s ", twentyReaisNotes, ": R$ 20,00 \n");
	printf("- %d notas de %s ", fiftyReaisNotes, ": R$ 50,00 \n");
	printf("- %d notas de %s ", oneHundredReaisNotes, ": R$ 100,00 \n");
	printf("-- %s %d,00 %s ", "Total carregado: R$ ", limit, "\n");
	printf("%s", "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  \n");
}

void generateNotes() {
	twoReaisNotes = rand() % (100 + 1 - 1) - 1;
	fiveReaisNotes = rand() % (100 + 1 - 1) - 1;
	tenReaisNotes = rand() % (80 + 1 - 1) - 1;
	twentyReaisNotes = rand() % (60 + 1 - 1) - 1;
	fiftyReaisNotes = rand() % (40 + 1 - 1) - 1;
	oneHundredReaisNotes = rand() % (20 + 1 - 1) - 1;

	limit = twoReaisNotes * 2 + fiveReaisNotes * 5 + tenReaisNotes * 10
			+ twentyReaisNotes * 20 + fiftyReaisNotes * 50
			+ oneHundredReaisNotes * 100;

}

void loadATMWithMoney() {
	printLoadingATMMoneyMessage();
	generateNotes();
	printLoadedATMMoneyMessage();
}

void printDrawMoneyMessage() {
	printf("%s", "\n$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$");
	printf("%s", "\n$-$ $ Saque Solicitado -$-$-$-$-$-$-$-$-$-$-$");
	printf("%s", "\n$-$ $ Digite o valor que deseja sacar -$-$-$-");
	printf("\n$-$ $ Limite Disponível: R$ %d,00 -$-$-$-$-", limit);
	printf("%s", "\n$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$\n\n");
}

int isValidValueToDrawMoney(int value) {

	if (value < 1) {
		printf("Valor %d Inválido!", value);
		return FALSE;
	}

	if (value > limit) {
		printf("Valor %d EXCEDEU O LIMITE DO CAIXA", value);
		return FALSE;
	}

	return TRUE;
}

int isValidBank(int bank) {

	if (bank < BANK_BANCO_DO_BRASIL || bank > BANK_CAIXA) {
		printf("Banco %d Inválido!", bank);
		return FALSE;
	}

	return TRUE;
}

void chooseBestOptionToDrawMoney(int value) {

	int currentValue = value;

	while (currentValue > 0) {

		if (currentValue >= 100 && oneHundredReaisNotes > 0) {
			oneHundredReaisNotes--;
			currentValue -= 100;
			limit -= 100;
			continue;
		}

		if (currentValue >= 50 && fiftyReaisNotes > 0) {
			fiftyReaisNotes--;
			currentValue -= 50;
			limit -= 50;
			continue;
		}

		if (currentValue >= 20 && twentyReaisNotes > 0) {
			twentyReaisNotes--;
			currentValue -= 20;
			limit -= 20;
			continue;
		}

		if (currentValue >= 10 && tenReaisNotes > 0) {
			tenReaisNotes--;
			currentValue -= 10;
			limit -= 10;
			continue;
		}

		if (currentValue >= 5 && fiveReaisNotes > 0) {
			fiveReaisNotes--;
			currentValue -= 5;
			limit -= 5;
			continue;
		}

		if (currentValue >= 2 && twoReaisNotes > 0) {
			twoReaisNotes--;
			currentValue -= 2;
			limit -= 2;
			continue;
		}
	}
}

char * getBankName(int bankCode) {
	switch (bankCode) {

	case BANK_BANCO_DO_BRASIL:
		return "Banco do Brasil";

	case BANK_SANTANDER:
		return "SANTANDER";

	case BANK_ITAU:
		return "ITAU";

	case BANK_CAIXA:
		return "CAIXA";

	default:
		return "Banco não encontrado";
	}
}

void drawSomeMoney() {
	printDrawMoneyMessage();

	char buf[50];
	fgets(buf, sizeof buf, stdin);
	int end = 0;
	if (sscanf(buf, "%d %n", &currentValue, &end) != 1 || buf[end] != '\0'
			|| isValidValueToDrawMoney(currentValue) == FALSE) {
		drawSomeMoney();
	}

	if (sscanf(buf, "%d %n", &currentBank, &end) != 1 || buf[end] != '\0'
			|| isValidBank(currentBank) == FALSE) {
		drawSomeMoney();
	}

	chooseBestOptionToDrawMoney(currentValue);

}

void statistics() {
	printf("%s", "statistics");
}
