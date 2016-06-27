#include <iostream>
using namespace std;
void Heapify(int A[], int n, int i);
void BuildHeap(int A[], int n);
void Heapsort(int A[], int n);
int main()
{
    int A[10]={17,5,20,23,-5,3,7,3,21,16};
    for (int i=0;i<10;i++) cout<<A[i]<<" ";
    cout<<endl;
    //Heapify(A,10,1);
    //BuildHeap(A,10);
    Heapsort(A,10);
    for (int i=0;i<10;i++) cout<<A[i]<<" ";
}

int parent(int i){return (i-1)/2;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
void swap(int A[], int x, int y)
{
    int tmp=A[x];
    A[x]=A[y];
    A[y]=tmp;
}

void Heapify(int A[], int n, int i)
{
    int ind_max=i;
    if(left(i)<n && A[left(i)]>A[i])   ind_max=left(i);
    else
        ind_max=i;
    if(right(i)<n && A[right(i)]>A[ind_max]) ind_max=right(i);
    if(ind_max!=i)
    {
        swap(A,i,ind_max);
        Heapify(A,n,ind_max);
    }
}

void BuildHeap(int A[], int n)
{
    for(int i=parent(n-1);i>=0;i--)
    {
        Heapify(A,n,i);
    }
}

void Heapsort(int A[], int n)
{
    int tmp;
    BuildHeap(A,n);
    for (int i=n-1;i>0;i--)
    {
        tmp=A[0];
        A[0]=A[i];
        A[i]=tmp;
        Heapify(A,i,0);
    }
}
