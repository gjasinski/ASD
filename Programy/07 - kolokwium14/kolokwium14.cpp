#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Node{Node* next; int val;};
struct TwoLists{Node* even;Node* odd;};
TwoLists* split(Node* list);

struct snode{string val;snode* next; };
void sortString(string A[], int n);


int main()
{
    //Zadanie 2
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
    //zadanie 3
    cout<<endl<<endl<<endl;
    string str[10]={"agh", "asd","krakow","wiedzmin","blackout","testowo","grafika","g","dziewiec","wiet"};
    sortString(str,10);
    for(int i=0;i<10;i++) cout<<str[i]<<endl;
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

    snode* B[27];
    snode* C[27];//ogon do B
    for(int i=0;i<27;i++)
    {
        B[i]=new snode;
        B[i]->next=NULL;
        C[i]=B[i];
    }

    snode* list= new snode;
    list->next=NULL;
    snode* tail=list;
    snode* tmp;

    int max_len=0;
    for(int i=0;i<n;i++)
    {
        if(A[i].length()>max_len) max_len=A[i].length();
        tmp=new snode;
        tmp->val=A[i];
        tail->next=tmp;
        tail=tmp;
    }
    tail->next=NULL;
    int x;
    for(int i=max_len-1;i>=0;i--)
    //int i=max_len-1;
    {
        while(list->next!=NULL)
        {
            //rozdzielanie na listy
            if(list->next->val.length()<=i)
            {
                C[0]->next=list->next;
                C[0]=C[0]->next;
                list->next=list->next->next;
            }
            else
            {
                x=list->next->val[i]-96;//bo 0 jest dla krotszych wyrazow
                C[x]->next=list->next;
                C[x]=C[x]->next;
                list->next=list->next->next;
            }
        }
        //laczenie list;

        tail=list;
        for(int i=0;i<27;i++)
        {
            if(B[i]->next!=NULL)
            {
                tail->next=B[i]->next;
                tail=C[i];
                B[i]->next=NULL;
                C[i]=B[i];
            }
        }
        tail->next=NULL;
    }
    int i=0;
    while (list->next!=NULL)
    {
        A[i]=list->next->val;
        list->next=list->next->next;
        i++;
    }
}
