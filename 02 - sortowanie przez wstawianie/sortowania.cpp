//wszystkie listy sa z straznikiem

#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

struct node{
    int key;
    node *next;
};


void minmax(int A[], int n, int &maks, int &min);

int main(){
    const int n=100;
    int A[n];
    srand(time(NULL));
    for(int i=0;i<n;i++){
        A[i]=rand()%1000;
        cout<<A[i]<<" ";
    }
    int min, maks;
    minmax(A,n,maks, min);
    cout<<endl<<min<< "  "<<maks;
}


void insert(node* list, node* e){
    while(list->next!=NULL and list->next->key<e->key){
        list=list->next;
    }
    list->next=e;
}

node* removeMax(node* list){
    node *tmp=list;
    while(list->next!=NULL){
        if(list->next->key>=tmp->next->key)
        //if(list->next->key>tmp->next->key) werjsja niestablina
            tmp=list;
    }
    node *r;
    r=tmp->next;
    tmp->next=r->next;
    r->next=NULL;
    return r;
}

node* inertsort(node* list){
    node *tmp;
    node *sorted = new node;
    sorted->next=NULL;
    while(list->next!=NULL){
        tmp=list->next;
        list->next=list->next;
        tmp->next=NULL;
        insert(sorted, tmp);
    }
    delete list;
    return sorted;
}

node* ssort(node* list){
    node *tmp;
    node *sorted=new node;
    sorted->next=NULL;
    while(list->next!=NULL){
        tmp=removeMax(list);
        tmp->next=sorted->next;
        sorted->next=tmp;
    }
    delete list;
    return sorted;
}

void minmax(int A[], int n, int &maks, int &min){
    min=INT_MAX;
    maks=INT_MIN;
    int i,j;
    i=0;
    j=n-1;
    do{
        if(A[i]<A[j]){
            if(min>A[i]) min=A[i];
            if(maks<A[j])maks=A[j];
        }
        else{
            if(min>A[j])min=A[j];
            if(maks<A[i])maks=A[i];
        }
        i++;
        j--;
    }while(i<j);
}
