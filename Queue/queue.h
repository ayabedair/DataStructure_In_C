//
// Created by Aya Bedair on 02/10/2023.
//

#include <stdbool.h>
#include "../Global.h"

#define LINKED_QUEUE

#ifdef LINKED_QUEUE

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

typedef struct queuenode{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct queue{
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

typedef struct queue{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;

#endif

void InitializeQueue(Queue *);
int Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
bool QueueEmpty(Queue *);
bool QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void (*) (QueueEntry));

