#include "kvs.h"
#define BUFF_SIZE 10000


void do_snapshot(FILE *input_file){
	FILE *output_file = fopen("kvs.img", "w");

	if (input_file == NULL || output_file == NULL) {
		perror ("FILE OPEN ERROR");
		return ;
	}
	char *BUFFER = (char *)malloc(BUFF_SIZE);
	while(fscanf(input_file, "%s", BUFFER) != EOF){
		fprintf(output_file, "%s", BUFFER);
	}
	free(BUFFER);	
	fclose(output_file);
	return;
}
