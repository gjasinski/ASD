/*
    Na promie do przewozu samochodow sa dwa pasy, prom ma dlugosc L.
    Przed promem stoja w kolejce samochody. Ile maksymalnie mozna wpuscic na propm.

Rozwiazanie:
    f(i,l,r)=   { True - jezli mozna zaladowac i aut tak aby lewy wypelnic do l i prawy do r.
                { False - w przeciwnym wypadku
    f(i,l,r)=f(i-1,l,r-A[i]) || f(i-1,l-A[i],r)

Hint:
    Wygodnie jest stworzyc tablice hashujaca ktorej kluczem jest (i,l,r) a wartoscia true/false.
*/
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Data{
    int i,l,r;
    bool value;
};

int solveProblem(int A[], int n, int ferryLength){
    while(f(n,ferryLength,ferryLength,A) && n>0){
        n--;
    }
    return n;
}

bool f(int i, int l, int r, int A[]){
    if(w tablicy hasujacej jest klucz (i,l,r)) return value z tego rekordu
    else{
        if(i==l==r==0) return true;
        else{
            if(i==0 && l<0) return false;
            if(i==0 && r<0) return false;
            bool ret=f(i-1,l-A[i],r);
            zapisz w tablicy o kluczu (i-1,l-A[i],r) wartosc ret;
            if(ret) return true;
            ret=f(i-1,l,r-A[i]);
            zapisz w tablicy o kluczu (i-1,l-A[i],r) wartosc ret;
            return ret;
        }
    }

}


