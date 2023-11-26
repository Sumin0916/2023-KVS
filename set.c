#include "kvs.h"

int set(kvs_t* kvs, const char* op,  int key, const char* value)
{
	node_t* snode = (node_t*) malloc(sizeof(node_t));
	char *vp = (char *)malloc(strlen(value)+2);
	if(vp == NULL){perror("SET FAIL");}
	strcpy(vp,value); vp[strlen(value)-1] = '\0';
	strcpy(snode->op,op); snode->key=key; snode->value=vp;
	node_t* end_node = kvs->end;
	end_node->next = snode;
	snode->next = NULL;
	kvs->end = snode;
	return 0;
}
