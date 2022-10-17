# Binary-Tree-Traversal
Header and source fils of tree traversal functions and a main file with an example
The main function takes the in order and pre order traversals and uses those to return the post order traversal

## Functions

### void newNode(node** tree, char inOrder[], char newData)
  Adds a node to a binary tree, in any given order. It appends newData into the tree depending on the inOrder string given

### void buildTree(node** tree, char inOrder[], char preOrder[], int length)
  Calls newNode function for the length of the input strings, it sorts a string into a binary tree based off of the preOrdered print and the Inorder print. From there any other printing method can be used on the tree

### void newSortedNode(node** tree, char newData)
  Adds a new node to a binary tree so that the tree remains sorted

### void buildSortedTree(node** tree, char inString[], int StringLength)
  Builds a binary tree from a string so that the tree will be sorted

### void freeTree(node** tree)
  Frees a tree from the root node

### void printTree(node* tree, char* type)
  prints a given tree with either the pre-order, in-order or post-order method or the reverse versions. Valid types of print are "pre", "in", "post", "rev_pre", "rev_in", "rev_post"
