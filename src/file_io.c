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

int file_read_head(FILE* file, IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig) {
	fscanf(file, "%*s %*s"); // "Parametrs are:"
	fscanf(file, "%*s %*s %*s"); //For input signal:
	int result = 0;
	result += fscanf(file, "%*s %lf %*s %*s %lf %*s %*s %lf %*s %*s %lf %*s %*s  %lf %*s %*s %lf %*s\n", &in_sig->u, &in_sig->tn, &in_sig->tm, &in_sig->tk,
			&in_sig->a, &in_sig->b);
	fscanf(file, "%*s %*s %*s"); //"For output signal"
	result += fscanf(file, "%*s %lf %*s %*s %lf %*s", &out_sig->u1, &out_sig->u2);
	result += fscanf(file, "%*s %d %*s", &in_sig->n);
	return result;
}


int file_read_table(FILE* file, int n, double* time, double* u_in, double*u_out, double* in_durat, double* out_durat) {
	fscanf(file, "%*s %*s %*s %*s");
	double t, uin, uout;
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += fscanf(file, " %*d %lf %lf %lf", &t, &uin, &uout);
		time[i] = t;
		u_in[i] = uin;
		u_out[i] = uout;
	}
	result += fscanf(file, "%*s %*s %*s %*s %*s %*s %lf %*s %*s %lf", in_durat, out_durat);
	fclose(file);
	return result;
}

int file_print(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig, const double* time,
	      	const double* u_in, const double* u_out, double in_durat, double out_durat) {
	FILE* file = open_file('w');

	if (file == NULL) {
		return 0;
	}
	print_signal(file, in_sig, out_sig, time, u_in, u_out,
			in_durat, out_durat);
	fclose(file);
	return 1;
}
