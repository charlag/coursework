#ifndef FILE_IO_H
#include "sig_type.h"
#define FILE_IO_H
FILE* open_file(char mode);
int file_read(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig);
int file_print(const IN_SIGNAL in_sig, const OUT_SIGNAL out_sig, const double* time, const double* u_in, const double* u_out);
#endif
