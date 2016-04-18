#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node{
Node *next;
int val;
};
Node *QuickerSort(Node *head);

int main()
{
    srand(time(NULL));
    Node *head=new Node;
    Node *tmp, *i;
    i=head;

    for(int j=0;j<100;j++)
    {
        tmp=new Node;
        tmp->val=rand()%1000;
        i->next=tmp;
        i=i->next;
    }
    i->next=NULL;
    i=head;
    while(i->next)
    {
        cout<<i->next->val<<" ";
        i=i->next;
    }
    cout<<endl<<endl;
    head=QuickerSort(head);
    i=head;
    while(i->next)
    {
        cout<<i->next->val<<" ";
        i=i->next;
    }
    return 0;
}

Node* Merge(Node* l1, Node* l2, Node *l3)
{
    //Wiemy ze:
    //Elementy listy l1<l2<l3
    //i kazdy element l2 jest taki sam
    Node* head;
    if(l1!=NULL)
    {
        head=l1;
        while(l1->next!=NULL)
        {
            l1=l1->next;
        }
        l1->next=l2;
    }
    else head=l2;
    while(l2->next!=NULL)
    {
        l2=l2->next;
    }
    l2->next=l3;
    return head;
}

Node *QuickerSort(Node* head)
{
    //bierzemy pierwszy element
    if(head->next!=NULL or head->next->next)
    {
        Node *l1=new Node;
        Node *l2=new Node;
        Node *l3=new Node;
        Node *t1,*t2,*t3;
        l1->next=NULL;
        l2->next=NULL;
        l2->next=NULL;
        t1=l1;
        t2=l2;//ogony
        t3=l3;
        int v=head->next->val;
        t2->next=head->next;
        t2=t2->next;
        head->next=head->next->next;
        while(head->next!=NULL)
        {
            if(head->next->val==v)
            {
                t2->next=head->next;
                t2=t2->next;
                head->next=head->next->next;
            }
            else
            {
                if(head->next->val<v)
                {
                    t1->next=head->next;
                    t1=t1->next;
                    head->next=head->next->next;
                }
                else
                {
                    t3->next=head->next;
                    t3=t3->next;
                    head->next=head->next->next;
                }
            }
        }
        t1->next=t2->next=t3->next=NULL;

        if(l1->next!=NULL) t1=QuickerSort(l1);
        if(l3->next!=NULL) t3=QuickerSort(l3);
        head->next=Merge(l1->next,l2->next,l3->next);
    }
    return head;
}
