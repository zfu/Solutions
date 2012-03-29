#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Node {
    struct Node *next;
    int data;
} Node;

typedef struct linklist {
    Node *head;
} List;

Node *createNode(int data) {
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    new->next = NULL;
    new->data = data;
    return new;
}

List *createList() {
    List *new;
    new = (List *)malloc(sizeof(List));
    new->head = NULL;
    return new;
}

int insertNode(List *list, Node *node, int pos) {
    int i = 0;
    if(list->head == NULL) {
        printf("\nError: list is empty\n");
        return FALSE;
    }
    Node **nextptr;
    Node *current;
    current = list->head;
    while((current!= NULL) && (i != pos)) {
        nextptr = &current->next;
        current = *nextptr;
        i++;
    }
    node->next = current;
    *nextptr = node;
    return TRUE;
}

int appendNode(List *list, Node *node) {
    Node **nextptr;
    Node *current;
    if(list->head == NULL) {
        list->head = node;
        return TRUE;
    }
    current = list->head;
    nextptr = &current->next;
    while((current = *nextptr) != NULL) {
        nextptr = &current->next;
    }
    //current = node;
    *nextptr = node;
    (*nextptr)->next = NULL;
    return TRUE;
}

int searchData(List *list, int data) {
    if(list->head == NULL) {
        return -1;
    }
    Node *ptr;
    ptr = list->head;
    int i = 0;
    while(ptr != NULL) {
        if(ptr->data == data)
            return i;
        ptr = ptr->next;
        i++;
    }
    return -1;
}

int deleteNode(List *list, int data) {
    if(list->head == NULL) {
        printf("\nError: list is NULL\n");
        return FALSE;
    }
    Node *current;
    Node **nextptr;
    current = list->head;
    *nextptr = current->next;
    if(current->data == data) {
        list->head = *nextptr;
        free(current);
        return TRUE;
    }
    Node *tmp;
    while(current != NULL) {
        if((*nextptr)->data == data) {
            tmp = *nextptr;
            current->next = (*nextptr)->next;
            free(tmp);
            return TRUE;
        }
        nextptr = &current->next;
        current = *nextptr;
    }

    return FALSE;
}

void printList(List *list) {
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr = list->head;
    printf("\n************************\n");
    printf("\nNow list: \n");
    while(ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n************************\n");
}





int main() {
    Node *a = createNode(29);
    Node *b = createNode(23);
    Node *c = createNode(32);
    Node *d = createNode(1000);
    Node *e = createNode(100);
    List *list = createList();
    appendNode(list, a);
    appendNode(list, b);
    appendNode(list, c);
    printList(list);
    insertNode(list, d, 1);
    printList(list);
    //int search = 32;
    //printf("\nSEARCH DATA %d, RESULT %d\n", search, searchData(list, search));
    //search = 999;
    //printf("\nSEARCH DATA %d, RESULT %d\n", search, searchData(list, search));
    //search = 23;
    //printf("\nSEARCH DATA %d, RESULT %d\n", search, searchData(list, search));
    deleteNode(list, 29);
    printList(list);
    deleteNode(list, 23);
    printList(list);
    appendNode(list, e);
    printList(list);

    return 0;
}
