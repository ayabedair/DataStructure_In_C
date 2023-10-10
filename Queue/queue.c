//
// Created by Aya Bedair on 02/10/2023.
//
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "queue.h"

#ifdef LINKED_QUEUE

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

void InitializeQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int Append(QueueEntry element, Queue *q){
    QueueNode *pn = (QueueNode*) malloc(sizeof (QueueNode));
    //check if the memory is full
    if(!pn)
        return 0;
    else{
        pn->next = NULL;
        pn->entry = element;
        if(!q->rear)
            q->front = pn;
        else
            q->rear->next = pn;
        q->rear = pn;
        q->size++;
        return 1;
    }
}

void Serve(QueueEntry *element, Queue* q){
    QueueNode *pn = q->front;
    *element = pn->entry;
    q->front = pn->next;
    free(pn);
    if(!q->front)
        q->rear = NULL;
    q->size--;
}

bool QueueEmpty(Queue *q){
    return !q->size;
}

bool QueueFull(Queue *q){
    return 0;
}

int QueueSize(Queue *q){
    return q->size;
}

void ClearQueue(Queue *q){
    while(q->front){
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    q->size = 0;
}

void TraverseQueue(Queue *q, void (*function) (QueueEntry)){
    QueueNode *pn;
    for(pn=q->front; pn; pn=pn->next)
        (*function) (pn->entry);
}

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

void InitializeQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int Append(QueueEntry element, Queue *q){
    q->rear = (q->rear + 1) % MAXQUEUE;
    q->entry[q->rear] = element;
    q->size++;
    return 1;
}

void Serve(QueueEntry *element, Queue *q){
    *element = q->entry[q->front];
    q->front = (q->front + 1) % MAXQUEUE;
    q->size--;
}

bool QueueEmpty(Queue *q){
    return !q->size;
}

bool QueueFull(Queue *q){
    return (q->size == MAXQUEUE);
}

int QueueSize(Queue *q){
    return q->size;
}

void ClearQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void TraverseQueue(Queue *q, void (*function) (QueueEntry)){
    int pos,s;
    for(pos=q->front, s=0; s<q->size; s++){
        (*function) (q->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}

#endif