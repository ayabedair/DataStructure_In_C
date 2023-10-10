//
// Created by Bedir on 08/10/2023.
//
#include <stdbool.h>
#include "../Global.h"

#define LINKED_STACK

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
int Push(StackEntry element, Stack *);
void Pop(StackEntry *, Stack *);
bool StackFull(Stack *);
bool StackEmpty(Stack *);
void StackTop(StackEntry *, Stack *);
int StackSize(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));
