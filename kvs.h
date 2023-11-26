#include<stdio.h>
#include<string.h>
#include<stdlib.h>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define LINE_LENGTH 4500

struct node {
	char op[5];
	char key[150];
=======
#define LINE_LENGTH 201

struct node {
=======
#define LINE_LENGTH 201

struct node {
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
#define LINE_LENGTH 201

struct node {
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
	char op[50];
	char key[100];
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
	char *value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	int items; // number of data 
};
typedef struct kvs kvs_t; 


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
kvs_t* open_kvs(FILE *input_file);
int close_kvs(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char *op, const char* key,const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return -1  if not found. 
void do_snapshot_base(kvs_t *kvs);
void do_snapshot_custom(kvs_t *kvs);
=======
=======
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
kvs_t* open(FILE *input_file);
int close(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char *op, const char* key,const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return -1  if not found. 
void do_snapshot(kvs_t *kvs);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
=======
>>>>>>> 90acfc6a7dfb4d76ef7c91ff66ca4ffdcd01d225
