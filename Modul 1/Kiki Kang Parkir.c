/**
 * Implementasi ADT SInglyList (Singly Linked List)
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

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }

    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {

        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

bool isDobel(int arr[], int n)
{
    int i, j, ctr = 0;
    for(i = 0;i < n;i++) for(j = i+1;j < n;j++) if(arr[i] == arr[j]) ctr++;
    return (ctr > 0);
}

int MaxCounter(int *array, int size)
{
    int i, j, maxCount, count;
    maxCount = -100000;
    for (i = 0; i< size; i++)
    {
        count = 1;
        for(j = i+1; j < size; j++)
        {
            if(array[j] == array[i])
            {
                count++;
                if(count > maxCount) maxCount = count;
            }
        }
    }
    //printf("%d", maxCount);
    //return maxCount;
    return maxCount;
}

int Counter(SinglyList *list, int n, int k)
{
    SListNode *temp = list->_head;
    int arr[101010] = {0}, counter = 0;
    bool done = 0;
    while(temp->next != NULL && !done){
        arr[counter] = temp->data;
        arr[counter+1] = temp->next->data;
        counter += 2;
        //printf("%d - %d\n", temp->data, temp->next->data);
        //printf("COUNT KE %d dan %d\n", counter, counter + 1);
        temp=temp->next->next;
        //printf("COUNTER SEKARANG: %d\n", counter);
        if (counter == n) {done = 1; break;}//printf("CHECK GANNNN\n");
    }
    //printf("SEKARANG: %d\n", counter);
    if (n%2==1) {arr[counter] = slist_back(list); counter++;}
    //for (int i = 0; i < counter; i++) printf("%d. %d\n", i+1, arr[i]);
    return MaxCounter(arr, n);
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&myList);

    int n, k;
    bool done = 0;
    while (!done)
    {
        scanf("%d %d", &n, &k);
        int a[n+10], e[n+10];
        if (n == 0 && k == 0) done = 1;
        else
        {
            int total = 0;
            bool samaan = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d %d", &a[i], &e[i]);
                if (a[i] == e[i]) samaan = 1;
                total += e[i]-a[i];
            }
            //printf("TOTAL: %d\n", total);
            SinglyList nums;
            slist_init(&nums);
            for (int j = 0; j < n; j++) for (int i = a[j]; i < e[j]; i++) {slist_pushBack(&nums, i);}
            if (isDobel(a, n) || isDobel(e, n) || Counter(&nums, total, k) > k || samaan) printf("Gimana nih boss\n");
            else printf("Bisa boss\n");
        }
    }
    puts("");
    return 0;
}
