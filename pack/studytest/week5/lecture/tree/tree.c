// Implements a list of numbers as a binary search tree

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

bool search_tree(node *root, int tar_val);
void free_tree(node *root);

int main(void)
{
    // Tree of size 0
    node *tree = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return 1;
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    // Get target value
    int tar_val = 0;
    printf("Target: ");
    scanf("%i", &tar_val);

    // Print target value
    if (search_tree(tree, tar_val))
        printf("Element found.\n");
    else
        printf("Element not found.\n");

    // Free tree
    free_tree(tree);
    return 0;
}

bool search_tree(node *root, int tar_val)
{
    if (root == NULL)
        return false;
    else if (tar_val < root->number)
        return search_tree(root->left, tar_val);
    else if (tar_val > root->number)
        return search_tree(root->right, tar_val);
    else
        return true;
}

void free_tree(node *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
