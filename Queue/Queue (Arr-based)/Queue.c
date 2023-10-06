//
// Created by Aya Bedair on 02/10/2023.
//
#include "stdbool.h"
#include "Queue.h"

void InitializeQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void Append(QueueEntry element, Queue *q){
    q->rear = (q->rear + 1) % MAXQUEUE;
    q->entry[q->rear] = element;
    q->size++;
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