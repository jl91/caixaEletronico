#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//CONSTANTS
#define TRUE 1
#define FALSE 0

char* concat(const char *s1, const char *s2) {
	char *result = malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}


void end(){
	exit(EXIT_SUCCESS);
}




