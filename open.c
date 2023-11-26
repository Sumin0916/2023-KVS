#include "kvs.h"


kvs_t* open_kvs(FILE * input_file)
{
	if(input_file == NULL){
		input_file = fopen("kvs.img", "r");
		if(input_file==NULL){perror("RECOVERY FAIL");return 1;}
	}
	kvs_t* kvs = (kvs_t*) malloc(sizeof(kvs_t));
	if(input_file == NULL){
		input_file = fopen("kvs.img", "r");
		if(input_file==NULL){perror("RECOVERY FAIL");return kvs;}
	}
	node_t* init_node = (node_t*) malloc(sizeof(node_t));
	char * vp = (char *)malloc(sizeof(100));
	init_node->next=NULL;strcpy(init_node->key,"S");strcpy(init_node->op,"S");init_node->value=vp;
	init_node->prev = init_node;
	kvs->db = init_node;
	kvs->end = init_node;
	return kvs;
}
