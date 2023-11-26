#include "kvs.h"


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void do_snapshot_base(kvs_t *kvs){
=======
void do_snapshot(kvs_t *kvs){
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
void do_snapshot(kvs_t *kvs){
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
void do_snapshot(kvs_t *kvs){
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
	FILE *output_file = fopen("kvs.img", "w");
	if ( output_file == NULL) {
		perror ("FILE OPEN ERROR");
		return ;
	}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	node_t *current = kvs->db->next;
=======
	node_t *current = kvs->db;
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
	node_t *current = kvs->db;
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
	node_t *current = kvs->db;
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
	while(current != NULL){
		fprintf(output_file, "%s,%s,%s\n", current->op, current->key, current->value);
		current = current->next;
	}
	fclose(output_file);
	return;
}
