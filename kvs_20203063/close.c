#include "kvs.h"

int close_kvs(kvs_t* kvs)
{
	node_t* current = kvs->db;
	node_t* next;

	while(current != NULL) {
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	free(kvs);
	return 0;
}