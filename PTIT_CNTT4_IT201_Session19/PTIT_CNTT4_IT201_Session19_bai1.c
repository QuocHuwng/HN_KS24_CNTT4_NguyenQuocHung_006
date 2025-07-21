#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* newNode(){
    int value;
    printf("Enter value of node: ");
    scanf("%d",&value);
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void printfNode(Node *node) {
    if(node == NULL) {
        printf("NULL\n");
        return;
    }
    printf("node ={\n");
    printf("data: %d\n",node->data);
    printf("left->%s\n",node->left == NULL ? "NULL":"not NULL");
    printf("right->%s\n",node->right == NULL ? "NULL":"not NULL");
    printf("}\n");
}
int main() {
    Node *node = newNode();
    printfNode(node);
    free(node);
    return 0;
}