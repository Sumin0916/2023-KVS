#include "kvs.h"

int set(kvs_t* kvs, const char* key, const char* value)
{
	node_t* snode = (node_t*) malloc(sizeof(node_t));
	char *vp = (char *)malloc(strlen(value)+1);
	strcpy(vp,value); vp[strlen(value)-1] = '\0';
	strcpy(snode->key,key); snode->value=vp;
	node_t* current = kvs->db;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = snode;
	return 0;
}
