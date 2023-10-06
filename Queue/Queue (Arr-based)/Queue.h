//
// Created by Aya Bedair on 02/10/2023.
//

#ifndef QUEUE_H_
#define QUEUE_H_

#define QueueEntry   int
#define MAXQUEUE     100

typedef struct queue{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;

void InitializeQueue(Queue *q);
void Append(QueueEntry element, Queue *q);
void Serve(QueueEntry *element, Queue *q);
bool QueueEmpty(Queue *q);
bool QueueFull(Queue *q);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q, void (*function) (QueueEntry));

#endif
