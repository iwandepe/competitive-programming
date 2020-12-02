#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);
void deq_reverse(Deque *deque);

int main(int argc, char const *argv[])
{
    Deque mydeq;
    deq_init(&mydeq);

    int t,i=0,val,flag=0;
    char perintah[10];
    scanf("%d", &t);
    for (; i<t; i++) {
        scanf(" %s", perintah);
        if (!deq_isEmpty(&mydeq) && strcmp(perintah, "back") == 0){
            printf("%d\n", deq_back(&mydeq)); 
            deq_popBack(&mydeq);
        }
        else if (!deq_isEmpty(&mydeq) && strcmp(perintah, "front") == 0){
            printf("%d\n", deq_front(&mydeq));
            deq_popFront(&mydeq);
        }
        else if (strcmp(perintah, "reverse") == 0){
            deq_reverse(&mydeq);
        }
        else if (strcmp(perintah, "push_back") == 0){
            scanf("%d", &val);
            deq_pushBack(&mydeq, val);
        }
        else if (strcmp(perintah, "toFront") == 0){
            scanf("%d", &val);
            deq_pushFront(&mydeq, val);
        }
        else {
            printf("No job for Ada?\n");
        }
    }
    return 0;
}
/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_reverse(Deque *deque) {
    Deque *temp;
    printf("1");        
    // BUG DI DUNGSI INI
    // SETELAH MEMANGGIL FUNGSI INI LANGSUNG KELUAR PROGRAM
    while (!deq_isEmpty(deque)){printf("a");
       deq_pushFront(temp, deque->_head->data);printf("s");
       deq_popFront(deque);
    }
    while (!deq_isEmpty(temp)){
        deq_pushBack(deque, temp->_tail->data);
        deq_popBack(temp);
    }
}