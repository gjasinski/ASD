/*
Własnośc kopca:
    Dla każdego węzła i który nie jest korzeniem A[parent(i)]>=A[i]

Dla kopca rzedu d(majacego d synow)
Dla tablicy A[1..n]
ojciec (i-2+d)/d
1 syn i*d+2-d
2 syn i*d+2-d+1=(i-1)*d+3
d-ty syn i*d+2-d+d-1=i*d+3
*/

#include <iostream>

using namespace std;

int parent(int i, int d) {return (i+1-2+d)/d-1;}
int son(int i, int n, int d) {return ((i+1-1)*d+1+n)-1;}
void heapify(int A[], int i, int d, int heap_size);
void heap_build(int A[], int d, int heap_size);
int heap_extract_max(int A[], int d, int &heap_size);
void heap_insert(int A[], int v, int d, int &heap_size);
void heap_increase_key(int A[], int i, int k, int d, int heap_size);
void wypisz(int A[], int maxn)
{
    for (int i=0;i<maxn;i++)
    {
    cout<<A[i]<< " ";
    }
    cout<<endl;
}

int main()
{
    const int maxn=100;
    int heap_size=16;
    int A[maxn]={19,13,3,2,16,9,10,14,8,7,11,9,51,21,8,13};
    wypisz(A, heap_size);
    //heapify(A,1,5,heap_size);
    heap_build(A, 5, heap_size);
    wypisz(A, heap_size);
    cout<<heap_extract_max(A, 5, heap_size)<<endl;
    wypisz(A, heap_size);
    heap_insert(A,400,5,heap_size);
    wypisz(A, heap_size);
    heap_increase_key(A, 3, 500, 5, heap_size);
    wypisz(A, heap_size);
}

//przywraca wlasnosci kopca
void heapify(int A[], int i, int d, int heap_size)
{
    int s;
    int largest=i;
    for(int n=1;n<=d;n++)
    {
        s=son(i, n, d);
        if(A[s]>A[largest] and s<heap_size)largest=s;
    }
    if(largest!=i)
    {
        int tmp=A[largest];
        A[largest]=A[i];
        A[i]=tmp;
        heapify(A, largest, d, heap_size);
    }
}

//tworzy kopiec rzedu d
void heap_build(int A[], int d, int heap_size)
{
    int i=(heap_size-1)/d;
    for(i;i>=0;i--)
    {
        heapify(A, i, d, heap_size);
    }
}

//zwrca i usuwa najwiekszy element
int heap_extract_max(int A[], int d, int &heap_size)
{
    if(heap_size==0) {cout<<"Kopiec pusty"; return -666;}
    int maximum=A[0];
    A[0]=A[heap_size-1];
    heap_size--;
    heapify(A, 0, d, heap_size);
    return maximum;
}

//Wstawianie do kopca
void heap_insert(int A[], int v, int d, int &heap_size)
{
    int par, tmp;
    int i=heap_size;
    A[i]=v;
    bool dzialaj;
    do
    {
        par=parent(i, d);
        if(par>=0 and A[par]<A[i])
        {
            tmp=A[par];
            A[par]=A[i];
            A[i]=tmp;
            dzialaj=true;
            i=par;
        }
        else dzialaj=false;
    }while (dzialaj);
    heap_size++;
}

//Procedura podstawia pod A[i] <- k, i przywrca wlasnosc kopca
void heap_increase_key(int A[], int i, int k, int d, int heap_size)
{
    if(i<0 or i>=heap_size) return;
    int tmp, par;
    int dzialaj;
    if(A[i]<k)
    {
        A[i]=k;
        do
        {
            par=parent(i, d);
            if(par>=0 and A[par]<A[i])
            {
                tmp=A[par];
                A[par]=A[i];
                A[i]=tmp;
                dzialaj=true;
                i=par;
            }
            else dzialaj=false;
        }while(dzialaj);
    }
    else
    {
        A[i]=k;
        heapify(A, i, d, heap_size);
    }
}
