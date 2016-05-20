#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

struct Vertex{
    int weight;
    int parent;
};

int main() {
    int N, M, x, y, r, S;
    scanf("%d %d", &N, &M);
    int** A = new int*[N];
    Vertex* V= new Vertex[N];
    for(int i=0;i<N;i++) A[i]=new int[N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) A[i][j]=0;
        V[i].parent=0;
        V[i].weight=INT_MAX;
    }
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &r);
        A[x][y]=r;
        A[y][x]=r;
    }
    return 0;
}

void prim()
