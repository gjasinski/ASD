#include <iostream>
#include <stack>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
void quicksort(int A[], int l, int r);
void qs_bezrekurencji(int A[], int N);

int main()
{
    int A[100];
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        A[i]=rand()%1000;
    }
    quicksort(A,0,100);
    //qs_bezrekurencji(A,10);
    for(int i=0;i<100;i++) cout<<A[i]<<" ";
}

void swap(int A[], int x, int y)
{
    int tmp=A[x];
    A[x]=A[y];
    A[y]=tmp;
}

//Dzieli tablice na elementy mniejsze i wieksze od pivota, zwrca pivot(element podzialu)
//Wersja tworzenia podzialu wg algorytmu - Lomuto
int partitionLomuto(int A[], int l, int r)
{
    int x=A[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A,i,j);
        }
    }
    swap(A,r,i+1);
    return i+1;
}

//Dzieli tablice na elementy mniejsze i wieksze od pivota, zwrca pivot(element podzialu)
//Wersja tworzenia podzialu wg algorytmu - Hoare
int partitionHoare(int A[], int l, int r)
{
    int i=l-1;
    int j=r+1;
    int x=A[l];
    while(true)
    {
        do
        {
            j--;
        }while(A[j]>x);
        do
        {
            i++;
        }while(A[i]<x);
        if(i<j)swap(A,i,j);
        else return j;
    }
}

void quicksort(int A[], int l, int r)
{
    if(l<r)
    {
        int q=partitionLomuto(A,l,r);
        //int q=partitionHoare(A,l,r);
        //quicksort(A,l,q);dla partitionHoare
        quicksort(A,l,q-1);
        quicksort(A,q+1,r);
    }
}

//QS z uzyciem stosu, bez rekurencji
//Wrzucamy na stos poczatek, koniec
//sciagamy koniec poczatek
//Gdy stos nie jest pusty
void qs_bezrekurencji(int A[], int N)
{
    stack <int> s;
    s.push(0);
    s.push(N-1);
    int l,r,q;
    while(!s.empty())
    {
        r=s.top();
        s.pop();
        l=s.top();
        s.pop();
        q=partitionHoare(A,l,r);
        if(l<q)
        {
            s.push(l);
            s.push(q-1);
        }
        if(q<r)
        {
            s.push(q+1);
            s.push(r);
        }
    }
}
