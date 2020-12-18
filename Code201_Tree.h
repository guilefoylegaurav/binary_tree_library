#ifndef CODE201_TREE_H
#define CODE201_TREE_H
#include <stdio.h>

//Defining a tree node
typedef struct TreeNodeType
{
    int                 Key;
    float               fValue;
    int                 iValue;
    char                cArray[7];
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
int Insert1(TreeNode *newNode);
int Insert2(int Key, float f, int i, char *cA);
int Delete(int Key);
void PrintOne(TreeNode *T);
void PrintTree();

#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE (!FALSE)
#endif

#endif