#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sig_type.h"
#include "file_io.h"
#include "strio.h"
#include "signal.h"
#include "ui.h"

#define FILE_READ_PARAMS 1
#define MANUAL 2
#define DISPLAY 3
#define PRINT 4
#define GENER 5
#define FILE_READ_RESULT 6
#define MAXIMA 7
#define QUIT_CODE 8

int main() {
	IN_SIGNAL in_sig;
	OUT_SIGNAL out_sig;

	int choice = menu();
	int ready = 0;
	
	double* time = (double*) malloc(sizeof(double) * 10);
	double* u_in = (double*) malloc(sizeof(double) * 10);
	double* u_out = (double*) malloc(sizeof(double) * 10); 
	double in_durat, out_durat; //duration of signals
	while (choice != QUIT_CODE) {
		switch(choice) {
		case FILE_READ_PARAMS:
			if(file_read_params(&in_sig, &out_sig) < 9) {
				ready = 0;
				puts("Something went wrong");
				getint();
			} else {
				puts("succes!");
				ready = 1;
				getint();
			}
			break;
		case MANUAL:
			if(!manual(&in_sig, &out_sig)) {
				puts("Cannnot evalute if less then 2 points");
				ready = 0;
				getint();
				break;
			}
			puts("succes!");
			ready = 1;
			getint();
			break;
		case DISPLAY:
			if (ready < 2) {
				puts("Signal is not generated");
				getint();
				break;
			}
			print_signal(stdout, in_sig, out_sig, time, u_in, u_out,
				     in_durat, out_durat);
			getint();
			break;
		case PRINT:
			if (ready < 2) {
				puts("Signal is not generated");
				getint();
			} else if ( !file_print(in_sig, out_sig, time, u_in, u_out, in_durat, out_durat)) {
				puts("Something went wrong");
				getint();
			} else {
				puts("Success!");
				getint();
			}
			break;
		case GENER:
			if (ready < 1) {
				puts("Signal is not inserted");
				getint();
			} else {
			  time = realloc(time, sizeof(double) * (in_sig.n+1));
			  u_in = realloc(u_in, sizeof(double) * (in_sig.n+1));
			  u_out = realloc(u_out, sizeof(double) * (in_sig.n+1));
				sig_gen(in_sig, out_sig, time, u_in, u_out);
				ready = 2;
				in_durat = sig_duration(u_in, in_sig.n, in_sig.tn, in_sig.tk);
				out_durat = sig_duration(u_out, in_sig.n, in_sig.tn, in_sig.tk);	
				puts("Success!");
				getint();
			}
			break;
		case FILE_READ_RESULT:
			if (!file_read_result(&in_sig, &out_sig, &u_in, &u_out, &time, &in_durat, &out_durat)) {
				ready = 0;
				puts("Something went wrong");
				getint();	
			} else {
				puts("succes!");
				ready = 2;
				getint();
			}
			break;
		case MAXIMA:
			if(ready < 2) {
				puts("Signal is not generated");
				getint();
			} else {
				maxima(in_sig.n, time, u_in, u_out);
				puts("Generated files. Open mxm.wxm with WxMaxima");
				getint();
			}
			break;
		case QUIT_CODE:
			puts("Bye");
			break;
		}
		choice = menu();
	}
	return 0;
}



