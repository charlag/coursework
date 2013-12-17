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
#define QUIT_CODE 7

int menu(void);

int main() {
	IN_SIGNAL in_sig;
	OUT_SIGNAL out_sig;

	int choice = menu();

	while (choice != QUIT_CODE) {
		switch(choice) {
			case FILE_READ:
				if( file_read(&in_sig, &out_sig) < 0){
					puts("Something went wrong");
					getint();
				} else {
					puts("succes!");
					double *u_in = malloc(sizeof(double) * (in_sig.n+1));
					double *u_out = malloc(sizeof(double) * (in_sig.n+1));
					sig_gen(in_sig, out_sig, u_in, u_out);
					getint();
					}
				break;
			case MANUAL:
					puts("!!!DEVELOPMENT!!!");
					getint();
					break;
			case QUIT_CODE:
				printf("Bye\n");
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
		printf(" 1: Input signal parametrs from file\n");
		printf(" 2: Input signal parametrs manually\n");
		printf(" 7: Exit\n");
		printf(">");
		option = getint();
	} while ((option < 0) || (option > 7)); 
	return option;
}

