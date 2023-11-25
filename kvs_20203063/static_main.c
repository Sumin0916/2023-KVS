#include "kvs.h"

int main()
{
	FILE* qfile = fopen("query.dat", "r");
	FILE* afile = fopen("answer.dat", "w");
	if ((qfile == NULL) || (afile == NULL)){
		perror("FILE OPEN ERROR");
		return -1;
	}
	
	kvs_t* kvs = open();
	char line[LINE_LENGTH];
	while (fgets(line, LINE_LENGTH, qfile) != NULL) {
		const char* operation = strtok(line, ",");
		const char* key= strtok(NULL, ",");
		const char* value = strtok(NULL, ",");

		if(strcmp(operation, "get") == 0){
			char *res = get(kvs, key);
			fprintf(afile, "%s\n",res);
		}
		else {
			set(kvs, key, value);
		}
		memset(line, 0, LINE_LENGTH);
	}
	close(kvs);
	fclose(qfile);
	fclose(afile);
	return 0;
}
