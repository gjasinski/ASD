/*
Problem sumy spójengo podciągu.
Dane
A[0..n-1] - liczby całkowite
Wyjście
Max SUMA od i do j A[x]
Gdy wszystkie elementy sa ujemne to suma jest równa 0.
*/
#include <iostream>
#include <cstdlib>

using namespace std;


void prepareArray(int A[], int n);
int solution_1(int A[], int n);
int solution_3(int A[], int n);
int solution_4(int A[], int n);

int main()
{
    const int n=1000;
    int A[n];
    prepareArray(A, n);
    cout<<solution_1(A, n)<<endl;
    cout<<solution_3(A, n)<<endl;
    cout<<solution_4(A, n)<<endl;
}

void prepareArray(int A[], int n)
{
    srand(time(NULL));
    for (int i=0;i<n;i++) A[i]=rand()%10;
}
//O(n^3)
int solution_1(int A[], int n)
{
    int part;
    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            part=0;
            for(int k=i;k<=j;k++) part+=A[k];
            if(part>res) res=part;
        }
    }
    return res;
}
//O(n^2)
int solution_2(int A[], int n);

//O(nlogn)
//rekurencja
int solution_3(int A[], int n)
{
    if(n==0)return 0;
    if(n==1)return max(A[0],0);
    int k=n/2;
    int L=solution_3(A,k);
    int R=solution_3(A+k,n-k);//przesuniecie wskaznika poczatku tablicy
    int sparL=0;
    int sparR=0;
    int par=0;
    for(int i=k;i<n;i++)
    {
        par+=A[i];
        if(par>sparR) sparR=par;
    }
    par=0;
    for(int i=k-1;i>=0;i--)
    {
        par+=A[i];
        if(par>sparL)sparL=par;
    }
    return max((sparL+sparR),max(L,R));
}

//O(n)
int solution_4(int A[], int n)
{
    int part=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        part+=A[i];
        if(part<0)part=0;
        if(part>res)res=part;
    }
    return res;
}
