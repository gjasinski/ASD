/*
    Problem nadluzszego rosnacego podciagu - LIS
    Dane:
        A[0, n-1] - tablica liczb
    Zadanie:
        Obliczyc dlugosc najdluzszego rosnacego podciagu niekoniecznie spojnego.
*/
#include <stdio.h>
#include <cstdio>
int lis(int* A, int n);
void printSolution(int* A, int* P, int i);

int main(){
    int n;
    scanf("%d", &n);
    int* A = new int[n];
    for(int i=0;i<n;i++) scanf("%d", &A[i]);
    printf("%d", lis(A,n));

}
int lis(int* A, int n){
    int F[n];
    int max=0;
    int P[n];
    F[0]=1;
    P[0]=-1;
    for(int i=1; i<n; i++){
        F[i]=1;
        P[i]=-1;
        for(int j=0; j<i; j++){
            if(A[j]<A[i] && F[j]+1>F[i]){
                F[i]=F[j]+1;
                P[i]=j;
            }
        }
        if(F[max]<F[i])max=i;
    }
   // printSolution(A,P,max);
    return F[max];
}

void printSolution(int* A, int* P, int i){
    if(P[i]!=-1){
        printSolution(A,P,P[i]);
        printf("%d ", A[i]);
    }
}
