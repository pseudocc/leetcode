#ifndef LC_TEST_H
#define LC_TEST_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list_node* list_t;
typedef struct llist_node* llist_t;
typedef struct tree_node* tree_t;

struct list_node {
  int val;
  struct list_node *next;
};

struct llist_node {
  int val;
  struct llist_node *prev;
  struct llist_node *next;
};

struct tree_node {
  int val;
  struct tree_node *left;
  struct tree_node *right;
};

list_t read_list();
void free_list(list_t);
void print_list(list_t);

llist_t read_llist();
void free_llist(llist_t);
void print_llist(llist_t);

tree_t read_tree();
void free_tree(tree_t);
void print_tree(tree_t);

int read_int();
int* read_arr(int*);
void print_arr(int*, int);

int run_test(void);

#endif
