#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"

int main()
{
    TreeNode *newNode;
    char dummy; // Used in the scanf() to to pause before continuing

    //Initializing the tree
    CreateTree();

    printf("Building tree with 14, 15, 8, 9, 7, 6 as the elements...\n");

    Insert2(14);
    Insert2(15);
    Insert2(8);
    Insert2(9);
    Insert2(7);
    Insert2(6);

    printf("All nodes inserted\n");
    int one = 1;
    while(one){
        int c=0;
        int temp=0;
        printf("Type:\n0 - insert a node\n1 - delete a node\n2 - traverse the tree(preorder)\n3 - traverse the tree(postorder)\n4 - traverse the tree(inorder)\n5 - traverse the tree(level-based order)\n6 - search for a key\n7 - exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 0:
            printf("Type in the value of the node to be inserted:");
            temp;
            scanf("%d", &temp);
            Insert2(temp);
            printf("Insertion completed.\n");
            break;
        case 1:
            printf("Type in the value of the node to be deleted:");
            temp;
            scanf("%d", &temp);
            Delete(temp);
            printf("Insertion completed.\n");
            break;
        case 2:
            printf("The tree traversed in preorder: ");
            Preorder1();
            printf("\n");
            break;
        case 3:
            printf("The tree traversed in postorder: ");
            Postorder1();
            printf("\n");
            break;
        case 4:
            printf("The tree traversed in inorder: ");
            Inorder1();
            printf("\n");
            break;
        case 5:
            printf("The tree traversed in level based order: ");
            printLevelOrder1();
            printf("\n");
            break;
        case 6:
            printf("Type in the key value to be searched for:");
            scanf("%d", &temp);
            newNode = SearchTree(6);
            if(newNode != NULL)
            {
                printf("The tree contains the given key.");
                free(newNode);
            }
            else
                printf("The tree doesn't contain the given key.\n");
            break;
        case 7:
            one = 0;
            break;
        default:
            printf("Wrong input, try again.\n\n");
            break;
        }
    }
    /*
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

        //as newNode is a duplicate node and not in the tree.
        free(newNode);
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
    */
}