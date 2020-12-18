/*
Submitted by:
GROUP 5
--------
Snehil Sharma (1912017)​
Gaurav Bhattacharjee (1912018)​
Sri Sylamsh Amrutakavi (1912065)​
Kotari Aditya (1912093)​
Saumyajit Chowdhury (1912116)​
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"

//Declaring global pointer which will be the root of the tree
static TreeNode *root;    
//Prototyping function so CreateTree can call it.
static void ClearTree(TreeNode *T); 

//Creates a tree and initializes it to NULL
void CreateTree()
{
    ClearTree(root);
    root = NULL;
    return;
}

//Iteratively destroys all nodes.
static void ClearTree(TreeNode *T)
{
    if(T==NULL) return;  // Nothing to clear
    if(T->left != NULL) ClearTree(T->left); // Clear left sub-tree
    if(T->right != NULL) ClearTree(T->right); // Clear right sub-tree
    free(T);    // Destroy this node
    return;
}

//Checks if the tree is empty.
int isEmpty()
{
    return(root==NULL);
}

//Duplicates a node, in order to give access to node data without affecting the tree.
static TreeNode *DupNode(TreeNode * T)
{
    TreeNode *dupNode;

    dupNode = (TreeNode *)malloc(sizeof(TreeNode));
    *dupNode = *T;    // Copy the data structure
    dupNode->left = NULL;    // Set the pointers to NULL
    dupNode->right = NULL;
    return dupNode;
}

//Iteratively searches the tree for a given value
TreeNode *SearchTree(int Key)
{
    int      ValueInTree = FALSE;
    TreeNode *temp;

    temp = root;
    while((temp != NULL) && (temp->Key != Key))
    {
        if(Key < temp->Key)
            temp = temp->left;  // Search key comes before this node.
        else
            temp = temp->right; // Search key comes after this node 
    }
    if(temp == NULL) return temp;    // Search key not found
    else
        return(DupNode(temp));    // Found it so return a duplicate
}

//Inserts a new node at the specified point
int Insert1(TreeNode *newNode)
{
    TreeNode *temp;
    TreeNode *back;

    temp = root;
    back = NULL;

    while(temp != NULL) // Loop till temp falls out of the tree 
    {
        back = temp;
        if(newNode->Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    // Now attach the new node to the node that back points to 
    if(back == NULL) // Attach as root node in a new tree 
        root = newNode;
    else
    {
        if(newNode->Key < back->Key)
            back->left = newNode;
        else
            back->right = newNode;
    }
   return(TRUE);
}

//Creates a new node to be inserted
int Insert2(int Key)
{
    TreeNode *newNode;

    // Create the new node and copy data into it
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = Key;
    newNode->left = newNode->right = NULL;

    // Call Insert1() to do the insertion
    return(Insert1(newNode));
}

/*Deletes a node with the given value, 
returns 1 if successful and 0 if the node doesn't exist.*/
int Delete(int Key)
{
    TreeNode *back;
    TreeNode *temp;
    TreeNode *delParent;    // Parent of node to delete
    TreeNode *delNode;      // Node to delete

    temp = root;
    back = NULL;

    // Find the node to delete 
    while((temp != NULL) && (Key != temp->Key))
    {
        back = temp;
        if(Key < temp->Key)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == NULL) // Didn't find the one to delete 
    {
        printf("Key not found. Nothing deleted.\n");
        return FALSE;
    }
    else
    {
        if(temp == root) // Deleting the root 
        {
            delNode = root;
            delParent = NULL; 
        }                
        else
        {
            delNode = temp;
            delParent = back;
        }
    }

    // Case 1: Deleting node with no children or one child 
    if(delNode->right == NULL)
    {
        if(delParent == NULL)    // If deleting the root    
        {
            root = delNode->left;
            free(delNode);
            return TRUE;
        }
        else
        {
            if(delParent->left == delNode)
                delParent->left = delNode->left;
            else
                delParent->right = delNode->left;
            free(delNode);
            return TRUE;
        }
    }
    else // There is at least one child 
    {
        if(delNode->left == NULL)    // Only 1 child and it is on the right
        {
            if(delParent == NULL)    // If deleting the root    
            {
                root = delNode->right;
                free(delNode);
                return TRUE;
            }
            else
            {
                if(delParent->left == delNode)
                    delParent->left = delNode->right;
                else
                    delParent->right = delNode->right;
                free(delNode);
                return TRUE;
            }
        }
        else // Case 2: Deleting node with two children 
        {
            // Find the replacement value.  Locate the node  
            // containing the largest value smaller than the 
            // key of the node being deleted.                
            temp = delNode->left;
            back = delNode;
            while(temp->right != NULL)
            {
                back = temp;
                temp = temp->right;
            }
            // Copies the replacement values into the node to be deleted 
            delNode->Key = temp->Key;
            // Removes the replacement node from the tree 
            if(back == delNode)
                back->left = temp->left;
            else
                back->right = temp->left;
            free(temp);
            return TRUE;
        }
    }
}

//Prints just one node
void PrintOne(TreeNode *T)
{
    printf("%d ", T->Key);
}

//Depth first traversal : Inorder
static void Inorder(TreeNode *T)
{
    if (T == NULL)
    {
        return; 
    }
    
    Inorder(T->left); 
    PrintOne(T); 
    Inorder(T->right); 
}



//Depth first traversal : Preorder
static void Preorder(TreeNode *T)
{
    if (T == NULL)
    {
        return; 
    }
    PrintOne(T); 
    Preorder(T->left); 
    Preorder(T->right); 
}




//Depth first traversal : Postorder
static void Postorder(TreeNode *T)
{
    if (T == NULL)
    {
        return; 
    }
    
    Postorder(T->left); 
    Postorder(T->right); 
    PrintOne(T); 
}



//Prints the tree
void PrintTree()
{
    Inorder(root);
}



/*UTILITY FUNCTIONS*/
TreeNode** createQueue(int *front, int *rear)
{
    TreeNode **queue =
        (TreeNode**)malloc(sizeof(TreeNode*)
                                       *500);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(TreeNode **queue, int *rear, 
                             TreeNode *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

TreeNode *deQueue(TreeNode **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}
 
void printLevelOrder(TreeNode* root)
{
    int rear, front;
    TreeNode **queue = createQueue(&front, &rear);
    TreeNode *temp_node = root;
 
    while (temp_node)
    {
        PrintOne(temp_node);
 
        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}
void Postorder1(){
    Postorder(root);
}
void Preorder1(){
    Preorder(root);
}
void Inorder1(){
    Inorder(root);
}
void printLevelOrder1(){
    printLevelOrder(root);
}