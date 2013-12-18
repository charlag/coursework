#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include "sig_type.h"
#include "strio.h"
#include "signal.h"

FILE* open_file(char mode) {
	printf("Insert filename:\n");
	char* filename = getstring();

	FILE* file;
	switch (mode) {
		case 'r':
			file = fopen(filename, "r");
			break;
		case 'w':
			file = fopen(filename, "w+");
			break;
		default:
			puts("Wrong use of the open_file function");
			file = fopen(filename, "r+");
	}
	if (filename) {
		free(filename);
	}
	if (file == NULL) {
		puts("Error reading file");
	}
	return file;
}

int file_read(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig) {
	FILE* file = open_file('r');

	if (file == NULL) {
		return 0;
	}
	
	int result = fscanf(file, "%lf %lf %lf %lf %lf %lf %d"
			"%lf %lf", &in_sig->u, &in_sig->tn, &in_sig->tm, &in_sig->tk,
			&in_sig->a, &in_sig->b, &in_sig->n, &out_sig->u1, &out_sig->u2);
	if (result < 9) {
		puts("Wrong file");
		return 0;
	}
	return 1;
}

int file_print(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig, const double* time, const double* u_in, const double* u_out) {
	FILE* file = open_file('w');

	if (file == NULL) {
		return 0;
	}
	print_signal(file, in_sig, out_sig, time, u_in, u_out);
	return 1;
}
