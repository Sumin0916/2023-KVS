#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINE_LENGTH 4320

struct node {
	char op[5];
	int key;
	char *value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	struct node* end;
};
typedef struct kvs kvs_t; 

kvs_t* open_kvs(void);
int close_kvs(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char *op, int key,const char* value); // return -1 if failed.
char* get(kvs_t* kvs, int key); // return -1  if not found. 