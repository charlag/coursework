#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include "sig_type.h"
#include "strio.h"

FILE* open_file(char mode) {
	printf("Insert filename:\n");
	char* filename = getstring();
	//REMOVE
	printf("filelename: %s\n", filename);

	FILE* file;
	switch (mode) {
		case 'r':
			file = fopen(filename, "r");
			break;
		case 'w':
			file = fopen(filename, "w+");
		default:
			puts("Wrong use of the open_file function");
			file = fopen(filename, "r+");
	}
	free(filename);

	if (file == NULL) {
		puts("Error reading file");
	}
	return file;
}

int file_read(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig) {
	FILE* file = open_file('r');

	if (file == NULL) {
		return -1;
	}
	
	int result = fscanf(file, "%lf %lf %lf %lf %lf %lf %d"
			"%lf %lf", &in_sig->u, &in_sig->tn, &in_sig->tm, &in_sig->tk,
			&in_sig->a, &in_sig->b, &in_sig->n, &out_sig->point, &out_sig->mult);
	if (result < 9) {
		puts("Wrong file");
		return -1;
	}
	//REMOVE
	printf("%lf %lf %lf %lf %lf %lf %d, %lf %lf\n", in_sig->u, in_sig->tn, in_sig->tm, in_sig->tk, in_sig->a, in_sig->b, in_sig->n, out_sig->point, out_sig->mult);
	return 0;
}
