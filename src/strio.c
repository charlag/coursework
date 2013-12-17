#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strio.h"

/*!!! After using both readline() and getstring() memory has to be free()'d !!!*/

char* readline() {
	size_t nbytes = 2;
	char* line = NULL;
	ssize_t read = getline(&line, &nbytes, stdin);
	if (line[read - 1] == '\n') {
		line[read - 1] = '\0';
	}
	return line;
}

int getint() {
	int num;
	char* line = readline();
	sscanf(line, "%d", &num);
	free(line);
	return num;
}

char* getstring() {
	char* rawline = readline();
	//even if it's cyrrilic - we need real number of bytes.
	char* newline = malloc(strlen(rawline) + 1);  
	sscanf(rawline, "%s", newline);
	if(rawline) {
		free(rawline);
	}
	return newline;
}
