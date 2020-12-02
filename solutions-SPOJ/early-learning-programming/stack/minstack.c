#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int min;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_topmin(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        if (stack_isEmpty(stack)){
			newNode->next = NULL;
			newNode->min = value;
			stack->_top = newNode;
		}
        else {
			newNode->next = stack->_top;
			newNode->min = stack->_top->min; 
	        stack->_top = newNode;
			if (value < stack->_top->min) stack->_top->min = value;
		}
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

int stack_topmin(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->min;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);
	char perintah[5];
	int val,n,i;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf(" %s", perintah);
		if (strcmp(perintah, "PUSH") == 0) {
			scanf("%d", &val);
			stack_push(&myStack, val);
		}
		else if (!stack_isEmpty(&myStack) && strcmp(perintah, "MIN") == 0) {
			printf("%d\n", stack_topmin(&myStack));
		}
		else if (!stack_isEmpty(&myStack) && strcmp(perintah, "POP") == 0) {
			stack_pop(&myStack);
		}
		else {
			printf("EMPTY\n");
		}
	}
    return 0;
}



