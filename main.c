#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"

int main()
{
    char latest;
    int lengthInOrder = 0;
    int lengthPreOrder = 0;
    node *root;
    root = NULL;

    char *preOrder;
    char *inOrder;

    // Read in pre-order traversal from the command line
    printf("Input the pre-order traversal: ");

    preOrder = (char *)malloc(sizeof(char));

    scanf("%c", &latest);
    while (latest != '\n')
    {
        preOrder[lengthPreOrder] = latest;
        preOrder = realloc(preOrder, (++lengthPreOrder + 1) * sizeof(char));
        scanf("%c", &latest);
    }

    // Read in in-order traversal from the command line
    printf("Input the in-order traversal: ");

    inOrder = (char *)malloc(sizeof(char));

    scanf("%c", &latest);
    while (latest != '\n')
    {
        inOrder[lengthInOrder] = latest;
        inOrder = realloc(inOrder, (++lengthInOrder + 1) * sizeof(char));
        scanf("%c", &latest);
    }

    // checks if inOrder and preOrder have the same characters
    for (int i = 0; i < lengthInOrder; i++)
    {
        int j;
        for (j = 0; j < lengthPreOrder; j++)
        {
            if (inOrder[i] == preOrder[j])
                break;
        }
        if (j == lengthPreOrder)
        {
            free(inOrder);
            free(preOrder);

            printf("\nInvalid Inputs\n\n");
            return -1;
        }
    }
    for (int i = 0; i < lengthPreOrder; i++)
    {
        int j;
        for (j = 0; j < lengthInOrder; j++)
        {
            if (preOrder[i] == inOrder[j])
                break;
        }
        if (j == lengthInOrder)
        {
            free(inOrder);
            free(preOrder);

            printf("\nInvalid Inputs\n\n");
            return -1;
        }
    }

    // Build the binary tree
    buildTree(&root, inOrder, preOrder, lengthInOrder);

    // Build the binary tree
    printf("The post-order traversal is: ");

    // Output the post-order of the binary tree
    printTree(root, "post");

    printf("\n");

    // Free used memory
    freeTree(&root);
    free(inOrder);
    free(preOrder);

    return 0;
}