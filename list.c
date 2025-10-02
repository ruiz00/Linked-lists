#include "list.h"

List new_list(void)
{
    return NULL;
}
Bool is_empty_list(List li)
{
    if( li == NULL)
    {
        return true;
    }
    return false;
}
Bool is_empty_Dlist(Dlist li)
{
    if( li == NULL)
    {
        return true;
    }
    return false;
}
void print_list(List li)
{
    if (is_empty_list(li))
    {
        printf("La liste est vide \n");
        return;
    }
    while (li != NULL)
    {
        printf("[%d] ", li->val);
        li=li->next;

    }
    printf("\n");
    
}
void free_slist(List li) {
    while (li != NULL) {
        ListElement *temp = li;
        li = li->next;
        free(temp);
    }
}

List removeOccurence(List li, int x)
{
    if (is_empty_list(li))
    {
        return li;
    }
    ListElement *current =li;//utilisee pour parcourir la liste
    ListElement *prev =NULL;// utilise pour garder l'adresse du noeud precedent current  initialise a null cas au debut ill n'a pas de precedant


    while (current != NULL && current ->val == x)
    {
        ListElement *temp =current;// on conserve le premier noeud pour pouvoir le liberer a la fin
        current =current ->next;
        free(temp);
    }
    /*tant que current n'est pas null et que sa valeur est egal a x on doit supprimer ces cases
    cette boucle gere le cas ou les premier cellules contienne la valeur a supprimer */



    li= current;// on fais la mise a jour du debut de la liste
    while (current != NULL)
    {
        if (current -> val == x)
        {
            ListElement *temp = current;// on stock le neoud a etre supprimer 
            prev->next = current-> next;// on  relie le noeud precedent a celui aui suit current en ignorant le current actuel
            current = current ->next; // mettre current sur le noeud suivant et free temp 
            free(temp);
        }
        else
        {
            prev=current; // on avance precedant pour qu'il devienne le noeud precedant de la future position de current
            current =current->next;//on avance current
        }
        
    }
    return li; // la tete de la liste 
    
   
}
List sortedInsert(List li , int x)
{
    ListElement *new= malloc(sizeof(ListElement));
    if (new == NULL)
    {
        printf("Erreur d'allocation dynamique \n");// on verifies si l'allocation memoire c'est bien passee
        exit(1);
    }
    new->val = x;

    if (is_empty_list(li) || x <= li->val)
    {
        new->next=li;
        return new;
        // si la liste est vide ou si le premier element est plus grand que x on fait pointer
        // new sur la liste actuelle et on retourne new comme nouvelle tete
    }
    
    ListElement *current=li;// current est utilise pour parcourir la liste 

    while (current ->next != NULL && current->next->val < x )
    {
        current = current ->next;
        // on avance avec current tant que la liste n'est pas vide et aue la sa valeur est 
        // inferieure a la valeur de x
    }
    
    new->next =current->next;// qund on trouve le bon endroit ou inserer le new node on relie new entre current
    // et current-> next  et ensuite on retourne la liste complete 
    current -> next =new;
    return li;
}
List pushfront(List li,int x)
{
    ListElement *new = malloc(sizeof(ListElement));
    if(new == NULL)
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    new->val= x;
    if (is_empty_list(li))
    {
        new->next=NULL; // si la liste est vide on retourne juste le nouvelle element creer 
        return new;
    }
    // sinon on mets le next de element creer a tout le reste de la liste
    new->next = li;
    return new;
    
}
List pushback(List li ,int x)
{
    ListElement *new = malloc(sizeof(ListElement));
    if(new == NULL)
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    new->val= x;
    new->next=NULL;
    // on ajoute la valeur de x a element qu'on viens de creer et comme on ajoute en fin de liste l'element suivant est NULL

    if (is_empty_list(li))
    {
        return new;// dans le cas ou la liste est vide on retourne juste l'element
    }

    ListElement *current =li;// un variable pour iterer sur la liste sans bouger le pointeur li de la liste 

    while (current->next != NULL)
    {
        current = current->next;// on utilise la boucle pour deplacer le pointeur jusqu'a la fin de la liste
    }
    current->next = new;// on fait pointer le dernier elelment precedent de la liste a la nouveau dernier element
    return li;

    
}

List popfront(List li)
{
    if (is_empty_list(li))
    {
        return new_list();
    }
    
    ListElement *new = malloc(sizeof(ListElement));
    if(new == NULL)
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    new=li->next;// on garde toute la liste sauf le premier element de la liste 
    free(li);
    return new;

}
List popback(List li)
{
    if (is_empty_list(li))
    {
        return new_list();
    }
    
    if (li->next == NULL)
    {
        free(li);// si la liste contient juste un element on peut faire un free de toute la liste
        return new_list();
    }
    

    ListElement *temp = li;
    ListElement *before =li; 

    while (temp-> next != NULL)
    {
        before = temp;// before sert a garder element juste avant la temp
        temp= temp->next;
    }
    before->next =NULL;
    free(temp);
    return li;
    
}

/* liste doublement chainee*/


void print_dlist(Dlist li) {
    printf("Liste doublement chaînée: ");
    DListNode *cur = li->begin;
    while (cur != NULL) {
        printf("[%d] ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
void free_dlist(Dlist li) {
    DListNode *cur = li->begin;
    while (cur != NULL) {
        DListNode *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(li); // libère la structure DList elle-même
}

Dlist sortedDinsert(Dlist li , int x)
{
    DListNode *new = malloc(sizeof(DListNode));
    if (! new)
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    new->val =x;
    new->next=NULL;
    new-> prev =NULL;

    if (li->begin == NULL)
    {
        li->begin = new;
        li->end = new;
        return li;
    }
    
    if(x <= li->begin->val)
    {
        new->next = li->begin;
        li->begin->prev = new;
        li->begin = new;
    }
    DListNode *current = li->begin;
    while (current ->next != NULL && current ->next ->val < x)
    {
        current = current ->next;
    }
    
    if (current->next == NULL)
    {
        current->next =new;
        new->prev = current;
        li->end= new;
    }
    else{
        new->next =current -> next;
        new->prev =current;
        current->next -> prev = new;
        current-> next =new;
    }
    
    return li;
    /* on gere 3 cas 
        liste vide le new node devint le begin et le end
        insertion avant le premier element dont on fait la mise de begin
        insertion au milieu ou a la fin , on parcourt puis on met a jour next et prev 
        on maintient la liste triee grace a la boucle while aio avance tant que la valeur suivante est plus petite
    */

}
Dlist pushfrontD(Dlist li,int X)
{
    DListNode *element = malloc(sizeof(*element));
    if (element == NULL )
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    element->val=X;
    element->next=NULL;
    element->prev=NULL;
    
    if (is_empty_Dlist(li))
    {
        li = malloc(sizeof(*li));
        if(li  == NULL )
        {
            printf("Erreur d'allocation memoire \n");
            exit(1);
        }
        li->begin= element;
        li->end=element ;
        return li;
    }
    li->begin ->prev = element;
    element->next = li->begin;
    li->begin = element;
    return li;
    /*il faut gerer 2 cas , liste vide et liste non vide
    si la liste est vide on alloue un espace memoire pour la structure de la liste
    */
    /*si la liste n'est pas vide on insere l'element au debut en modifiant les pointeurs*/
    /*element->next = li->begin;*/
    /*li->begin->prev = element;*/
    /*li->begin = element;*/
    /*return li;*/
    

    
    
}
Dlist pushbackD(Dlist li, int x)
{

    DListNode *element = malloc(sizeof(*element));
    if (element == NULL )
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    element->val=x;
    element->next=NULL;
    element->prev=NULL;
    if (is_empty_Dlist(li))
    {
        li = malloc(sizeof(*li));
        if(li  == NULL )
        {
            printf("Erreur d'allocation memoire \n");
            exit(1);
        }
        li->begin= element;
        li->end=element ;
    }
    else
    {
        li->end ->next = element;
        element->prev = li->end;
        li->end = element;
        

    }
    return li;

}
Dlist popbackD(Dlist li)
{

    if (is_empty_Dlist(li))
    {
        printf("la liste est vide rein a supprimer \n");
        return NULL;
    }
    if (li ->begin == li->end)
    {
        free(li);
        return NULL;
    }
    DListNode *temp = li->end; 
    li->end = li->end ->prev;
    li->end ->next = NULL;
    temp ->next = NULL;
    temp->prev = NULL;
    free(temp);
    return li;
    

}
Dlist popfrontD(Dlist li)
{
    if (is_empty_Dlist(li))
    {
        printf("la liste est vide rein a supprimer \n");
        return NULL;
    }
    if (li ->begin == li->end)
    {
        free(li);
        return NULL;
    }
    DListNode *temp = li->begin; 
    li->begin = li->begin->next;
    li->begin ->prev = NULL;
    temp ->next = NULL;
    temp->prev = NULL;
    free(temp);
    return li;
}
/*    liste chainee simplement circulaire*/

void print_cslist(Clist li) {
    if (li == NULL) {
        printf("Liste circulaire simple vide\n");
        return;
    }
    printf("Liste circulaire simple: ");
    CListNode *cur = li;
    do {
        printf("%d ", cur->val);
        cur = cur->next;
    } while (cur != li);
    printf("(retour au début)\n");
}
void free_cslist(Clist li) {
    if (li == NULL) return;
    CListNode *cur = li->next;
    while (cur != li) {
        CListNode *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(li);
}


Clist insertFront(Clist li,int x)
{
    CListNode *new=malloc(sizeof(CListNode));
    if (!new)
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    new->val=x;
    if (li == NULL)
    {
        new->next=new;
        return new;
    }
    CListNode *last=li;
    while (last->next != li)
    {
        last = last->next;
    }
    new->next = li;//lie le nouveau noeyd a l'ancienne tete
    last->next=new;//modifie le dernier nœud pour qu'il pointe sur la nouvelle tête .c'est ce qui conserve la circularité.
    return new;// la nouvelle tete est retournee
    /*last commence a la tete li
    la boucle avance jusqu'q trouver le noeud tel aue last->next == li c'est le dernier noeud
    dans une liste circulaire
    new->next=li 
    */

    
}
Clist insertqueue(Clist li ,int x)
{
    CListNode *new= malloc(sizeof(CListNode));
    if (!new)
    {
        printf("Erreur d'allocation memoire \n");
        exit(1);
    }
    new->val=x;
    if (li == NULL)
    {
        new->next =new;
        return new;
    }
    CListNode *last = li;
    while (last -> next != li)
    {
        last = last->next;
    }
    last->next =new;// place new apres l'ancien dernier 
    new-> next=li;// ferme la boucle en faisant pointer le nouveau dernier vers la tete li
    return li;

}
/* liste doublement chainee circulaire*/


void print_cdlist(CDList li) {
    if (li == NULL) {
        printf("Liste circulaire double vide\n");
        return;
    }
    printf("Liste circulaire double: ");
    CDListNode *cur = li;
    do {
        printf("%d ", cur->val);
        cur = cur->next;
    } while (cur != li);
    printf("(retour au début)\n");
}
void free_cdlist(CDList li) {
    if (li == NULL) return;
    CDListNode *cur = li->next;
    while (cur != li) {
        CDListNode *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(li);
}

CDList insertDCfront(CDList li , int x)
{
    CDListNode *new = malloc(sizeof(CDListNode));
    if (!new) {
        printf("Erreur allocation mémoire\n");
        exit(1);
    }
    new->val = x;

    if (li == NULL) {
        // Liste vide le nœud pointe sur lui-même
        new->next = new;
        new->prev = new;
        return new;
    }

    // Le dernier nœud est li->prev car circulaire
    CDListNode *last = li->prev;

    new->next = li;
    new->prev = last;
    li->prev = new;
    last->next = new;

    return new; // nouveau nœud devient la tête
}
CDList insertDCqueue(CDList li , int x)
{
    CDListNode *new = malloc(sizeof(CDListNode));
    if (!new) {
        printf("Erreur allocation mémoire\n");
        exit(1);
    }
    new->val = x;
    if(li == NULL)
    {
        new-> next = new;
        new->prev= new;
        return new;
    }
    CDListNode *last=li->prev;
    new->next = li;
    new->prev=last;
    last->next=new;
    li->prev = new;
    return li;

}
