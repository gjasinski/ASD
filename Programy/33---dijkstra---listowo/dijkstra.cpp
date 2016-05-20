/*
    Solution for https://www.hackerrank.com/challenges/dijkstrashortreach
    List representation.
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Vertex{
    int d;
    int parent;
    int* edge;
    int edges;
    int* weight;
};

struct pqNode{
    int v;
    int weight;
};

struct Comp{
    bool operator()(const pqNode& a, const pqNode& b){
        return a.weight<b.weight;
    }
};

void dijkstra(Vertex* G, int n, int s);
void printShortestPathes(Vertex* G, int n, int S);

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
        dijkstra(v, N, S);
        printShortestPathes(v, N, S);
        delete v;
    }
    return 0;
}

void dijkstra(Vertex* G, int n, int s){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        G[i].d=INT_MAX;
        G[i].parent=-1;
        visited[i]=false;
    }
    priority_queue< pqNode, vector<pqNode>, Comp> pq;
    G[s].d=0;
    pqNode node;
    node.v=s;
    node.weight=G[s].d;
    pq.push(node);
    while(!pq.empty()){
        node=pq.top();
        pq.pop();
        int u=node.v;
        //if(visited[u])continue;   //na cwiczeniach zaimplementowane z tymi dwoma wierszami
        //visited[u]=true;          // jednak program dziala niepoprawnie z nimi
        for(int i=0;i<G[u].edges;i++){
            int p=G[u].edge[i];
            if(G[u].d+G[u].weight[i]<G[p].d){
                G[p].d=G[u].d+G[u].weight[i];
                G[p].parent=u;
                node.v=p;
                node.weight=G[p].d;
                pq.push(node);
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
