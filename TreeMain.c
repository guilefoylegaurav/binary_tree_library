//---------------------------------------------------------------
// File: TreeMain.c
// Purpose: Main file for a demonstration of a binary tree
// Programming Language: C
// Author: Dr. Rick Coleman
// Date: February, 2002
//---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Code201_Tree.h"

int main(void)
{
    TreeNode *newNode;
    char     dummy; // Used in the scanf() to to pause before continuing

    // Do initialization stuff
    CreateTree();

    printf("Building tree...\n");
    // Do simple insert of 15 nodes into tree.
    // Insert with keys in the order.
    //   8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 
    // First 5 nodes are inserted using Insert1(). Remainder using Insert2()

    // Node 1
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 8;
    newNode->iValue = 2;
    newNode->fValue = 2.3f;
    strcpy(newNode->cArray, "Node1");
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 2
    // Note: Each time a new node is allocated we reuse the same pointer
    // Access to the previous node is not lost because it is not in the tree.
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 4;
    newNode->iValue = 4;
    newNode->fValue = 3.4f;
    strcpy(newNode->cArray, "Node2");
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 3
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 12;
    newNode->iValue = 8;
    newNode->fValue = 4.5f;
    strcpy(newNode->cArray, "Node3");
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 4
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 2;
    newNode->iValue = 16;
    newNode->fValue = 5.6f;
    strcpy(newNode->cArray, "Node4");
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 5
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 6;
    newNode->iValue = 32;
    newNode->fValue = 6.7f;
    strcpy(newNode->cArray, "Node5");
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 6
    // Remainder of the nodes are inserted using Insert2()
    Insert2(10, 7.8f, 64, "Node6");

    // Node 7
    Insert2(14, 8.9f, 128, "Node7");

    // Node 8
    Insert2(1, 9.0f, 256, "Node8");

    // Node 9
    Insert2(3, 0.9f, 512, "Node9");

    // Node 10
    Insert2(5, 9.8f, 1024, "Node10");

    // Node 11
    Insert2(7, 8.7f, 2048, "Node11");

    // Node 12
    Insert2(9, 7.6f, 4096, "Node12");

    // Node 13
    Insert2(11, 6.5f, 8192, "Node13");

    // Node 14
    Insert2(13, 5.4f, 16384, "Node14");

    // Node 15
    Insert2(15, 4.3f, 32768, "Node15");

    printf("All nodes inserted\n");

    // Print the tree
    printf("-----------------------------------------------------\n");
    PrintTree();
    printf("Press Enter to continue...");
    scanf("%c", &dummy);
    printf("-----------------------------------------------------\n");

    // Find some nodes and print them
    printf("-----------------------------------------------------\n");
    printf("Testing the search function\n");
    newNode = SearchTree(13);
    if(newNode != NULL)
    {
        PrintOne(newNode);
        free(newNode); // Remember this is a duplicate node of the one in
                       // in the tree and main() is responsible for deleting it.
    }
    else
        printf("Search key not found.\n");

    newNode = SearchTree(6);
    if(newNode != NULL)
    {
        PrintOne(newNode);
        free(newNode);
    }
    else
        printf("Search key not found.\n");

    newNode = SearchTree(1);
    if(newNode != NULL)
    {
        PrintOne(newNode);
        free(newNode);
    }
    else
        printf("Search key not found.\n");

    newNode = SearchTree(25); // Note: there is no Key=25 in the tree
    if(newNode != NULL)
    {
        PrintOne(newNode);
        free(newNode);
    }
    else
        printf("Search key not found.\n");

    // Delete some nodes
    printf("-----------------------------------------------------\n");
    printf("Testing delete function\n");
    printf("-----------------------------------------------------\n");
    printf("Testing deleting a leaf...\n");
    Delete(7);    // Delete a known leaf
    PrintTree();
     printf("Press Enter to continue...");
    scanf("%c", &dummy);
    printf("-----------------------------------------------------\n");

    printf("-----------------------------------------------------\n");
    printf("Testing deleting a node with 2 children...\n");
    Delete(12);    // Delete a node known to have 2 children
    PrintTree();
    printf("Press Enter to continue...");
    scanf("%c", &dummy);
    printf("-----------------------------------------------------\n");

    printf("-----------------------------------------------------\n");
    printf("Testing deleting a node with 1 child...\n");
    Delete(6);    // Delete a node known to have only 1 child
    PrintTree();
    printf("Press Enter to continue...");
    scanf("%c", &dummy);
    printf("-----------------------------------------------------\n");

    printf("-----------------------------------------------------\n");
    printf("Testing trying to delete a node that is not in the tree...\n");
    Delete(7);    // Delete a node that is not there
    PrintTree();
    printf("Press Enter to continue...");
    scanf("%c", &dummy);
    printf("-----------------------------------------------------\n");

    printf("-----------------------------------------------------\n");
    printf("Testing deleting the root...\n");
    Delete(8);    // Delete the root
    PrintTree();
    printf("Done.\nPress Enter to continue...");
    scanf("%c", &dummy);

    printf("-----------------------------------------------------\n");
}