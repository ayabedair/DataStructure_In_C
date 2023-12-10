//
// Created by Aya Bedair on 10/10/2023.
//

#include "../Global.h"
#include <stdbool.h>
#define LINKED_LIST

#ifdef LINKED_LIST

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
}ListNode;

typedef struct list{
    ListNode *head, *current;
    int size, currentpos;
}List;

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

typedef struct list{
    ListEntry entry[MAXLIST];
    int size;
}List;

#endif

void InitializeList(List*);
bool ListEmpty(List*);
bool ListFull(List*);
int ListSize(List*);
void DestroyList(List*);
int InsertList(int, ListEntry, List*);
void DeleteList(int, ListEntry*, List*);
void TransverseList(List*, void (*visit) (ListEntry));
void RetrieveList(int, ListEntry*, List*);
void ReplaceList(int, ListEntry, List*);