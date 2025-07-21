#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue {
    Node** items;
    int front, rear, size, capacity;
} Queue;
Queue* newQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->items = (Node**)malloc( sizeof(Node*) * capacity);
    return queue;
}
void enQueue(Queue* queue, Node* node) {
    if (queue->size == queue->capacity) {
        queue->rear++;
        queue->items[queue->rear] = node;
        queue->size++;
    }
}
Node* deQueue(Queue* queue) {
    if (queue->size == 0) {
        return NULL;
    }
    Node* node = queue->items[queue->front];
    queue->front++;
    queue->size--;
    return node;
}
void addNode(Node* root, int value) {
    if (root == NULL) {
        return;
    }
    Queue* queue = newQueue(100);
    enQueue(queue, root);
    while (queue->size>0) {
        Node* current = deQueue(queue);
        if (current->left=NULL) {
            current->left=newNode(value);
            break;
        }else {
            enQueue(queue,current->left);
        }
        if (current->right=NULL) {
            current->right=newNode(value);
            break;
        }else {
            enQueue(queue, current->right);
        }
    }
    free(queue->items);
    free(queue);
}
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = newQueue(100);
    enQueue(queue, root);
    while (queue->size>0) {
        Node* current = deQueue(queue);
        printf("%d\n", current->data);
        if (current->left!=NULL)enQueue(queue, current->left);
        if (current->right!=NULL)enQueue(queue, current->right);
    }
    free(queue->items);
    free(queue);
}
int main() {
    Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    levelOrder(root);
    addNode(root, 6);
    levelOrder(root);
    return 0;
}