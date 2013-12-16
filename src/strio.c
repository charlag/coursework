#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "strio.h"

/*!!!After using both readline() and getstring() memory has to be free()'d!!!*/

char* readline() {
	size_t nbytes = 2;
	char* line = (char *) malloc(nbytes + 1);
	getline(&line, &nbytes, stdin);
	if (line[nbytes - 1] == '\n') {
		(line[nbytes - 1] = '\0');
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
	char* newline = malloc(sizeof(rawline));
	sscanf(rawline, "%s", newline);
	free(rawline);
	return newline;
}
