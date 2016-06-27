/*
    Solution for https://www.hackerrank.com/challenges/primsmstsub/
    Find MST.
*/
#include <cmath>
#include <cstdio>
#include <climits>
using namespace std;


struct Vertex{
    int* edge;
    int edges;
    int* weight;
    int parent;
};

int prim(Vertex* v, int n, int s);

int main() {
    //Read graph
    int N, M, x, y, r, S;
    scanf("%d %d", &N, &M);
    int** A = new int*[N];
    for(int i=0;i<N;i++) A[i]=new int[N];
    Vertex* v= new Vertex[N];
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++) A[i][j]=-1;
        v[i].parent=-1;
    }
    //save data in matrix
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &r);
        x--;
        y--;
        A[x][y]=r;
        A[y][x]=r;
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
    printf("%d", prim(v, N, S));
    delete v;
    return 0;
}

int minimalWeightVertex(int* w, bool* visited, int n){
    int min_w, min_i;
    min_w=INT_MAX;
    min_i=0;
    for(int i=0;i<n;i++){
        if(!visited[i] && w[i]<min_w){
            min_w=w[i];
            min_i=i;
        }
    }
    return min_i;
}

int prim(Vertex* v, int n, int s){
    int* w = new int[n];
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        w[i]=INT_MAX;
        visited[i]=false;
    }
    w[s]=0;
    int count=0;
    while(count<n){
        int u=minimalWeightVertex(w, visited, n);
        for(int i=0;i<v[u].edges;i++){
            int p=v[u].edge[i];
            if(visited[p]) continue;
            if(w[p]>v[u].weight[i]){
                w[p]=v[u].weight[i];
                v[p].parent=u;
            }
        }
        count++;
        visited[u]=true;
    }
    int mstWeight=0;
    for(int i=0;i<n;i++) mstWeight+=w[i];
    delete w;
    delete visited;
    return mstWeight;
}
