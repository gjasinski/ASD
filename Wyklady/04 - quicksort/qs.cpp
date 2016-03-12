#include <iostream>
#include <stack>
using namespace std;
void quicksort(int A[], int l, int r);
void qs_bezrekurencji(int A[], int N);
int main()
{
    int A[10]={17,5,20,23,-5,3,7,3,21,16};
    //quicksort(A,0,9);
    qs_bezrekurencji(A,10);
    for(int i=0;i<10;i++) cout<<A[i]<<" ";
}
void swap(int A[], int x, int y)
{
    int tmp=A[x];
    A[x]=A[y];
    A[y]=tmp;
}
int partition(int A[], int l, int r)
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
int partition_oryginal(int A[], int l, int r)
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
        //int q=partition(A,l,r);
        int q=partition_oryginal(A,l,r);
        quicksort(A,l,q-1);
        quicksort(A,q+1,r);
    }
}
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
        q=partition_oryginal(A,l,r);
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
