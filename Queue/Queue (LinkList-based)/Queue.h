//
// Created by Aya Bedair on 02/10/2023.
//

#ifndef QUEUE_H_
#define QUEUE_H_

#define QueueEntry  int

typedef struct queuenode{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct queue{
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;

void InitializeQueue(Queue *q);
int Append(QueueEntry element, Queue *q);
void Serve(QueueEntry *element, Queue* q);
bool QueueEmpty(Queue *q);
bool QueueFull(Queue *q);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q, void (*function) (QueueEntry));

#endif
