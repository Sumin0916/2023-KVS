#include "kvs.h"


kvs_t* open()
{
	kvs_t* kvs = (kvs_t*) malloc(sizeof(kvs_t));
	node_t* init_node = (node_t*) malloc(sizeof(node_t));
	char * vp = (char *)malloc(sizeof(100));
	init_node->next=NULL;strcpy(init_node->key,"S");init_node->value=vp;
	if(kvs != NULL)kvs->items = 0;
	kvs->db = init_node;
	return kvs;
}
