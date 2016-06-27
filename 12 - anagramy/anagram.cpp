/*
Dwa słowa o długości n, na alfabecie o rozmiarze k.
    Sprawdzić czy A i B anagramami.
*/

#include <iostream>

using namespace std;

int main(){
    int k;
    string wordA, wordB;
    cin >>k;
    cin>> wordA>>wordB;
    int* A = new int [k];
    int length=wordA.length();
    for(int i=0; i<k; i++) A[i]=0;
    for(int i=0; i<length; i++) A[wordA[i]%k]++;
    length=wordB.length();
    bool error=false;
    for(int i=0; i<length && !error; i++){
        if(A[wordA[i]%k]==0) error=true;
        A[wordA[i]%k]--;
    }
    if(error)cout<<"To nie sa anagramy";
    else cout<<"To sa anagramy";
}
