#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sig_type.h"
#include "file_io.h"
#include "strio.h"
#include "signal.h"
#include "ui.h"

#define FILE_READ 1
#define MANUAL 2
#define DISPLAY 3
#define PRINT 4
#define QUIT_CODE 7

int menu(void);

int main() {
	IN_SIGNAL in_sig;
	OUT_SIGNAL out_sig;

	int choice = menu();
	int ready = 0;
	
	double* time;
	double* u_in;
	double* u_out;
	double in_durat, out_durat;

	while (choice != QUIT_CODE) {
		switch(choice) {
			case FILE_READ:
				if( !file_read(&in_sig, &out_sig) ){
					puts("Something went wrong");
					getint();
				} else {
					puts("succes!");
					time = malloc(sizeof(double) * (in_sig.n+1));
					u_in = malloc(sizeof(double) * (in_sig.n+1));
					u_out = malloc(sizeof(double) * (in_sig.n+1));
					sig_gen(in_sig, out_sig, time, u_in, u_out);
					ready = 1;
					in_durat = sig_duration(u_in, in_sig.n, in_sig.tn, in_sig.tk);
				        out_durat = sig_duration(u_out, in_sig.n, in_sig.tn, in_sig.tk);	
					print_signal(stdout, in_sig, out_sig, time, u_in, u_out,
							in_durat, out_durat);
					getint();
					}
				break;
			case MANUAL:
					if(!manual(&in_sig, &out_sig)) {
						puts("Cannnot evalute if less then 2 points");
						ready = 0;
						break;
					}
					puts("succes!");
					time = malloc(sizeof(double) * (in_sig.n+1));
					u_in = malloc(sizeof(double) * (in_sig.n+1));
					u_out = malloc(sizeof(double) * (in_sig.n+1));
					sig_gen(in_sig, out_sig, time, u_in, u_out);
					ready = 1;
					in_durat = sig_duration(u_in, in_sig.n, in_sig.tn, in_sig.tk);
				        out_durat = sig_duration(u_out, in_sig.n, in_sig.tn, in_sig.tk);	
					print_signal(stdout, in_sig, out_sig, time, u_in, u_out,
							in_durat, out_durat);
					getint();
					break;
			case DISPLAY:
					if (ready < 1) {
					puts("Signal is not generated");
					getint();
					break;
					}
					print_signal(stdout, in_sig, out_sig, time, u_in, u_out,
							in_durat, out_durat);
					getint();
					break;
			case PRINT:
					if (ready < 1) {
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

			case QUIT_CODE:
				puts("Bye");
				break;
		}
		choice = menu();
	}
	return 0;
}



