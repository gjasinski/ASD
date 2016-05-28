/*
    Tested on https://www.hackerrank.com/challenges/dijkstrashortreach
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

struct Vertex{
    int d;
    int parent;
    int* edge;
    int edges;
    int* weight;
};
void printShortestPathes(Vertex* G, int n, int S);
void bellmanFord(Vertex* v, int n, int s);

int main() {
    int T,N, M, x, y, r, S;
    scanf("%d", &T);
    for(int ti=0;ti<T;ti++){
        scanf("%d %d", &N, &M);
        Vertex* v = new Vertex[N];
        int** A = new int*[N];
        for(int i=0;i<N;i++) A[i]=new int[N];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)A[i][j]=-1;

        //read data;
        for(int i=0;i<M;i++){
            scanf("%d %d %d", &x, &y, &r);
            x--;
            y--;
            if(A[x][y]>r || A[x][y]==-1){// for duplicate edges
                A[x][y]=r;
                A[y][x]=r;
            }
        }

        //convert data from matrix to lists
        for(int i=0;i<N;i++){
            int c=0;
            for(int j=0;j<N;j++) if(A[i][j]!=-1)c++;
            v[i].edge = new int[c];
            v[i].weight = new int [c];
            v[i].edges = c;
            c=0;
            for(int j=0;j<N;j++){
                if(A[i][j]!=-1){
                    v[i].edge[c]=j;
                    v[i].weight[c]=A[i][j];
                    c++;
                }
            }
            delete A[i];
        }
        delete A;
        scanf("%d", &S);
        S--;
        bellmanFord(v,N,S);
        printShortestPathes(v,N,S);
        delete v;
    }
    return 0;
}

void bellmanFord(Vertex* v, int n, int s){
    for(int i=0; i<n; i++){
        v[i].d=INT_MAX;
        v[i].parent=-1;
    }
    v[s].d=0;
    for(int j=0; j<n; j++){
        if(j==s)continue;
        for(int i=0; i<n;i++){
            for(int e=0; e<v[i].edges; e++){
                int d=v[i].edge[e];
                if(v[i].d + v[i].weight[e]<v[d].d){
                    if(v[i].d>0 && v[i].weight[e]>0 && (v[i].d+v[i].weight[e]<0))continue; //overflow protection
                    v[d].d=v[i].d+v[i].weight[e];
                    v[d].parent=i;
                }
            }
        }
    }
    for(int i=0;i<n; i++){
        for(int e=0; e<v[i].edges; e++){
            int d=v[i].edge[e];
            if(v[i].d + v[i].weight[e]<v[d].d){
                if(v[i].d>0 && v[i].weight[e]>0 && (v[i].d+v[i].weight[e]<0))continue; //overflow protection
                printf("CYKL UJEMNY");
                return;
            }
        }
    }
}


void printShortestPathes(Vertex* G, int n, int S){
    for(int i=0;i<n;i++){
        if(i==S)continue;
        if(G[i].d==INT_MAX)printf("-1 ");
            else printf("%d ", G[i].d);
    }
    printf("\n");
}
