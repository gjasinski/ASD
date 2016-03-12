#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{
    int key;
    node *next;
    node *prev;
};

void sortnmsort(node *head);

int main()
{
    srand(time(NULL));
    node *head=new node;
    node *tmp, *i, *tail;
    i=head;
    head->prev=NULL;
    cout<<head->key<<endl;
    for(int j=0;j<100;j++)
    {
        tmp=new node;
        tmp->key=rand()%1000;
        cout<<tmp->key<<" ";
        tmp->prev=i;
        i->next=tmp;
        i=i->next;
    }
    tmp=new node;
    tmp->prev=i;
    tmp->next=NULL;
    tail=tmp;
    i->next=NULL;
    i=head;
    /*while(i->next)
    {
        cout<<i->next->key<<" ";
        i=i->next;
    }*/
    cout<<endl<<endl;
    //sortnmsort(head);
    i=head;

    while(i->next)
    {
        cout<<i->next->key<<" ";
        i=i->next;
    }
    cout<<endl<<endl;
    i=tail;
    while(i->prev)
    {
        cout<<i->prev->key<<" ";
        i=i->prev;
    }
    return 0;
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
    node *tmp=head;
    node *s1 =new node;
    s1->next=NULL;
    node *s2=new node;
    s2->next=NULL;
    node *l=new node;
    l->next=NULL;
    node *end;
    end=l;
    int n;
    node *i;
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
