#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	node_t* current = kvs->db;
	char *res = "-1";
	while(current != NULL){
		if(strcmp(current->key, key)==0){
			res = current->value;
		}
		current=current->next;
	}
	return res;
}
