#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Code201_Tree.h"

int main()
{
    TreeNode *newNode;
    char dummy; // Used in the scanf() to to pause before continuing

    //Initializing the tree
    CreateTree();

    printf("Building tree...\n");
    // Do simple insert of 15 nodes into tree.
    // Insert with keys in the order.
    //   8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 
    // First 5 nodes are inserted using Insert1(). Remainder using Insert2()

    // Node 1
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 8;
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 2
    // Note: Each time a new node is allocated we reuse the same pointer
    // Access to the previous node is not lost because it is not in the tree.
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 4;
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 3
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 12;
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 4
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 2;
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 5
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->Key = 6;
    newNode->left = newNode->right = NULL;
    Insert1(newNode);

    // Node 6
    // Remainder of the nodes are inserted using Insert2()
    Insert2(10);

    // Node 7
    Insert2(14);

    // Node 8
    Insert2(1);
    
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