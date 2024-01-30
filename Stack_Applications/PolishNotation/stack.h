//
// Created by Bedir on 08/10/2023.
//
#include <stdbool.h>
#include "Global.h"

//#define MAXSTACK     100
//#define EVALUATEPOSTFIX

//#ifdef EVALUATEPOSTFIX
//#define StackEntry   double
//#else
//#define StackEntry   char
//#endif

#ifdef LINKED_STACK

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

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

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

typedef struct stack{
    int top; //refers to the top element(last in)
    /*
     * StackEntry refers to the type of elements in the stack (user level)
     * entry is the stack itself
     * MAXSTACK max number of elements (user level)
     */
    StackEntry entry[MAXSTACK];
}Stack;

#endif

void IntializeStack(Stack *);
void Push(StackEntry element, Stack *);
void Pop(StackEntry *, Stack *);
bool StackFull(Stack *);
bool StackEmpty(Stack *);
void StackTop(StackEntry *, Stack *);
int StackSize(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));
