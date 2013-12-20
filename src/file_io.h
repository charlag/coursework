#ifndef FILE_IO_H
#include "sig_type.h"
#define FILE_IO_H
FILE* open_file(char mode);
int file_read_head(FILE* file, IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig);
int file_read_table(FILE* file, int n, double* time,
		double* u_in, double* u_out, double* in_dur,
	       	double *out_dir);
int file_print(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig,
		const double* time, const double* u_in,
		const double* u_out, double in_durat, double out_durat);
#endif
