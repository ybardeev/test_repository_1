#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <errno.h>

typedef struct intlistnode
{
    int elem;
    struct intlistnode *next;
} * intlist;

intlist newintlistnode (int newelem, intlist next)
{
    intlist newp=malloc(sizeof(*newp));
    if (newp==NULL)
    {
        exit(EXIT_FAILURE);
    }
    newp->elem=newelem;
    newp->next=next;
    return newp;
}

void freelist (intlist *list)
{
    intlist p;
    for (;*list!=NULL;*list=p)
    {
        p=*list;
        p=p->next;
        free(*list);
    }
}


void addfirst(intlist *plist, int newelem)
{
    *plist=newintlistnode(newelem, *plist);
}


void printlist(intlist list)
{
    for (;list!=NULL;)
    {
        printf("%d ",list->elem);
        list=list->next;
    }
}

void addend(intlist *plist, int newelem)  //добавить в конец
{
    if(*plist==NULL)
    {
        addfirst(plist, newelem);
    }
    else
    {
        intlist p=*plist;
        intlist p1=*plist;
        for (;p!=NULL;)
        {
            p=p->next;
            if (p!=NULL)
            {
                p1=p;
            }
        }
        p1->next=newintlistnode(newelem, NULL);
    }
}

void freefirst(intlist *plist)
{
    intlist list=*plist;
    intlist list2=*plist;
    //printf("%d ",list->elem);
    list=list->next;
    *plist=list;
    free(list2);
}

void freelast (intlist *list)
{
    intlist p=*list;
    intlist p1=*list;
    intlist list1=*list;
    if (list1!=NULL && list1->next==NULL)
    {
        freelist(*list);
        *list=NULL;
        //*list=NULL;
        return 0;
    }
    for (;list1!=NULL;list1=p)
    {
        p=list1->next;
        if (p==NULL)
        {
            p1->next=NULL;
            free(list1);
            break;
        }
       p1=list1;

    }
}



int main()
{
    printf("Hello world!\n");
    intlist a=NULL;
    addend(&a,1);
    addend(&a,2);
    addend(&a,3);
    addend(&a,1);
    addend(&a,2);
    addend(&a,3);

    addfirst(&a,5);
    freelast(&a);
    freefirst(&a);
    freelast(&a);
    printlist(a);
    freelist(&a);
    printlist(a);
    return 0;
}
