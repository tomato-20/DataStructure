#include <stdio.h>
#include <stdlib.h>

typedef struct BSTnode
{
    int info;
    struct BSTnode *left;
    struct BSTnode *right;
} bnode;

bnode *root = NULL;

bnode *search_BST(bnode *, int);
bnode *insert_BST(bnode *, int);
bnode *delete_BST(bnode *, int);
bnode *find_min_BST(bnode *);
void inorder(bnode *);

int main()
{
    bnode *temp;
    int A[] = {50, 25, 75, 12, 30, 85, 60, 52, 70, 72};

    for (int i = 0, size = sizeof(A) / sizeof(A[0]); i < size; i++)
    {
        root = insert_BST(root, A[i]);
    }

    printf("\nTree: ");
    inorder(root);

    temp = search_BST(root, 85);
    if (temp)
        printf("search successful!");
    else
        printf(" search unsuccessful!");

    temp = search_BST(root, 4);
    if (temp)
        printf("search successful!");
    else
        printf(" \nsearch unsuccessful!");

    root = delete_BST(root, 5);
    root = delete_BST(root, 85);

    printf("\nTree: ");
    inorder(root);

    root = delete_BST(root, 50);

    printf("\nTree: ");
    inorder(root);
    return 0;
}

bnode *search_BST(bnode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->info == key)
        return root;
    if (root->info > key)
        return search_BST(root->left, key);
    if (root->info < key)
        return search_BST(root->right, key);
}

bnode *insert_BST(bnode *root, int item)
{
    bnode *new_node;
    if (root == NULL)
    {
        new_node = (bnode *)malloc(sizeof(bnode));
        new_node->info = item;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    else
    {
        if (item < root->info)
            root->left = insert_BST(root->left, item);
        if (item > root->info)
            root->right = insert_BST(root->right, item);
    }
    return root;
}

bnode *delete_BST(bnode *root, int item)
{
    bnode *temp;
    if (root == NULL)
    {
        return NULL;
    }
    else if (item < root->info)
        root->left = delete_BST(root->left, item);
    else if (item > root->info)
        root->right = delete_BST(root->right, item);
    else //item to be deleted found
    {
        if (root->left != NULL && root->right != NULL)
        {
            temp = find_min_BST(root->right);
            root->info = temp->info;
            root->right = delete_BST(root->right, root->info);
        }
        else
        {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}

bnode *find_min_BST(bnode *root)
{
    bnode *current = root;
    if (root == NULL)
    {
        printf("Empty tree!");
        return NULL;
    }
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void inorder(bnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}
