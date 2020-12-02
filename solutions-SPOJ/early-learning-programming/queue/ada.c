#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_toFront(Queue *queue, int value);
void queue_popFront(Queue *queue);
void queue_popBack(Queue *queue);
void queue_front(Queue *queue);
void queue_back(Queue *queue);
void queue_reverse(Queue *queue);
int  queue_size(Queue *queue);

int main(int argc, char const *argv[])
{
    Queue myQueue;
    queue_init(&myQueue);

    int t,i=0,val;
    char perintah[10];
    scanf("%d", &t);
    for (; i<t; i++) {
        scanf(" %s", perintah);
        if (!queue_isEmpty(&myQueue) && strcmp(perintah, "back") == 0){
            queue_back(&myQueue);
        }
        else if (!queue_isEmpty(&myQueue) && strcmp(perintah, "front") == 0){
            queue_front(&myQueue);
        }
        else if (queue_isEmpty(&myQueue) && strcmp(perintah, "reverse") == 0) continue;
        else if (!queue_isEmpty(&myQueue) && strcmp(perintah, "reverse") == 0){
            queue_reverse(&myQueue);
        }
        else if (strcmp(perintah, "push_back") == 0){
            scanf("%d", &val);
            queue_push(&myQueue, val);
        }
        else if (strcmp(perintah, "toFront") == 0){
            scanf("%d", &val);
            queue_toFront(&myQueue, val);
        }
        else {
            printf("No job for Ada?\n");
        }
    }

    return 0;
}

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_toFront(Queue *queue, int value){
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            newNode->next = queue->_front;
            queue->_front = newNode;
        }
    }
}

void queue_popFront(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

void queue_popBack(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        QueueNode *prev = temp;
        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        if (queue->_front->next == NULL)
            queue->_front = queue->_front->next;
        prev->next = NULL;
        queue->_rear = prev;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

void queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        printf("%d\n", queue->_front->data);
        queue_popFront(queue);
    }
}

void queue_back(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        printf("%d\n", queue->_rear->data);
        queue_popBack(queue);
    }
}

void queue_reverse(Queue *queue){
    Queue *temp;
            
    while (!queue_isEmpty(queue)){
       queue_push(temp, queue->_front->data); // MASALAH ADA DI BARIS INI
       // SETELAH BARIS INI LANGSUNG KELUAR PROGRAM
       queue_popBack(queue);
    }
    while (!queue_isEmpty(temp)){
        queue_toFront(queue, temp->_front->data);
        queue_popFront(temp);
    }
}

int queue_size(Queue *queue) {
    return queue->_size;
}
