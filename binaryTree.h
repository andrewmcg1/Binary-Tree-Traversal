#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "binaryTree.c"

typedef struct tree node;

void newNode(node**, char[], char);
void buildTree(node**, char[], char[], int);
void newSortedNode(node**, char);
void buildSortedTree(node**, char[], int);
void freeTree(node **);

void printPreOrder(node*);
void printInOrder(node*);
void printPostOrder(node*);

void printTree(node*, char*);

#endif