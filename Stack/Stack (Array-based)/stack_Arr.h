//
// Created by Aya Bedair on 24/09/2023.
//

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define StackEntry  int
#define MAXSTACK  100

//typedef is used, so we can name the type(struct stack) only using the name Stack
typedef struct stack{
    int top; //refers to the top element(last in)
    /*
     * StackEntry refers to the type of elements in the stack (user level)
     * entry is the stack itself
     * MAXSTACK max number of elements (user level)
     */
    StackEntry entry[MAXSTACK];
}Stack;

void IntializeStack(Stack *ps);
void Push(StackEntry element, Stack *ps);
void Pop(StackEntry *element, Stack *ps);
bool StackFull(Stack *ps);
bool StackEmpty(Stack *ps);
void StackTop(StackEntry *element, Stack *ps);
int StackSize(Stack *ps);
void TraverseStack(Stack *ps, void (*function)(StackEntry element));

#endif //STACK_H_
