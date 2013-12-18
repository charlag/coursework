#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "sig_type.h"
#include "file_io.h"
#include "strio.h"
#include "signal.h"

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
					print_signal(stdout, in_sig, out_sig, time, u_in, u_out);
					getint();
					}
				break;
			case MANUAL:
					puts("!!!DEVELOPMENT!!!");
					puts("  ▲  ");
					puts(" ▲▲▲ ");
					puts("▲▲▲▲▲");
					getint();
					break;
			case DISPLAY:
					if (ready < 1) {
					puts("Signal is not generated");
					getint();
					break;
					}
					print_signal(stdout, in_sig, out_sig, time, u_in, u_out);
					getint();
					break;
			case PRINT:
					if (ready < 1) {
						puts("Signal is not generated");
						getint();
					} else if ( !file_print(in_sig, out_sig, time, u_in, u_out)) {
						puts("Something went wrong");
							getint();
					} else {
						puts("Succes!");
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


int menu(void) {
	int option = 0 ;
	do {	
		printf("\e[1;1H\e[2J");
		printf("\n\n\n");
		puts(" 1: Input signal parametrs from file");
		puts(" 2: Input signal parametrs manually");
		puts(" 3: Display signal");
		puts(" 4: Print signal to file");
		puts(" 7: Exit");
		printf(">");
		option = getint();
	} while ((option < 0) || (option > 7)); 
	return option;
}

