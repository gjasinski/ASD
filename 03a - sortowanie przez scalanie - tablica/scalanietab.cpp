#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void Mergesort(int A[], int B[], int l, int r);

int main()
{
    srand(time(NULL));
    int tab[100];
    for (int i=0;i<100;i++)
    {
        tab[i]=rand()%1000;
        cout<<tab[i]<<" ";
    }
    cout<<endl<<endl;
    int t2[100];
    Mergesort(tab,t2,0,99);
    for (int i=0;i<100;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void merge(int A[], int B[], int l, int q, int r)
{
    int i=l;
    int j=q+1;
    int k=0;
    while (i<=q && j<=r)//co z tym q 2? zlicza?
    {
        if (A[i]>A[j])
        {
            B[k]=A[j];
            j++;
        }
        else
        {
            B[k]=A[i];
            i++;
        }
        k++;
    }
    while(i<=q)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=r)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    k=0;
    for(int p=l;p<=r;p++)
    {
        A[p]=B[k];
        k++;
    }
}

void Mergesort(int A[], int B[], int l, int r)
{
    if(l!=r)
    {
        int q=(l+r)/2;
        Mergesort(A,B,l,q);
        Mergesort(A,B,q+1,r);
        merge(A,B,l,q,r);
    }
}
