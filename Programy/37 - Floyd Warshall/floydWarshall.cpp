/*
    Solution for https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

int** floydWarshall(int** A, int n);

int main() {
    int N, M, x, y, r, Q;
    scanf("%d %d", &N, &M);
    int** A = new int*[N];
    int** D;
    for(int i=0;i<N;i++) A[i]=new int[N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)A[i][j]=INT_MAX;
    //read data;
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &x, &y, &r);
        x--;
        y--;
        A[x][y]=r;
    }
    D=floydWarshall(A,N);
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        scanf("%d %d", &x, &y);
        x--;
        y--;
        int tmp=D[x][y];
        if(tmp==INT_MAX)printf("-1\n");
            else printf("%d\n", tmp);
    }
    for (int i=0; i<N; i++){
        delete A[i];
        delete D[i];
    }
    delete A;
    delete D;
    return 0;
}

int** floydWarshall(int** A, int n){
    int** D = new int*[n];
    for(int i=0; i<n; i++)D[i]=new int[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            D[i][j]=A[i][j];
        }
    }
    int a;
    for(int t=0; t<n; t++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a=D[i][t] + D[t][j];
                if(D[i][t]>0 && D[t][j]>0 && a<0) continue; //overflow protection
                D[i][j]=min(D[i][j], a);
            }
        }
    }
    return D;
}
