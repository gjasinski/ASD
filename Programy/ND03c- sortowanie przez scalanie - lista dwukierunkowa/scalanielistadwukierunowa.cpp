#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{
    int key;
    node *next;
    node *prev;
};
void mergesort(node *head);

int main()
{
    srand(time(NULL));
    node *head=new node;    //stworzenie listy dwukierunkowej i postawienie straznika
    node *tmp, *i, *tail;
    i=head;
    head->prev=NULL;
    for(int j=0;j<100;j++)  //wypelnienie listy
    {
        tmp=new node;
        tmp->key=rand()%1000;
        cout<<tmp->key<<" ";
        tmp->prev=i;
        i->next=tmp;
        i=tmp;
    }
    tmp=new node;       //straznik na koncu listy
    tmp->prev=i;
    tmp->next=NULL;
    i->next=tmp;
    tail=tmp;
    // tail i head -> wskazniki na straznikow
    cout<<endl<<endl;
    mergesort(head);
/*
    i=head;
    while(i->next->next)
    {
        cout<<i->next->key<<" ";
        i=i->next;
    }
    cout<<endl<<endl;
    i=tail;
    while(i->prev->prev)
    {
        cout<<i->prev->key<<" ";
        i=i->prev;
    }*/
    return 0;
}
void nserie(node *list, node *s)
{
    node *ptr =list->next;
    if(ptr!=NULL && ptr->next==NULL)
    {
        s->next=ptr;
        ptr->prev=s;
        ptr->next=NULL;
        list->next=NULL;
        return;
    }
    while(ptr!=NULL && ptr->next!=NULL && ptr->key<=ptr->next->key)
    {
        ptr=ptr->next;
    }
    s->next=list->next;
    list->next=ptr->next;
    s->next->prev=s;
    list->next->prev=list;
    ptr->next=NULL;
    return;
}

node *mergeseries(node *s1, node *s2, node *append_to)
{
    node * ptr;
    ptr=append_to;
    node *tmp;

    while(s1->next!=NULL && s2->next!=NULL)
    {
        if(s1->next<s2->next)
        {
            tmp=s1->next;
            tmp->prev=ptr;
            ptr=tmp;
            s1->next=s1->next->next;
            //nie ustawiam prev w tym miejscu, dla listy s1/s2 poniewaz w tej funkcji tego nie uzywam
            //ale dla ptr jest ustawiane
            /*ptr->next=s1->next;
            s1->next->prev=ptr;
            ptr=ptr->next;
            s1->next=s1->next->next;
            s1->next->prev=s1;*/
        }
        else
        {
            tmp=s2->next;
            tmp->prev=ptr;
            ptr=tmp;
            s2->next=s1->next->next;

            /*ptr->next=s2->next;
            s2->next->prev=ptr;
            ptr=ptr->next;
            s2->next=s2->next->next;
            s2->next->prev=s2;*/
        }
    }
    /*if(s1->next!=NULL)
    {
        ptr->next=s1->next;
        s1->next->prev=ptr;
        s1->next=NULL;
    }
    while(s2->next!=NULL)
    {
        ptr->next=s2->next;
        s2->next->prev=ptr;
        s2->next=NULL;
    }
    while(ptr->next!=NULL) ptr=ptr->next;*/
    return ptr;
}

void mergesort(node *head)
{
    node *s1=new node;
    node *s2=new node;
    node *h=new node;
    node *end;
    s1->next=NULL;
    s1->prev=NULL;
    s2->next=NULL;
    s1->prev=NULL;
    h->next=NULL;
    h->prev=NULL;
    end=h;
    int n;
    //do
    //{
        n=0;
        //while(head->next!=NULL)
        {
            nserie(head, s1);
            n++;
            if(head->next!=NULL)
            {
                n++;
                nserie(head,s2);
                //end=mergeseries(s1,s2,end);
                mergeseries(s1,s2,end);
            }
            else
            {
                end->next=s1;
                end->next->prev=end;

            }
        }
    node *i=h;
    while(i->next)
    {
        cout<<"OK";
        cout<<i->next->key<<" ";
        i=i->next;
    }
        //head->next=h->next;
        //h->next=NULL;
        //end=h;

    //}while(n>2);
}
/*
void nserie(node *list, node *s)
{
    node *ptr =list->next;
    if(ptr!=NULL and ptr->next==NULL)
    {
        s=ptr;
        list->next=NULL;
        return;
    }
    while(ptr!=NULL and ptr->next!=NULL and ptr->key<=ptr->next->key)
    {
        ptr=ptr->next;
    }
    s->next=list->next;
    list->next=ptr->next;
    ptr->next=NULL;
}

node *mergeseries(node *s1, node *s2, node *append_to)
{
    node *end = append_to;
    node *res;
    while(s1->next!=NULL and s2->next!=NULL)
    {
        if(s1->next->key>=s2->next->key)
        {
            end->next=s2->next;
            end=end->next;
            s2->next=s2->next->next;
            end->next=NULL;
        }
        else
        {
            end->next=s1->next;
            end=end->next;
            s1->next=s1->next->next;
            end->next=NULL;
        }
    }
    if(s1->next!=NULL)
    {
        end->next=s1->next;
        s1->next=NULL;
    }
    if(s2->next!=NULL)
    {
        end->next=s2->next;
        s2->next=NULL;
    }
    while(end->next!=NULL)end=end->next;
    return end;
}

void sortnmsort(node *head)
{
    node *s1 =new node;
    s1->next=NULL;
    node *s2=new node;
    s2->next=NULL;
    node *l=new node;
    l->next=NULL;
    node *end;
    end=l;
    int n;
    do
    {
        n=0;
        while(head->next!=NULL)
        {
            nserie(head,s1);
            n++;
            if(head->next!=NULL)
            {
                n++;
                nserie(head,s2);
                end=mergeseries(s1,s2,end);
            }
            else
            {
                end->next=s1->next;
                s1->next=NULL;
            }

        }
        head->next=l->next;
        l->next=NULL;
        end=l;
    }while(n>2);
    delete l;
    delete s1;
    delete s2;
}
*/
