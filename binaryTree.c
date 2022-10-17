#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"

typedef struct tree
{
    char data;
    int count;

    struct tree *left;
    struct tree *right;
} node;

void newNode(node **tree, char inOrder[], char newData)
{
    int treeIndex = 0;
    int inIndex = 0;
    node *Node;
    if (!*tree)
    {
        // allocates new node
        Node = (node *)malloc(sizeof(node));

        // initialize node
        Node->data = newData;
        Node->count = 1;
        Node->left = NULL;
        Node->right = NULL;

        *tree = Node;
        return;
    }

    // find the index of inOrder that is equal to the node data
    while (inOrder[treeIndex] != (*tree)->data)
    {
        treeIndex++;
    }
    // find the index of inOrder that is equal to input char
    while (inOrder[inIndex] != newData)
    {
        inIndex++;
    }

    // compare the index of the char in prOrder and inOrder
    if (inIndex < treeIndex)
    {
        newNode(&((*tree)->left), inOrder, newData);
    }
    else if (inIndex > treeIndex)
    {
        newNode(&((*tree)->right), inOrder, newData);
    }
    else if (inIndex == treeIndex)
    {
        (*tree)->count++;
    }
}

void buildTree(node **tree, char inOrder[], char preOrder[], int length)
{
    for (int i = 0; i < length; i++)
    {
        newNode(tree, inOrder, preOrder[i]);
    }
}

// adds a new node to a tree so that the tree remains sorted
void newSortedNode(node **tree, char newData)
{
    node *Node;
    if (!*tree)
    {
        // allocates node
        Node = (node *)malloc(sizeof(node));

        // initialize node
        Node->data = newData;
        Node->count = 1;
        Node->left = NULL;
        Node->right = NULL;

        *tree = Node;
        return;
    }

    // if newData is less than the data in the node, go left
    if (newData < (*tree)->data)
    {
        newSortedNode(&((*tree)->left), newData);
    }
    // if newData is greater than the data in the node, go right
    else if (newData > (*tree)->data)
    {
        newSortedNode(&((*tree)->right), newData);
    }
    // prints the data in the node count times
    else if (newData == (*tree)->data)
    {
        (*tree)->count++;
    }
}

// builds a sorted binary tree from an input string
void buildSortedTree(node **tree, char in[], int length)
{
    for (int i = 0; i < length; i++)
    {
        newSortedNode(tree, in[i]);
    }
}

// frees allocated tree
void freeTree(node **tree)
{
    // free left node
    if ((*tree)->left)
    {
        freeTree(&((*tree)->left));
    }
    // free right node
    if ((*tree)->right)
    {
        freeTree(&((*tree)->right));
    }
    // free node
    free(*tree);
    *tree = NULL;
}

// function to print tree in any order
void printTree(node *tree, char *type)
{
    // return if tree is empty
    if (!tree)
        return;

    int print, left, right;
    char *order[] = {"pre", "in", "post",
                     "rev_pre", "rev_in", "rev_post"};

    // check for valid type input
    int k = 0;
    while (k < 6 && type != order[k])
    {
        k++;
    }
    // error for invalid input
    if (k == 6)
    {
        printf("\n\ninvalid arguements: printTree(node*, char*)\n\n");
        return;
    }
    // sets correct print order for the input type
    int i;
    for (i = 0; i < 6; i++)
    {
        print = i % 3;
        if (type == order[i] && i % 3 == 0)
        {
            left = 1;
            right = 2;
            break;
        }
        else if (type == order[i] && i % 3 == 1)
        {
            left = 0;
            right = 2;
            break;
        }
        else if (type == order[i] && i % 3 == 2)
        {
            left = 0;
            right = 1;
            break;
        }
    }
    // reverses order if type calls for it
    if (i > 2)
    {
        int temp;
        temp = left;
        left = right;
        right = temp;
    }

    // prints in the correct order
    for (int j = 0; j < 3; j++)
    {
        if (j == print)
        {
            for (int i = 0; i < tree->count; i++)
            {
                printf("%c", tree->data);
            }
        }

        if (j == left && tree->left)
        {
            printTree(tree->left, type);
        }

        if (j == right && tree->right)
        {
            printTree(tree->right, type);
        }
    }
}
