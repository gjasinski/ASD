/*
Jest dana tablica A o n elementach, z zakresu [0,n^2-1].
Posortować
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void prepareTable(int* A, int N);
void radixSort(int* A, int N);
void printArray(int* A, int N);

int main(){
    int n=100;
    int* A=new int [n];
    prepareTable(A, n);
    radixSort(A, n);
    printArray(A,n);
    delete[] A;
}

void prepareTable(int* A, int N){
    srand(time(NULL));
    int mod=N*N;
    for(int i=0; i<N; i++) A[i]=rand()%mod;
}

void radixSort(int* A, int N){
    int *tab=new int [N];
    int *B=new int [N];
    //first sort
    for(int i=0; i<N; i++) tab[i]=0;
    for(int i=0; i<N; i++) tab[A[i]%N]++;
    for(int i=1; i<N; i++) tab[i]+=tab[i-1];
    for(int i=N-1; i>=0; i--) B[--tab[A[i]%N]]=A[i];
    //second sort
    for(int i=0; i<N; i++) tab[i]=0;
    for(int i=0; i<N; i++) tab[B[i]/N]++;
    for(int i=1; i<N; i++) tab[i]+=tab[i-1];
    for(int i=N-1; i>=0; i--) A[--tab[B[i]/N]]=B[i];

    delete[] B;
    delete[] tab;
}

void printArray(int* A, int N){
    for(int i=0; i<N;i++) cout<<i<<" "<<A[i]<<" "<<endl;

}

