#include "kvs.h"

int main()
{
	FILE* qfile = fopen("cluster004.trc", "r");
	FILE* afile = fopen("answer.dat", "w");
	if (afile == NULL){
		perror("FILE OPEN ERROR");
		return -1;
	}	
	kvs_t* kvs = open_kvs(qfile);
	kvs_t* mem_kvs = open_kvs(qfile);
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
			set(kvs, operation, key, value);
		}
		set(mem_kvs, operation, key, value);
		memset(line, 0, LINE_LENGTH);
	}
	do_snapshot_custom(mem_kvs);
	close_kvs(kvs);
	close_kvs(mem_kvs);
	fclose(qfile);
	fclose(afile);
	return 0;
}
