/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 *
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int mini = 10000, maxi = 0, counter = 0;
int miniid, maxiid;
int mini2 = 10000, maxi2 = 0;

/* Struktur Node */

typedef struct stackNode_t {
    int data, id;
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
void stack_push(Stack *stack, int value, int id);
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

void stack_push(Stack *stack, int value, int id)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        newNode->id = id;
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

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

int getMin(Stack *stack)
{
    StackNode *temp = stack->_top;
    int x=temp->data;
    while(temp->next != NULL){
        if(temp->next->data < x) x=temp->next->data;
        temp=temp->next;
    }
    return x;
}

int getMax(Stack *stack)
{
    StackNode *temp = stack->_top;
    int x=temp->data;
    while(temp->next != NULL){
        if(temp->next->data > x) x=temp->next->data;
        temp=temp->next;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;
    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);


    char cmd[10000];
    int n, num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'p' && cmd[1] == 'u')
        {
            scanf("%d", &num);
            stack_push(&myStack, num, counter);
            counter++;
        }
        else if (cmd[0] == 't') printf("%d\n", stack_top(&myStack));
        else if (cmd[0] == 'm' && cmd[1] == 'i') printf("%d\n", getMin(&myStack));
        else if (cmd[0] == 'd') printf("%d\n", (getMax(&myStack)-getMin(&myStack)));
        else if (cmd[0] == 'm' && cmd[1] == 'a') printf("%d\n", getMax(&myStack));
        else if (cmd[0] == 'p' && cmd[1] == 'o') stack_pop(&myStack);
    }
    puts("");
    return 0;
}
