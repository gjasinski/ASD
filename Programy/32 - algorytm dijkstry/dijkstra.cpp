/*
    Solution for https://www.hackerrank.com/challenges/dijkstrashortreach
    Passed 5/7 test cases
#include <cstdio>
#include <climits>
using namespace std;

struct pathTree{
    int d;
    int parent;
};

int next_candidate(pathTree* pT, bool* vis, int n);
pathTree* dijkstra(int** graph, int n, int start);
void printShortestPathes(pathTree* pT, int n, int S);

int main() {
    int T,N, M, x, y, r, S;
    scanf("%d", &T);
    for(int ti=0;ti<T;ti++){
        scanf("%d %d", &N, &M);
        int** A = new int*[N];
        for(int i=0;i<N;i++) A[i]=new int[N];
        pathTree* pT;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)A[i][j]=-1;
        for(int i=0;i<M;i++){
            scanf("%d %d %d", &x, &y, &r);
            x--;
            y--;
            if(A[x][y]>r || A[x][y]==-1){// for duplicat edges
                A[x][y]=r;
                A[y][x]=r;
            }
        }
        scanf("%d", &S);
        S--;
        pT=dijkstra(A, N, S
        );
        printShortestPathes(pT, N, S);
        for(int i=0;i<N;i++) delete A[i];
        delete A;
        delete pT;
    }
    return 0;
}

pathTree* dijkstra(int** graph, int n, int start){
    pathTree* pT= new pathTree[n];
    bool* vis = new bool[n];
    for(int i=0;i<n;i++){
        pT[i].d=INT_MAX;
        pT[i].parent=-1;
        vis[i]=false;
    }
    pT[start].d=0;
    int num_vis=0;
    while(num_vis<n){
        int u=next_candidate(pT, vis, n);
        for(int i=0;i<n;i++){
            if(graph[u][i]!=-1 && (pT[u].d+graph[u][i])<pT[i].d){
                pT[i].d=pT[u].d+graph[u][i];
                pT[i].parent=u;
            }
        }
        vis[u]=true;
        num_vis++;
    }
    delete []vis;
    return pT;
}

int next_candidate(pathTree* pT, bool* vis, int n){
    int i;
    for(i=0; i<n && vis[i]; i++);
    int min_i=i;
    for(i;i<n;i++){
        if(!vis[i] && pT[i].d<pT[min_i].d) min_i=i;
    }
    return min_i;
}

void printShortestPathes(pathTree* pT, int n, int S){
    for(int i=0;i<n;i++){
        if(i==S)continue;
        if(pT[i].d==INT_MAX)printf("-1 ");
            else printf("%d ", pT[i].d);
    }
    printf("\n");
}
