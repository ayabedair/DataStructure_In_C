//
// Created by Aya Bedair on 02/10/2023.
//
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "Queue.h"

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