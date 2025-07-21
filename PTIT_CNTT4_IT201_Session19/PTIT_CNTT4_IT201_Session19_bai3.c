#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->data);
}
int main() {
    Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    postorder(root);
    free(root->left->left);
    free(root->left);
    free(root);
    return 0;
}