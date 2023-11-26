#include "kvs.h"

int main()
{
	FILE* qfile = fopen("cluster004.trc", "r");
	FILE* afile = fopen("answer.dat", "w");
	if (afile == NULL){
		perror("FILE OPEN ERROR");
		return -1;
	}	
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	kvs_t* kvs = open_kvs(qfile);
	kvs_t* mem_kvs = open_kvs(qfile);
=======
	kvs_t* kvs = open(qfile);
	kvs_t* mem_kvs = open(qfile);
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
	kvs_t* kvs = open(qfile);
	kvs_t* mem_kvs = open(qfile);
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
	kvs_t* kvs = open(qfile);
	kvs_t* mem_kvs = open(qfile);
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	do_snapshot_custom(mem_kvs);
	close_kvs(kvs);
	close_kvs(mem_kvs);
=======
	do_snapshot(mem_kvs);
	close(kvs);
	close(mem_kvs);
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
	do_snapshot(mem_kvs);
	close(kvs);
	close(mem_kvs);
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
	do_snapshot(mem_kvs);
	close(kvs);
	close(mem_kvs);
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
	fclose(qfile);
	fclose(afile);
	return 0;
}
