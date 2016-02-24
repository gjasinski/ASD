/*
Własnośc kopca:
    Dla każdego węzła i który nie jest korzeniem A[parent(i)]>=A[i]
*/

#include <iostream>

using namespace std;

int parent(int i) {return (i-1)/2;}
int left(int i) {return 2*i+1;}
int right(int i) {return 2*i+2;}
void heapify(int A[], int i, int heap_size);
void heapify_iteration(int A[], int i, int heap_size);
void heap_build(int A[], int heap_size);
void heapsort(int A[], int heap_size);
//kolejka priorytetowa
void heap_insert(int A[], int v, int &heap_size);
int heap_maximum(int A[], int heap_size);
int heap_extract_max(int A[], int &heap_size);
void heap_increase_key(int A[], int i, int k, int heap_size);
void heap_delete(int A[], int i, int &heap_size);
void heap_build_insert(int A[], int heap_size);

/*
Dla kolejki priorytetowaje przydatne są operacje
int heap_minimum(int A[], int heap_size);
int hea_extract_min(int A[], int heap_size);
Ale wtedy trzeba zmienic bydowe kopca
rodzic najmniejszy, synowie wieksi od ojca
*/

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

    /*
    //Przywrcanie wlasnosci kopca
    int A[maxn]={16,4,10,14,7,9,3,2,8,1};
    wypisz(A, 10);
    heapify(A, 1, 10);
    heapify_iteration(A,1,10);
    wypisz(A,10);
    */

    /*
    //Tworzenie kopca
    int A[maxn]={4,1,3,2,16,9,10,14,8,7};
    wypisz(A, 10);
    heap_build(A, 10);
    wypisz(A,10);
    */

    /*
    //Sortowanie przez kopcowanie
    //int A[maxn]={4,1,3,2,16,9,10,14,8,7};//10 elementow
    int A[maxn]={5,13,2,25,7,17,20,8,4};//9 elementow
    wypisz(A,9);
    heapsort(A, 9);
    wypisz(A,9);
    */

    /*
    //Kolerki priorytetowe
    int heap_size=10;
    int A[maxn]={4,1,3,2,16,9,10,14,8,7};
    heap_build(A, heap_size);
    wypisz(A,heap_size);
    heap_insert(A, 50, heap_size);
    heap_insert(A, 11, heap_size);
    wypisz(A,heap_size);
    heap_maximum(A, 0);
    cout<<heap_maximum(A, heap_size)<<endl;
    wypisz(A, heap_size);
    cout<<heap_extract_max(A, heap_size)<<endl;
    wypisz(A, heap_size);
    heap_increase_key(A, 9, 15, heap_size);
    heap_increase_key(A, 2, 1, heap_size);
    heap_increase_key(A, 5555, 1, heap_size);
    wypisz(A, heap_size);
    heap_delete(A, 1, heap_size);
    wypisz(A, heap_size);
    heap_delete(A, 2, heap_size);
    wypisz(A, heap_size);
    */
    int heap_size=10;
    int A[maxn]={4,1,3,2,16,9,10,14,8,7};
    heap_build_insert(A, heap_size);
    wypisz(A, heap_size);
}

//Przyracanie własności kopca - wersja rekurencyjna.
void heapify(int A[], int i, int heap_size)
{
    int l=left(i);
    int r=right(i);
    int largest;
    if(l<heap_size and A[l]>A[i]) largest=l;
    else largest=i;
    if(r<heap_size and A[r]>A[largest]) largest=r;
    if(largest!=i)
    {
        int tmp=A[largest];
        A[largest]=A[i];
        A[i]=tmp;
        heapify(A, largest, heap_size);
    }
}


//Przyracanie własności kopca - wersja iteracyjna.
void heapify_iteration(int A[], int i, int heap_size)
{
    int l;
    int r;
    int largest=i;
    do
    {
        i=largest;
        l=left(i);
        r=right(i);
        if(l<heap_size and A[l]>A[i]) largest=l;
        else largest=i;
        if(r<heap_size and A[r]>A[largest]) largest=r;
        if(largest!=i)
        {
            int tmp=A[largest];
            A[largest]=A[i];
            A[i]=tmp;
        }
    }while(largest!=i and i<heap_size);
}

//Budowanie kopca
void heap_build(int A[], int heap_size)
{
    int i=(heap_size-1)/2;
    for(i;i>=0;i--)
    {
        heapify(A, i, heap_size);
    }
}

//budowanie kopca przez wstawianie
void heap_build_insert(int A[], int heap_size)
{
    for(int i=1;i<heap_size;)
        heap_insert(A, A[i], i);
}
//Sortowanie przez kopcowanie
void heapsort(int A[], int heap_size)
{
    heap_build(A, heap_size);
    int tmp;
    for(heap_size;heap_size>0;)
    {
        tmp=A[0];
        A[0]=A[heap_size-1];
        A[heap_size-1]=tmp;
        heap_size--;
        heapify(A, 0, heap_size);
    }
}

//Wstawianie do kopca
void heap_insert(int A[], int v, int &heap_size)
{
    int par, tmp;
    int i=heap_size;
    A[i]=v;
    bool dzialaj;
    do
    {
        par=parent(i);
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

//zwraca najwiekszy element
int heap_maximum(int A[], int heap_size)
{
    if(heap_size==0) cout<<"Kopiec pusty"<<endl;
    else return A[0];
}

//zwrca i usuwa najwiekszy element
int heap_extract_max(int A[], int &heap_size)
{
    if(heap_size==0) {cout<<"Kopiec pusty"; return -666;}
    int maximum=A[0];
    A[0]=A[heap_size-1];
    heap_size--;
    heapify(A, 0, heap_size);
    return maximum;
}

//Procedura podstawia pod A[i] <- k, i przywrca wlasnosc kopca
void heap_increase_key(int A[], int i, int k, int heap_size)
{
    if(i<0 or i>=heap_size) return;
    int tmp, par;
    int dzialaj;
    if(A[i]<k)
    {
        A[i]=k;
        do
        {
            par=parent(i);
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
        heapify(A,i, heap_size);
    }
}

//usuwanie elementu z kopca
void heap_delete(int A[], int i, int &heap_size)
{
    if(i<=0 or i>=heap_size) return;
    A[i]=A[heap_size-1];
    heap_size--;
    heapify(A, i, heap_size);
}
