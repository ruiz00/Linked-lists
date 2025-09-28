#ifndef __LISTE_H_
#define __LISTE_H_
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
// definition  d'une liste simplement chainee
typedef struct ListElement
{
    int val;
    struct ListElement *next;
}ListElement,*List;
// *list est un pointeur vers une liste (masquqnt le listElement)
typedef struct DListNode
{
    int val;
    struct DListNode *next;
    struct DListNode *prev;
}DListNode; // Noeud d'une Dliste

typedef struct Dlist
{
    struct DListNode *begin;
    struct DListNode *end;

}*Dlist; // definition d'une Dlist 
// defiitioin d'une liste simplement chainee circulaire
typedef struct CListNode
{
    int val;
    struct CListNode *next;
}CListNode, *Clist;


// definition d'une doublement chainee circulaire
typedef struct CDListNode
{
    int val;
    struct CDListNode *next;
    struct CDListNode *prev;
}CDListNode , *CDList;
List new_list(void);
bool is_empty_list(List li);
void print_list(List li);
void free_slist(List li);
List removeOccurence(List li, int x);
List sortedInsert(List li , int x);
void print_dlist(Dlist li);
void free_dlist(Dlist li) ;
Dlist sortedDinsert(Dlist li , int x);
void print_cslist(Clist li);
void free_cslist(Clist li);
Clist insertFront(Clist li,int x);
Clist insertqueue(Clist li ,int x);
void print_cdlist(CDList li);
void free_cdlist(CDList li);
CDList insertDCfront(CDList li , int x);
CDList insertDCqueue(CDList li , int x);




#endif