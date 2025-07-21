#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int dfsSearch(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    return dfsSearch(root->left, value) || dfsSearch(root->right, value);
}
int main() {
    Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    int findValue = 3;
    if (dfsSearch(root, findValue)) {
        printf("true\n");
    }else {
        printf("false\n");
    }
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}