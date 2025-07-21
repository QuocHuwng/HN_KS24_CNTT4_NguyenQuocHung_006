#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* newNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right == NULL;
    return newNode;
}
typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;
Queue* newQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}
void enQueue(Queue* queue, Node* data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (queue->rear == NULL) {
        queue->front =queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}
Node* deQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    Node* data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}
int bssSearch(Node* root,int tafget) {
    if (root == NULL) {
        return 0;
    }
    Queue* queue = newQueue();
    enQueue(queue,root);
    while (!isQueueEmpty(queue)) {
        Node* current= deQueue(queue);
        if (current->data == tafget) {
            return 1;
        }
        if (current->left != NULL) {
            enQueue(queue,current->left);
        }
        if (current->right != NULL) {
            enQueue(queue,current->right);
        }
    }
    return 0;
}
int main() {
    Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    int finValue=3;
    int found=bssSearch(root,finValue);
    if (found==1) {
        printf("True\n");
    }else {
        printf("Flase\n");
    }
    return 0;
}