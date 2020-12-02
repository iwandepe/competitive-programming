#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
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
int stack_top(Stack *stack);
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
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        newNode->data = value;
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

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    int i, val, n;
	int order[1000];
    scanf("%d", &n);
    while (! n == 0) {
    	int status = 1; int need = 1;
        Stack myStack;
        stack_init(&myStack);

        for (i=0; i<n; i++){
            scanf("%d", &val);
            order[i] = val;
        }
        for (i=0; i<n; i++){
            while (!stack_isEmpty(&myStack) && stack_top(&myStack) == need){
                need++;
                stack_pop(&myStack);
            }
            if (order[i] == need) {
                need++;
            }
            else if (!stack_isEmpty(&myStack) && stack_top(&myStack) < order[i]) {
                status = 0;
                break;
            }
            else {
                stack_push(&myStack, order[i]);
            }

        }
        
        if (status) printf("yes\n");
        else printf("no\n");
        
        scanf("%d", &n);
    }	
	
	return 0;
}
