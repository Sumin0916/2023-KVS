#include "kvs.h"
#include <unistd.h>
#include <fcntl.h>

void do_snapshot_custom(kvs_t *kvs){
	int output_file = open("kvs.img", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if ( output_file == -1) {
		perror ("FILE OPEN ERROR");
		return ;
	}

	node_t *current = kvs->db->next;
	while(current != NULL){
		char BUFFER[LINE_LENGTH+5];
		int length = snprintf(BUFFER, LINE_LENGTH+5, "%s,%s,%s\n", current->op, current->key, current->value);
		if(write(output_file, BUFFER, length) == -1){
			perror("RECOV WRITE ERROR");
			return;
		}
		current = current->next;
	}
	close(output_file);
	return;
}
