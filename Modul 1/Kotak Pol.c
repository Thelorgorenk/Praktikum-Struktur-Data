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

int stack_topid(Stack *stack)
{
    if (!stack_isEmpty(stack))
        return stack->_top->id;
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

int getMaxId(Stack *stack)
{
    StackNode *temp = stack->_top;
    int x=temp->data, y = temp->id;
    while(temp->next != NULL){
        if(temp->next->data > x) {x=temp->next->data;y = temp->next->id;}
        temp=temp->next;
    }
    return y;
}

int getMax(Stack *stack)
{
    StackNode *temp = stack->_top;
    int x=temp->data;
    while(temp->next != NULL){
        if(temp->next->data > x) {x=temp->next->data; break;}
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

    int n, num, na;
    scanf("%d", &n);
    na = n;
    while (n--)
    {
        scanf("%d", &num);
        stack_push(&myStack, num, na-counter-1);
        counter++;
    }
    //printf("CHECKER %d %d\n", getMax(&myStack),stack_topid(&myStack));
    for (int i = 0; i < na; i++)
    {
        if (getMax(&myStack) > stack_top(&myStack))
        {
            printf("%d ", getMax(&myStack));
            stack_pop(&myStack);
        }
        //else if (getMaxId(&myStack))
        else if (getMaxId(&myStack) == stack_topid(&myStack))
        {
            printf("-1 ");
            stack_pop(&myStack);
        }
    }
    printf("\n");
    puts("");
    return 0;
}
