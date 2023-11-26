#include "kvs.h"
#include <unistd.h>
#include <fcntl.h>

kvs_t* do_recovery_custom(kvs_t *kvs){
    int rec_file = open("kvs.img", O_RDONLY);
    if(rec_file == -1){perror("RECOV ERROR!");}
    char line[LINE_LENGTH];
    while (read(rec_file, line, LINE_LENGTH) > 0) {
		const char* operation = strtok(line, ",");
		int key = (int)atoi(strtok(NULL, ",")+5);
		const char* value = strtok(NULL, ",");
		set(kvs, operation, key, value);
		memset(line, 0, LINE_LENGTH);
	}
	close(rec_file);
    return kvs;
}