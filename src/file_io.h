#ifndef FILE_IO_H
#include "sig_type.h"
#define FILE_IO_H
FILE* open_file(char mode);

int file_read_params(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig);
int file_read_result(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig, double **u_in, double **u_out, double **time, double *in_durat, double* out_durat);

int file_print(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig,
		const double* time, const double* u_in,
		const double* u_out, double in_durat, double out_durat);
#endif
