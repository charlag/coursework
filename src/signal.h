#ifndef SIGNAL_H
#define SIGNAL_H
#include "sig_type.h"
void sig_gen(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig, double *time,  double *u_in, double *u_out);

void print_signal(FILE* stream, const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig,
		const double* time, const double* u_in, const double* u_out); 
#endif
