#include "kvs.h"
#include<dlfcn.h>

int main()
{
	FILE* qfile = fopen("query.dat", "r");
	FILE* afile = fopen("answer.dat", "w");
	if ((qfile == NULL) || (afile == NULL)){
		perror("FILE OPEN ERROR");
		return -1;
	}
	void *libHandle = dlopen("./libkvs.so", RTLD_LAZY);	
	if(!libHandle){perror("DLL FILE OPEN ERROR!"); return 1;}
	kvs_t* (*open)();
	int (*close)(kvs_t*);
	int (*set)(kvs_t*, const char*, const char*);
	char* (*get)(kvs_t*, const char*);

	open = (kvs_t*(*)())dlsym(libHandle,"open");
	close = (int(*)(kvs_t*))dlsym(libHandle,"close");
	set = (int(*)(kvs_t*, const char*, const char*))dlsym(libHandle,"set");
	get = (char*(*)(kvs_t*, const char*))dlsym(libHandle,"get");

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
