#include "kvs.h"

kvs_t* open_kvs(FILE * input_file){
	kvs_t* kvs = (kvs_t*) malloc(sizeof(kvs_t));
	node_t* init_node = (node_t*) malloc(sizeof(node_t));
	char * vp = (char *)malloc(sizeof(100));
	init_node->next=NULL;init_node->key=0;strcpy(init_node->op,"S");init_node->value=vp;
	kvs->db = init_node;
	kvs->end = init_node;
	if(input_file == NULL){
		//kvs = do_recovery_base(kvs);
		kvs = do_recovery_custom(kvs);
	}
	return kvs;
}
