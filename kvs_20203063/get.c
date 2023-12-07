#include "kvs.h"

char* get(kvs_t* kvs, int key)
{
	node_t* current = kvs->db->next;
	char *res = "-1";
	while(current != NULL){
		if(current->key==key){
			res = current->value;
		}
		current=current->next;
	}
	return res;
}