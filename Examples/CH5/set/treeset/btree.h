#ifndef __BTREE_H_INC
#define __BTREE_H_INC

/*
  say that a leaf is a node with both children as NULL
*/
typedef struct node {
  void *data;
  node *left;
  node *right;
} node;

/*
  same idea as the set interface
*/

node *node_new(void);
void node_free(node *n);

/*
  Free this node, and recusrively free all of its child nodes.
*/
void btree_free(node *n);

void btree_add(node *n, void *elem);
void btree_remove(node *n, void *elem);
int btree_contains(node *n, void *elem);

#endif
