//
// Created by Aya Bedair on 24/09/2023.
//

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

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

/*
 * #include <stdio.h>
#include "stdbool.h"
#include "stack_LinkList.h"

bool IsChar(char c){
    return (c>='A' && c<='Z');
}

bool Precedent(char a, char b){
    if(a == '$')
        return 1;

    if((a == '*') || (a == '/'))
        return (b != '$');

    if((a == '+') || (a == '-'))
        return ((b != '$') && (b != '*') && (b != '/'));

    return 0;
}

void Infix(char infix[], char postfix[])
{
    int c;
    int e;
    int i,j;
    Stack s;
    IntializeStack(&s);
    for(i=0,j=0; (c=infix[i]) != '\0'; i++){
        if(IsChar(c)){
            postfix[j++] = c;
        }
        else{
            if(!StackEmpty(&s)){
                StackTop(&e, &s);
                while(!StackEmpty(&s) && Precedent(e, c)){
                    //returns 1 if op1 is higher than op2
                    Pop(&e, &s);
                    postfix[j++] = e;
                    if(!StackEmpty(&s))
                        StackTop(&e, &s);
                }
            }
            Push(c, &s);
        }
    }
    while(!StackEmpty(&s)){
        Pop(&e, &s);
        postfix[j++] = e;
    }
    postfix[j] = '\0';
}

int main() {

    char arr[100];
    char eqn[100];
    char c;

    printf("Enter the Infix equation:\n");
    for(int i=0; i<100; i++) {
        c = getchar();
        if(c == '\n') {
            eqn[i] = '\0';
            break;
        }
        eqn[i] = c;
    }

    Infix(eqn, arr);

    printf("Postfix equation is:\n");
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++) {
        if(arr[i] == '\0')
            break;
        printf("%c",arr[i]);
    }

    return 0;
}
 */