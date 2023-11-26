#include "kvs.h"


<<<<<<< HEAD
<<<<<<< HEAD
kvs_t* open_kvs(FILE * input_file)
=======
kvs_t* open(FILE * input_file)
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
kvs_t* open(FILE * input_file)
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
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
	if(kvs != NULL)kvs->items = 0;
	kvs->db = init_node;
	return kvs;
}
