//
// Created by Bedir on 08/10/2023.
//

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#ifdef LINKED_STACK

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

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

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

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

#endif