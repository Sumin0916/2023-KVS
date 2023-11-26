#include "kvs.h"

kvs_t* do_recovery_base(kvs_t *kvs){
    FILE* rec_file = fopen("kvs.img", "r");
    if(rec_file == NULL){perror("RECOV ERROR!");}
    char line[LINE_LENGTH];
    while (fgets(line, LINE_LENGTH, rec_file) != NULL) {
		const char* operation = strtok(line, ",");
		int key = (int)atoi(strtok(NULL, ",")+5);
		const char* value = strtok(NULL, ",");
		set(kvs, operation, key, value);
		memset(line, 0, LINE_LENGTH);
	}
    fclose(rec_file);
    return kvs;
}