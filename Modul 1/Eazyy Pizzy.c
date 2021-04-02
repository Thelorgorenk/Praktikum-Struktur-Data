/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
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

typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pushganjil(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;
    PriorityQueue genap, ganjil;
    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);
    pqueue_init(&genap);
    pqueue_init(&ganjil);

    int num, ngenap = 0, nganjil = 0, iter = 0;
    bool x = 1;
    while (x)
    {
        scanf("%d", &num);
        if (num == 0) x = 0;
        else
        {
            if (num%2==0) {pqueue_push(&genap, num); ngenap++;}
            else {pqueue_pushganjil(&ganjil, num); nganjil++;}
            iter++;
        }
    }
    for (int i = 0; i < ngenap; i++)
    {
        printf("%d\n", genap._top->data);
        pqueue_pop(&genap);
    }
    for (int i = 0; i < nganjil; i++)
    {
        printf("%d\n", ganjil._top->data);
        pqueue_pop(&ganjil);
    }

    // cetak isi pque
    /*while (!pqueue_isEmpty(&myPque)) {
        printf("%d ", pqueue_top(&myPque));
        pqueue_pop(&myPque);
    }*/
    puts("");
    return 0;
}
