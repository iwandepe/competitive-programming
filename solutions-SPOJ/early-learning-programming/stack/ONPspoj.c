#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    char data;
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

bool isalpha(char x);
char* convert(char str[]);

bool isalpha(char x){
    return ((x>='A' && x<='Z') || (x>='a' && x<='z'));
}

char* convert(char str[]) {
    Stack myStack;
    char hasil[100];
    int i=0;
    for (; i<strlen(str); i++){
        if (isalpha(str[i])){
            printf("%c", str[i]);
        }
        else if (str[i] == '(') continue;
        else if (str[i] == ')') {
            printf("%c", stack_top(&myStack));
            stack_pop(&myStack);
        }
        else if (str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='*' || str[i]=='^') {
            stack_push(&myStack, str[i]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    char str[400];
    int n,i=0;
    scanf("%d", &n);
    for (; i<n; i++){
        scanf("%s", str);
        convert(str);
    }
    return 0;
}
