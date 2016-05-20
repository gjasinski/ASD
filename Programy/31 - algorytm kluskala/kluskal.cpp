/*
    Solution for https://www.hackerrank.com/challenges/kruskalmstrsub
    Find MST.
*/
#include <cmath>
#include <cstdio>
using namespace std;


struct Vertex{
    int id, rank;
    Vertex* parent;
};

struct Edge{
    int weight;
    Vertex* v1,* v2;
};


void bSort(Edge** e, int n);
Vertex* makeSet(int v);
bool diffrentSets(Vertex* v1, Vertex* v2);
void unionVertices(Vertex* v1, Vertex* v2);
int kluskal(Edge** e, int N , int M);

int main() {
    //Read graph
    int N, M, x, y, r, S;
    scanf("%d %d", &N, &M);
    N++; // Vertices from 1..n
    Edge** e = new Edge*[M];
    Vertex** v = new Vertex*[N];
    for(int i=0;i<N;i++)v[i]=NULL;
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &r);
        if(!v[x]) v[x]=makeSet(x);
        if(!v[y]) v[y]=makeSet(y);
        e[i]=new Edge;
        e[i]->v1=v[x];
        e[i]->v2=v[y];
        e[i]->weight=r;
    }
    printf("%d", kluskal(e, N, M));
    return 0;
}

//Finds MST.
int kluskal(Edge** e, int N , int M){
    bSort(e, M);
    int counter=1;
    int i=0;
    int weight=0;
    while(counter<N && i< M){
        if(diffrentSets(e[i]->v1,e[i]->v2)){
            counter++;
            weight+=e[i]->weight;
            unionVertices(e[i]->v1,e[i]->v2);
        }
        i++;
    }
    return weight;
}

Vertex* makeSet(int v){
    Vertex* vertex= new Vertex;
    vertex->id=v;
    vertex->rank=0;
    vertex->parent=NULL;
    return vertex;
}

Vertex* findSet(Vertex* v){
    if(v->parent!=NULL){
       return findSet(v->parent);
    }
    else
        return v;
}

void unionVertices(Vertex* v1, Vertex* v2){
    Vertex* s1 = findSet(v1);
    Vertex* s2 = findSet(v2);
    if(s1->rank>s2->rank){
        s2->parent=s1;
    }
    else{
        s1->parent=s2;
        if(s1->rank==s2->rank) s2->rank++;
    }

}
bool diffrentSets(Vertex* v1, Vertex* v2){
    return (findSet(v1)!=findSet(v2));
}

void swap(Edge* &e1, Edge* &e2){
    Edge* ptr=e1;
    e1=e2;
    e2=ptr;
}

void bSort(Edge** e,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(e[j]->weight>e[j+1]->weight) swap(e[j], e[j+1]);
        }
    }
}
