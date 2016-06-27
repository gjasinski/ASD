//Tablica n-elementowa przesuanc o k pozycji w miejscu i=(i+k)%n
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>

using namespace std;
void print(int* table,  int n);
void shiftTable(int* table, int shift, int n);
bool test(int* table, int n);

int main(){
    srand(time(NULL));
    int* numbers;
    int N=7919;
    numbers= new int [N];
    for(int i=0;i<N;i++) numbers[i]=i;
        //numbers[i]=rand()%100;
    print(numbers, N);
    shiftTable(numbers, 271, N);
    cout<<endl<<"#------------------------------------------"<<endl;
    print(numbers, N);
    if(test(numbers,N)) cout<<"OK"; else cout<<"ERROR";
}

void print(int* table,  int n){
    for(int i=0;i<n;i++)
        cout<<table[i]<<" ";
    cout<<endl;
}

void shiftTable(int* table, int shift, int n){
    bool* shiftedElement= new bool [n];
    for(int i=0;i<n;i++) shiftedElement[i]=false;
    int counter=n;
    int i=0;
    int prevValue=table[0];
    int tmp;
    while(counter>0){
        i+=shift;
        i=i%n;
        if(!shiftedElement[i]){
            tmp=table[i];
            table[i]=prevValue;
            prevValue=tmp;
            shiftedElement[i]=true;
            counter--;
        }
        else{
            while(shiftedElement[i]){
                i++;
                i=i%n;
            }
            prevValue=table[i];
            i+=shift;
            i=i%n;
        }
    }
}

bool test(int* table, int n){
    int number=table[0];
    for(int i=1;i<n;i++){
        if(table[i]!=(number+i)%n) return false;
    }
    return true;
}
