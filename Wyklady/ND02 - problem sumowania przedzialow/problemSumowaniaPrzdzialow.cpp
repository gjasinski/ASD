/*
Dane
    tablica A[0..n-1] liczby całkowite
Pytanie
    jaka jest suma elementów od A do B
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void prepareArray(int A[], int n);
void preparePrefixArray(int A[], int prefix[], int n);
int sumAB(int prefix[], int a, int b);

int main()
{
    const int n=100000;
    int A[n];
    prepareArray(A, n);
    //tablica prefiksowa
    int prefix[n];
    preparePrefixArray(A, prefix, n);
    cout<<sumAB(prefix, 5, 120)<<endl;
}

void prepareArray(int A[], int n)
{
    srand(time(NULL));
    for (int i=0;i<n;i++) A[i]=rand()%10;
}

void preparePrefixArray(int A[], int prefix[], int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=A[i];
        prefix[i]=s;
    }
}

int sumAB(int prefix[], int a, int b)
{
    return prefix[b]-prefix[a];
}
