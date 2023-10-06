//
// Created by Aya Bedair on 24/09/2023.
//

#include <stdlib.h>
#include <stdbool.h>
#include "stack_LinkList.h"

void IntializeStack(Stack *ps) {
    ps->top = NULL; 
    ps->size = 0;
}

int Push(StackEntry element, Stack *ps) {
    StackNode *pn = (StackNode*) malloc(sizeof(StackNode));
    if(!pn)
        return 0;
    else{
        pn->entry = element;
        pn->next = ps->top;
        ps->top = pn;
        ps->size++;
    }
}

void Pop(StackEntry *element, Stack *ps) {
    StackNode *pn;
    *element = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);

    ps->size--;
}

void StackTop(StackEntry *element, Stack *ps){
    *element = ps->top->entry;
}

bool StackEmpty(Stack *ps) {
    return ps->top == NULL;
}

bool StackFull(Stack *ps) {
    return 0;
}

void ClearStack(Stack *ps){
    StackNode *pn = ps->top;

    while(pn){
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }

    ps->size = 0;
}

void TraverseStack(Stack *ps, void (*function)(StackEntry element)){
    StackNode *pn = ps->top;

    while(pn){
        (*function)(pn->entry);
        pn = pn->next;
    }
}

int StackSize(Stack *ps){
    return ps->size;
}