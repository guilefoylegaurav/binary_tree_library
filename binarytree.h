#ifndef CODE201_TREE_H
#define CODE201_TREE_H
#include <stdio.h>

//Defining a tree node
typedef struct TreeNodeType
{
    int                 Key;
    struct TreeNodeType *left;
    struct TreeNodeType *right;
}TreeNode;

/*
Function prototypes for the functions in Code201_Tree.c,
as it is not good practise to keep function declarations 
in the header file.
*/

void CreateTree();
int isEmpty();
TreeNode *SearchTree(int Key);
//to insert nodes
int Insert1(TreeNode *newNode);
int Insert2(int Key);
//to delete nodes
int Delete(int Key);
//to print nodes
void PrintOne(TreeNode *T);
void PrintTree();
//utlity queue functions
TreeNode *deQueue(TreeNode **queue, int *front);
TreeNode* getRoot();
void enQueue(TreeNode **queue, int *rear, TreeNode *new_node);
//Traversals:
void printLevelOrder(TreeNode* root);
TreeNode** createQueue(int *front, int *rear);      
static void Postorder(TreeNode *T);
static void Preorder(TreeNode *T);
static void Inorder(TreeNode *T);
void Postorder1();
void Preorder1();
void Inorder1();
void printLevelOrder1();
#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE (!FALSE)
#endif

#endif