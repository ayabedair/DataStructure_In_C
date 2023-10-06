//
// Created by Aya Bedair on 24/09/2023.
//

#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

void IntializeStack(Stack *ps){
    ps->top = 0; //the index of the first place available
}

//before using check if the stack is not full
void Push(StackEntry element, Stack *ps){
    ps->entry[ps->top++] = element;
}
//returns the last element then pops it
void Pop(StackEntry *element, Stack *ps){
    *element = ps->entry[--ps->top];
}

bool StackFull(Stack *ps){
    return ps->top >= MAXSTACK;
}

bool StackEmpty(Stack *ps){
    return ps->top <= 0;
}

void StackTop(StackEntry *element, Stack *ps){
    *element = ps->entry[ps->top-1];
}

int StackSize(Stack *ps){
    return ps->top;
}

void ClearStack(Stack *ps){
    ps->top = 0;
}

void TraverseStack(Stack *ps, void (*function)(StackEntry element)){
    for(int i=ps->top; i>0; i--)
        (*function)(ps->entry[i-1]);
}