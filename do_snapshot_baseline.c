#include "kvs.h"
#define BUFF_SIZE 1024


void do_snapshot(FILE *input_file){
	FILE *output_file = fopen("kvs.img", "w");

	if (input_file == NULL || output_file == NULL) {
		perror("FILE OPEN ERROR");
		return ;
	}
	char *BUFFER = (char *)malloc(BUFF_SIZE);
	char buff_format[50]; snprintf(buff_format, 50, "%%%d[^\n]\n", BUFF_SIZE);
	while(1){
		BUFFER = fscanf(input_file, buff_format, BUFFER);	
		if(BUFFER == EOF) break;
		fprintf(output_file, "%s\n", BUFFER);
	}

	free(BUFFER);	
	fclose(input_file);
	fclose(output_file);
	return;
}
