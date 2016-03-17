#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node{Node* next; int val;};
struct TwoLists{Node* even;Node* odd;};
TwoLists* split(Node* list);
int main()
{
    srand(time(NULL));
    Node *head=new Node;
    TwoLists *tl;
    Node *tmp, *i;
    i=head;
    for(int j=0;j<100;j++)
    {
        tmp=new Node;
        tmp->val=rand()%1000;
        i->next=tmp;
        i=i->next;
    }
    tl=split(head->next);
    i=tl->even;
    while(i)
    {
        cout<<i->val<<" ";
        i=i->next;
    }
    i=tl->odd;
    cout<<endl;
    while(i)
    {
        cout<<i->val<<" ";
        i=i->next;
    }

}

TwoLists* split(Node* list)
{
    TwoLists *r=new TwoLists;
    r->even=NULL;
    r->odd=NULL;
    if(list==NULL)return r;
    Node *teven, *todd;//tail
    r->even=new Node;
    r->odd=new Node;
    r->even->next=NULL;
    r->odd->next=NULL;
    teven=r->even;
    todd=r->odd;
    while(list!=NULL)
    {
        if(list->val%2==0)
        {
            teven->next=list;
            teven=teven->next;
        }
        else
        {
            todd->next=list;
            todd=todd->next;
        }
        list=list->next;
    }
    teven->next=NULL;
    todd->next=NULL;
    r->even=r->even->next;
    r->odd=r->odd->next;
    return r;
}
void sortString(string A[], int n)
{


}
