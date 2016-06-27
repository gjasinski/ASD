#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

struct Vertex{
    int val;
    int* edge;
    int edges;
};

void findArticulationPoints(Vertex* V, int n);

int main(){
    int n=5;
    Vertex* V= new Vertex[n];
    V[0].edges=2;
    V[0].edge = new int[2];
    V[0].edge[0]=1;
    V[0].edge[1]=4;

    V[1].edges=4;
    V[1].edge = new int[4];
    V[1].edge[0]=0;
    V[1].edge[1]=2;
    V[1].edge[2]=3;
    V[1].edge[3]=4;

    V[2].edges=2;
    V[2].edge = new int[2];
    V[2].edge[0]=3;
    V[2].edge[1]=1;

    V[3].edges=2;
    V[3].edge = new int[2];
    V[3].edge[0]=2;
    V[3].edge[1]=1;

    V[4].edges=2;
    V[4].edge = new int[2];
    V[4].edge[0]=1;
    V[4].edge[1]=0;
    findArticulationPoints(V, n);
}

void dfs(Vertex* V, bool* visited, int n, int i){
    visited[i]=true;
    for(int j=0; j<V[i].edges; j++){
        if(!visited[V[i].edge[j]]) dfs(V, visited, n, V[i].edge[j]);
    }
}

//find articulation points O(V(E+V))
void findArticulationPoints(Vertex* V, int n){
    int tmp;
    bool visited[n];
    for(int i=0; i<n; i++) visited[i]=false;
    tmp=V[0].edges;
    dfs(V, visited, n, 1);
    for(int i=1; i<n; i++){
        if(!visited[i]){
            printf("%d ", i);
            break;
        }
    }
    V[0].edges=tmp;
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++) visited[j]=false;
        tmp=V[i].edges;
        V[i].edges=0;
        dfs(V, visited, n, 0);
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(!visited[j]){
                printf("%d ", i);
                break;
            }
        }
        V[i].edges=tmp;
    }
}
