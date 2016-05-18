#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

struct Vertex{
    int color;  //0-niepokolorowane
    int* to;
    int edges;
};
void topologicalSort(Vertex* G, int n);

int main(){
    int n=10;
    Vertex* V= new Vertex[n];
    V[0].edges=1;
    V[0].to = new int[1];
    V[0].to[0]=1;

    V[1].edges=2;
    V[1].to = new int[2];
    V[1].to[0]=2;
    V[1].to[1]=5;

    V[2].edges=2;
    V[2].to = new int[2];
    V[2].to[0]=3;
    V[2].to[1]=5;

    V[3].edges=1;
    V[3].to = new int[1];
    V[3].to[0]=9;

    V[5].edges=0;

    V[6].edges=0;

    V[7].edges=2;
    V[7].to = new int[2];
    V[7].to[0]=3;
    V[7].to[1]=8;

    V[8].edges=1;
    V[8].to = new int[1];
    V[8].to[0]=9;

    V[9].edges=0;
    for(int i=0;i<n;i++)V[i].color=0;
    topologicalSort(V, n);
}

void dfs(Vertex* G, int V, stack <int> &q){
    G[V].color=1;
    for(int i=0;i<G[V].edges;i++){
        if(G[G[V].to[i]].color==0)dfs(G, G[V].to[i], q);
    }
    q.push(V);
}
void topologicalSort(Vertex* G, int n){
    stack <int> q;
    for(int i=0;i<n;i++){
        if(G[i].color==0) dfs(G, i, q);
    }
    while(!q.empty()){
        printf("%d ", q.top());
        q.pop();
    }
}
