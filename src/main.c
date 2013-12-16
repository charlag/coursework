#include <stdio.h>
#include <memory.h>
#include "sig_sype.h"

#define QUIT_CODE 7

int menu(void);

int main() {

	int choice = menu();

	while (choice != QUIT_CODE) {
		switch(choice) {
			case 1:
				printf("Заглушка\n");
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
		printf("1: Input signal parametrs from file\n");
		printf("7: Exit\n");
		printf(">");
		fflush(stdin);
		scanf("%d", &option);
	} while ((option < 0) || (option > 7)); 
	return option;
}
