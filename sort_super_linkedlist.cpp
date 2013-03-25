#include <stdio.h>
#include <stdlib.h>
#include "errno.h"

//-------------------------------------------------------
typedef float DType;
int   cmp(DType d1, DType d2);
char *toString(char *buf, DType d);
//-------------------------------------------------------
int cmp(float d1, float d2) {
    if (d1 == d2) return 0;
    return (d1 < d2) ? -1 : 1;
}
char *toString(char *buf, float d) {
    sprintf(buf, "%6.2f", d);
    return buf;
}
//-------------------------------------------------------
struct SLNode;
typedef struct SLNode *LNode;

struct SLNode  {
    DType data;
    LNode next;
};

LNode newLNode(DType d, LNode next) {
    LNode n = malloc(sizeof(struct SLNode));
    n->data = d;
    n->next = next;
    return n;
}
void freeLNode(LNode p) {
    free(p);
}
//-------------------------------------------------------
struct SLList;
typedef struct SLList *LList;

struct SLList  {
    int size;
    LNode header;
};
LList newLList() {
    LList list = malloc(sizeof(struct SLList));
    list->size = 0;
    list->header = newLNode(0, NULL);
    return list;
}
void freeLList(LList list) {
    LNode q, p = list->header;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    free(list);
} 
//-------------------------------------------------------
int sizeOfLList(LList list) {
    return list->size;
}
int isEmptyLList(LList list) {
    return list->size == 0;
}
void printLList(LList list) {
    printf("LList[ ");
    LNode p = list->header->next;
    char buf[100];
    while( p != NULL) {
        printf("%s ", toString(buf, p->data));
        p = p->next;
    }
    printf("]\n");
}
//-------------------------------------------------------  
LNode nodeOf(LList list, int pos) { // -1 is header
    if (pos >= list->size) exit(ERR_LLIST_NOF_OOR);
    LNode p = list->header;
    int i;
    for (i=-1; i<pos; i++) p = p->next;
    return p;
}
LNode addAfterLNode(LList list, LNode p, DType x) {
    if (p == NULL) exit(ERR_LLIST_AAF_NULL);
    p->next = newLNode(x, p->next);
    list->size++;
    return p->next;
}
//-----------------------------------------------------
DType getLList(LList list, int pos) {
    if (pos < 0 || pos >= list->size) {
        exit(ERR_LLIST_GET_OOR);
    }
    return nodeOf(list, pos)->data;
}

DType setLList(LList list, int pos, DType x) {
    if (pos < 0 || pos >= list->size) {
        exit(ERR_LLIST_SET_OOR);
    }
    LNode p = nodeOf(list, pos);
    DType old = p->data;
    p->data = x;
    return old;
}

void addLList(LList list, int pos, DType x) {
    if (pos < 0 || pos > list->size) {
        exit(ERR_LLIST_ADD_OOR);
    }
    addAfterLNode(list, nodeOf(list,pos-1), x);
}

void addFirstLList(LList list, DType x) {
    addLList(list, 0, x);
}

void addLastLList(LList list, DType x) {
    addLList(list, list->size, x);
}

int indexOfLList(LList list, DType x) {
    LNode p = list->header->next;
    int pos = 0;
    while(p != NULL) {
        if(cmp(x, p->data) == 0) return pos;
        p = p->next;
        pos++;
    }
    return -1; // not found
}

DType removeLList(LList list, int pos) {
    if (pos < 0 || pos >= list->size) {
        exit(ERR_LLIST_REM_OOR);
    }
    LNode p = nodeOf(list, pos-1);
    LNode q = p->next;
    DType x = q->data;
    p->next = p->next->next;
    list->size--;
    free(q);
    return x;
}

// void  reverseLList(LList list) { ... }
// int   equalLList(LList list1, LList list2) { ... }
// LList createLList(DType data[], int n) { ... }
