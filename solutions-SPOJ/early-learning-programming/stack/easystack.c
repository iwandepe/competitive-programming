#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    long long min;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    long long _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, long long value);
void stack_pop(Stack *stack);
long long stack_topmin(Stack *stack);
long long stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, long long value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        newNode->min = value;
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

long long stack_topmin(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->min;
    return 0;
}

long long stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);
	long long val,n,i,perintah;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d", &perintah);
		if (perintah == 1) {
			scanf("%d", &val);
			stack_push(&myStack, val);
		}
		else if (!stack_isEmpty(&myStack) && perintah == 2) {
			stack_pop(&myStack);
		}
		else if (!stack_isEmpty(&myStack) && perintah == 3) {
			printf("%d\n", stack_topmin(&myStack));
		}
		else if (stack_isEmpty(&myStack) && (perintah==2 || perintah==3)){
			printf("Empty!\n");
		}
	}
    return 0;
}



