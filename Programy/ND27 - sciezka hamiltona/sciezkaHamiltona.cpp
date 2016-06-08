/*
Mamy DAG, sprawdz czy istnieje sciezka hamiltona.

Posortowac topologicznie, nastepenie spradzic?

*/
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

struct Vertex{
    int color;  //0-niepokolorowane
    int* to;
    int edges;
};
int topologicalSort(Vertex* G, int n);
bool hamiltonPath(Vertex* G, int n);

int main(){
    int n=6;
    Vertex* V= new Vertex[n];
    V[0].edges=1;
    V[0].to = new int[1];
    V[0].to[0]=1;

    V[1].edges=1;
    V[1].to = new int[1];
    V[1].to[0]=2;

    V[2].edges=1;
    V[2].to = new int[1];
    V[2].to[0]=3;

    V[3].edges=1;
    V[3].to = new int[1];
    V[3].to[0]=4;

    V[4].edges=1;
    V[4].to = new int[1];
    V[4].to[0]=5;

    for(int i=0;i<n;i++)V[i].color=0;
    if(hamiltonPath(V, n)) printf("OK"); else printf("NO OK");
}

void dfs(Vertex* G, int V, stack <int> &q){
    G[V].color=1;
    for(int i=0;i<G[V].edges;i++){
        if(G[G[V].to[i]].color==0)dfs(G, G[V].to[i], q);
    }
    q.push(V);
}
int topologicalSort(Vertex* G, int n){
    stack <int> q;
    for(int i=0;i<n;i++){
        if(G[i].color==0) dfs(G, i, q);
    }
    return q.top();
}

bool hamiltonPath(Vertex* G, int n){
    stack<int> q;
    int v = topologicalSort(G, n);
    for(int i=0; i<n; i++) G[i].color=0;
    dfs(G, v, q);
    for(int i=0; i<n; i++) if(G[i].color==0) return false;
    return true;
}
