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

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    char seq;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

bool damping = 0;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value);
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

void stack_push(Stack *stack, char value)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->seq = value;

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pusht(Stack *stack, int value)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;

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
        return stack->_top->seq;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void Checker(Stack *stack)
{
    StackNode *temp = stack->_top;
    printf("%c\n", temp->seq);
    while(temp->next != NULL){
        //if((temp->next->seq == 'C' && temp->seq == 'T') || (temp->next->seq == '9' && temp->seq == '1') || (temp->next->seq == '0' && temp->seq == '2'))
        //{

        //}
            //x=temp->next->data;
        //printf("")
        //printf("%c\n", temp->seq);
        printf("%c %c\n", temp->seq, temp->next->seq);
        temp=temp->next->next;

    }
    //return x;
}

void RemoveDamping(char* str)
{
    int i = 0, k = 0;
    while (str[i])
    {
        if (str[i] == 'C' && (k > 0 && str[k - 1] == 'T')) --k, ++i;
        else if (str[i] == '9' && (k > 0 && str[k - 1] == '1')) --k, ++i;
        else if (str[i] == '0' && (k > 0 && str[k - 1] == '2')) --k, ++i;
        else if (str[i] == 'T' && (k > 0 && str[k - 1] == 'C')) --k, ++i;
        else if (str[i] == '1' && (k > 0 && str[k - 1] == '9')) --k, ++i;
        else if (str[i] == '2' && (k > 0 && str[k - 1] == '0')) --k, ++i;
        else str[k++] = str[i++];
    }
    str[k] = '\0';
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    // Operasi pada stack

    char str[10010] = {0};
    int counter = 0;
    scanf("%[^\n]s", str);
    //printf("string: %s", str);
    bool check = 0;
    RemoveDamping(str);
    while (!check)
    {
        if (str[counter] == '\0') check = 1;
        else counter++;
    }
    for (int j=0; j < counter; j++) stack_push(&myStack, str[j]);
    if (stack_isEmpty(&myStack)) printf("DOPEBASEDLIT\n");
    else printf("No way!\n");
    puts("");
    return 0;
}
