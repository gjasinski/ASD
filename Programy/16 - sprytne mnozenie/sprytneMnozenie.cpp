/*
 Mamy tablice X n-elementowa liczb R
 Wyznaczyc tablice Y n-elementowa:
       y[i]=1/X[i]*Iloczyn(od j=1 do n)X[j]
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int N=10;
void randTab(int* A, int n);

int main(){
    int* A,* B, *C,* D;
    A = new int [N];
    B = new int [N];
    C = new int [N];
    D = new int [N];
    randTab(A,N);
    B[0]=A[0];
    C[N-1]=A[N-1];
    for(int i=1;i<N;i++)B[i]=B[i-1]*A[i];
    for(int i=N-2;i>=0;i--)C[i]=C[i+1]*A[i];
    D[0]=C[1];
    D[N-1]=B[N-2];
    for(int i=1;i<N-1;i++) D[i]=B[i-1]*C[i+1];
    for(int i=0;i<N;i++) cout<<A[i]<<" ";
    cout<<endl;
    for(int i=0;i<N;i++) cout <<D[i]<<" ";
    delete [] A;
    delete [] B;
    delete [] C;
    delete [] D;
    return 0;
}

void randTab(int* A, int n){
    srand(time(NULL));
    for(int i=0;i<n;i++) A[i]=rand()%10;
}
