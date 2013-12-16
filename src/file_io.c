#include <stdlib.h>
#include <stdio.h>

FILE* open_file(char mode) {
	int bytes_read;
	size_t  nbytes = 10;
	char *filename = (char *) malloc (nbytes + 1);
	printf("Insert filename:\n");
	fflush(stdin);
	bytes_read = getline (&my_string, &nbytes, stdin);
	if (bytes_read <= 0) {
		puts("Error reading filename\n");
		return NULL;
	}
	
	if (getline[nbytes - 1] == '\n') {
		(getline[nbytes - 1] = '\0');
	}

	FILE* file = NULL;
	
	case mode {
		switch 'r':
			file = fopen(filename, "r");
			break;
		switch 'w':
			file = fopen(filename, "w+");
	}

	if (filename == NULL) {
		puts("Error reading file\n");
	}
	return file;
}

int file_read(IN_SIGNAL *in_sig, OUT_SIGNAL *out_sig) {
	FILE* file = open_file('r');

	if (file == NULL) {
		return -1;
	}
	
	int result = fscanf(file, "%lf %lf %lf %lf %lf %lf %d"
			"%lf %lf", in_sig->u, in_sig->tn, in_sig->tm, in_sig->tk,
			in_sig->a, in_sig->b, in_sig->n, out_sig->point, out_sig->mult);
	if (result < 9) {
		puts("Wrong file\n");
		return -1;
	}

}
