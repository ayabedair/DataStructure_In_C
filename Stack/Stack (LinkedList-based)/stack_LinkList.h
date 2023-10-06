//
// Created by Aya Bedair on 24/09/2023.
//
#ifndef STACK_H_
#define STACK_H_

#define StackEntry   int

typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;

}StackNode;

typedef struct stack
{
    StackNode *top;
    int size;
}Stack;

void IntializeStack(Stack *ps);
int Push(StackEntry element, Stack *ps);
void Pop(StackEntry *element, Stack *ps);
void StackTop(StackEntry *element, Stack *ps);
bool StackEmpty(Stack *ps);
bool StackFull(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps, void (*function)(StackEntry element));
int StackSize(Stack *ps);

#endif