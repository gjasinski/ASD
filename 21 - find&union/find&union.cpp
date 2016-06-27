#include<iostream>

using namespace std;

/*

Wersja listowa

struct set;

struct node{
    set* R;
    node* next;
    int val;
};

struct set{
    node* head;
    node* tail;
    int length;
};

set* findSet(Node* e){
    return e->R;
}

set* makeSet(int val){
    set *S=new set;
    node* n=new node;
    n->R=S;
    n->val=val;
    s->head=n;
    s->tail=n;
    return s;
}

*/

//Las zbiorow rozlacznych

struct node{
    node* parent;
    int rank;
    int val;
};

node* makeSet(int val){
    node* s=new node;
    s->val=val;
    s->parent=s;
    s->rank=0;
    return s;
}

//Bez kompresji sciezki
node* findSet1(node* x){
    if(x->parent!=x){
        return findSet(x->parent);
    }else
        return x;
}

//Kompresja sciezki
node* findSet2(node* x){
    if(x->parent!=x){
        node* y=findSet(x->parent);
        x->parent=y;
        return y;
    }else
        return x;
}

void union(node* x, node* y){
    node* Rx = findSet1(x);
    node* Ry = findSet1(y);
    if(Rx->rank>Ry->rank){
        Ry->parent=Rx;
    }else{
        Rx->parent=Ry;
        if(Rx->rank==Ry->rank) Ry->rank++;
    }
}
