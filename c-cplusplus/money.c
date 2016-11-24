#include <stdio.h>

int twoReaisNotes = 0;
int fiveReaisNotes = 0;
int tenReaisNotes = 0;
int twentyReaisNotes = 0;
int fiftyReaisNotes = 0;
int oneHundredReaisNotes = 0;
int limit = 0;

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
	printf("-- %s %d,00 %s ","Total carregado: R$ ", limit, "\n");
	printf("%s", " \n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  \n");
}

void generateNotes() {
	twoReaisNotes = rand() % (100 + 1 - 1) - 1;
	fiveReaisNotes = rand() % (100 + 1 - 1) - 1;
	tenReaisNotes = rand() % (80 + 1 - 1) - 1;
	twentyReaisNotes = rand() % (60 + 1 - 1) - 1;
	fiftyReaisNotes = rand() % (40 + 1 - 1) - 1;
	oneHundredReaisNotes = rand() % (20 + 1 - 1) - 1;

	limit = twoReaisNotes * 2
			+ fiveReaisNotes * 5
			+ tenReaisNotes * 10
			+ twentyReaisNotes * 20
			+ fiftyReaisNotes * 50
			+ oneHundredReaisNotes * 100;

}

void loadATMWithMoney() {
	printLoadingATMMoneyMessage();
	generateNotes();
	printLoadedATMMoneyMessage();
}

void drawSomeMoney() {
	printf("%s", "drawSomeMoney");
}

void statistics() {
	printf("%s", "statistics");
}
