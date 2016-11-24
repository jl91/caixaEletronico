#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* getHeader() {

	char* header = "";

	header = concat(header, "*************************************** \n");
	header = concat(header, "SEJA BEM VINDO AO ATM \n");
	header = concat(header, "*************************************** \n\n");

	return header ;
}


