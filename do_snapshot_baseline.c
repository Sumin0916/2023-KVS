#include "kvs.h"


void do_snapshot(kvs_t *kvs){
	FILE *output_file = fopen("kvs.img", "w");
	if ( output_file == NULL) {
		perror ("FILE OPEN ERROR");
		return ;
	}

	node_t *current = kvs->db;
	while(current != NULL){
		fprintf(output_file, "%s,%s,%s\n", current->op, current->key, current->value);
		current = current->next;
	}
	fclose(output_file);
	return;
}
