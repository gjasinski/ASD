#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int dziel(int A[], int B[], int p, int q);
int main()
{
    int MAX_SIZE=10;
    int tab[MAX_SIZE];
    int tab2[MAX_SIZE];
    srand(time(NULL));
    for(int i=0;i<MAX_SIZE;i++)
    {
        tab[i]=rand()%100;
        cout<<tab[i]<<" ";
    }cout<<endl;
    cout<<endl<<dziel(tab,tab2,0,9)<<endl;
    for(int i=0;i<MAX_SIZE;i++)
    {
        cout<<tab[i]<<" ";
    }
}

int merge(int A[], int B[], int p, int s, int q)
{
    int w=0;
    int i=p;
    int j=s+1;
    int k=0;
    while(i<=s && j<=q)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else
        {
            w+=s-i+1;
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=s)
    {
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<=q)
    {
        B[k]=A[j];
        j++;
        k++;
    }

    for(int i=0;i<10;i++)
    {
        cout<<B[i]<<" ";

    }cout<<endl;
j=p;
    k=0;
    while(j<=q)
    {
        A[j]=B[k];
        k++;
        j++;
    }
    return w;
}

int dziel(int A[], int B[], int p, int q)
{
    if(p==q)return 0;
    int s=(p+q)/2;
    int w=0;
    w=dziel(A,B,p,s);
    w+=dziel(A,B,s+1,q);
    return w+merge(A,B,p,s,q);
}
