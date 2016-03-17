#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void countsort(int tab[], int n, int k);
int main()
{
    int MAX_SIZE=20;
    int tab[MAX_SIZE];
    int k=10;
    srand(time(NULL));
    for(int i=0;i<MAX_SIZE;i++)
    {
        tab[i]=rand()%k;
    }
    for(int i=0;i<20;i++)cout<<tab[i]<<" ";
    cout<<endl;
    countsort(tab,MAX_SIZE,k);
    cout<<endl;
    for(int i=0;i<20;i++)cout<<tab[i]<<" ";
}

void countsort(int A[], int n, int k)
{
    int *B=new int[n];
    int *C=new int[k];
    for (int i=0;i<k;i++)
    {
        C[i]=0;
    }
    for(int i=0;i<n;i++) C[A[i]]++;
    for(int i=1;i<k;i++) C[i]=C[i]+C[i-1];

    for(int i=n-1;i>=0;i--)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for(int i=0;i<n;i++) A[i]=B[i];
    delete [] C;
    delete [] B;
}
