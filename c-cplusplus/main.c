#include <stdio.h>
#include "functions.c"


int main (){
	char* header = getHeader();

	printf("%s", header);

	return 0;
}
