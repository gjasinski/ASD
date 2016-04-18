#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int qsPivot_ntaLiczba(int A[], int n, int k);
void quicksort(int A[], int l, int r);
int main()
{
    int MAX_SIZE=100;
    int tab[MAX_SIZE];
    int k=1000;
    srand(time(NULL));
    for(int i=0;i<MAX_SIZE;i++)
    {
        tab[i]=rand()%k;
    }
    //for(int i=0;i<100;i++)cout<<tab[i]<<" ";
    cout<<endl;
    cout<<qsPivot_ntaLiczba(tab,99,10);
    quicksort(tab,0,99);
    cout<<endl;
    cout<<tab[10]<<endl;
    for(int i=0;i<100;i++)cout<<tab[i]<<" ";
}
void swap(int A[], int a,int b)
{
    int tmp=A[a];
    A[a]=A[b];
    A[b]=tmp;
}
int partition(int A[], int p, int k)
{
    int x=A[k];
    int i=p-1;
    int j;
    for(j=p;j<k;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A, i,j);
        }
    }
    swap(A,k,i+1);
    return i+1;
}
int partition_2(int A[], int p, int k)
{
    int x=A[p];
    int i=p-1;
    int j=k+1;
    while(true)
    {
        do
        {
            i++;
        } while(A[i]<x);
        do
        {
            j--;
        }while(A[j]>x);
        if(i<j)
        swap(A,i,j);
        else return i;
    }
}

int qsPivot_ntaLiczba(int A[], int n, int k)
{
    //int q=partition(A,0,n);
    int q=partition_2(A,0,n);
    if(q==k) return A[q];
    if(q>k) return qsPivot_ntaLiczba(A,q-1,k);
    if(q<k) return qsPivot_ntaLiczba(A+q+1,n-(q+1),k-(q+1));
}

void quicksort(int A[], int l, int r)
{
    if(l<r)
    {
        int q=partition_2(A,l,r);
        quicksort(A,l,q-1);
        quicksort(A,q+1,r);
    }
}
