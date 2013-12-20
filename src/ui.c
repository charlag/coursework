#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "sig_type.h"
#include "strio.h"
					
int menu(void) {
	int option = 0 ;
	do {	
		printf("\e[1;1H\e[2J");
		printf("\n\n\n");
		puts(" 1: Input signal parametrs from file");
		puts(" 2: Insert signal parametrs manually");
		puts(" 3: Display signal");
		puts(" 4: Print signal to file");
		puts(" 5: Generate signal");
		puts(" 6: Exit");
		printf(">");
		option = getint();
	} while ((option < 0) || (option > 7)); 
	return option;
}

int manual(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig) {
	puts("Not inserted values will be set to 0");
	puts("Insert u:");
	in_sig->u = getdouble();
	puts("Insert tn:");
	in_sig->tn = getdouble();
	puts("Insert t1:"); 
	in_sig->tm = getdouble();
	puts("Insert tk:"); 
	in_sig->tk = getdouble();
	puts("Insert a:");
	in_sig->a = getdouble();
       	puts("Insert b:");	
	in_sig->b = getdouble();
	puts("Insert muber of point to calcute, > 1");
	in_sig->n = getint();
	puts("Insert u1:");
	out_sig->u1 = getdouble();
	puts("Insert u2:");
	out_sig->u2 = getdouble();
	
	if (in_sig->n <= 1) {
		return 0;
	}
	return 1;
}	
