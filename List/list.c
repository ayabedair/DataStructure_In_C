//
// Created by Aya Bedair on 10/10/2023.
//
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "list.h"

#ifdef LINKED_LIST

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

void InitializeList(List* pl){
    pl->head = NULL;
    pl->current = NULL;
    pl->size = 0;
    pl->currentpos = 0;
}

bool ListEmpty(List* pl){
    return !pl->size;
}

bool ListFull(List* pl){
    return 0;
}

int ListSize(List* pl){
    return pl->size;
}

void DestroyList(List* pl){
    ListNode *q;
    while(pl->head){
        q = pl->head->next;
        free(pl->head);
        pl->head = q;
    }
    pl->size = 0;
}

int InsertList(int position, ListEntry element, List* pl){
    ListNode *p, *q;
    int i;
    p = (ListNode *) malloc(sizeof (ListNode));
    if(p){
        p->entry = element;
        p->next = NULL;

        if(position == 0){
            p->next = pl->head;
            pl->head = p;
            pl->currentpos = 0;
            pl->current = pl->head;
        }
        else{
            if(position <= pl->currentpos){
                pl->currentpos = 0;
                pl->current = pl->head;
            }
            for(; pl->currentpos != position-1; pl->currentpos++)
                pl->current = pl->current->next;
            p->next = pl->current->next;
            pl->current->next = p;
        }
        pl->size++;
        return 1;
    }
    else
        return 0;

}

void DeleteList(int position, ListEntry* element, List* pl){
    int i;
    ListNode *q, *tmp;

    if(position == 0){
        *element = pl->head->entry;
        pl->current = pl->head->next;
        free(pl->head);
        pl->head = pl->current;
        pl->currentpos = 0;
    }
    else{
        if(position <= pl->currentpos){
            pl->currentpos = 0;
            pl->current = pl->head;
        }
        for(; pl->currentpos != position-1; pl->currentpos++)
            pl->current = pl->current->next;
        *element = pl->current->next->entry;
        tmp = pl->current->next->next;
        free(pl->current->next);
        pl->current->next = tmp;
    }
    pl->size--;
}

void TransverseList(List* pl, void (*visit) (ListEntry)){
    ListNode *p = pl->head;
    while(p){
        (*visit) (p->entry);
        p = p->next;
    }
}

void RetrieveList(int position, ListEntry* element, List* pl){
    if(position <= pl->currentpos){
        pl->currentpos = 0;
        pl->current = pl->head;
    }
    for( ; pl->currentpos < position ; pl->currentpos++)
        pl->current = pl->current->next;
    *element = pl->current->entry;
}

void ReplaceList(int position, ListEntry element, List* pl){
    if(position <= pl->currentpos){
        pl->currentpos = 0;
        pl->current = pl->head;
    }
    for( ; pl->currentpos < position ; pl->currentpos++)
        pl->current = pl->current->next;
    pl->current->entry = element;
}

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

void InitializeList(List* pl){
    pl->size = 0;
}

bool ListEmpty(List* pl){
    return !pl->size;
}

bool ListFull(List* pl){
    return pl->size == MAXLIST;
}

int ListSize(List* pl){
    return pl->size;
}

void DestroyList(List* pl){
    pl->size = 0;
}

// 0 <= position <= size
int InsertList(int position, ListEntry element, List* pl){
    int i;
    for(i = position ; i <= pl->size-1 ; ++i){
        pl->entry[i+1] = pl->entry[i];
    }
    pl->entry[position] = element;
    pl->size++;
    return 1;
}

// 0 <= position <= size-1 && !ListEmpty
void DeleteList(int position, ListEntry* element, List* pl){
    int i;
    *element = pl->entry[position];
    for(i = position+1 ; i <= pl->size-1 ; ++i){
        pl->entry[i-1] = pl->entry[i];
    }
    pl->size--;
}

void TransverseList(List* pl, void (*visit) (ListEntry)){
    int i;
    for(i = 0 ; i < pl->size ; ++i){
        (*visit) (pl->entry[i]);
    }
}

void RetrieveList(int position, ListEntry* element, List* pl){
    *element = pl->entry[position];
}

void ReplaceList(int position, ListEntry element, List* pl){
    pl->entry[position] = element;
}

#endif
