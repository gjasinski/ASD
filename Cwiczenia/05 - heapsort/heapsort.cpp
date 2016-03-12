#include <iostream>
#include <limits.h>
using namespace std;
const int MAX_SIZE=1000000;

struct heap{
    int A[MAX_SIZE];
    int size;
};
int main()
{
    heap *h = new heap;
}

int parent(int n){return (n-1)/2;}
int left(int n){return 2*n+1;}
int right(int n){return 2*n+2;}

void swap(heap *h, int x, int y)
{
    int tmp=h->A[x];
    h->A[x]=h->A[y];
    h->A[y]=tmp;
}
void Heapify(heap *h, int i)
{
    int ind_max;
    if(left(i)<h->size && h->A[left(i)]>h->A[i])
        ind_max=left(i);
    else ind_max=i;
    if(right(i)<h->size && h->A[right(i)>h->A[ind_max]])
        ind_max=right(i);
    if(ind_max!=i)
    {
        swap(h,i,ind_max);
        Heapify(h,ind_max);
    }
}
void increasekey(heap *h, int key, int i)
{
    if(h->A[i]>=key)
    {
        cout<<"error";
        return;
    }
    if(i==0 || h->A[parent(i)]>key) h->A[i]=key;
    else
    {
        h->A[i]=h->A[parent(i)];
        increasekey(h,key,parent(i));
    }
}

void insert(heap *h, int key)
{
    if(h->size<MAX_SIZE)
    {
        h->size++;
        h->A[h->size-1]=INT_MIN;
        increasekey(h,key,h->size-1);
    }
}
