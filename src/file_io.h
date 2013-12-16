#ifndef FILE_IO_H
#include "sig_type.h"
#define FILE_IO_H
FILE* open_file(char mode);
int file_read(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig);
#endif
