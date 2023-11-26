#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LINE_LENGTH 4500

struct node {
	char op[5];
	char key[150];
	char *value;
	struct node* next;
	struct node* prev;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	struct node* end;
};
typedef struct kvs kvs_t; 

kvs_t* open_kvs(FILE *input_file);
int close_kvs(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char *op, const char* key,const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return -1  if not found. 
void do_snapshot_base(kvs_t *kvs);
void do_snapshot_custom(kvs_t *kvs);
