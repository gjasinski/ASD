/*
    LCS - longest common subsequence problem
    a) algorytm
    b) uzywajac algortymu z podpuktu a) rozwiaz problem najdluszego rosnacego podciagu
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int LCS(int A[], int B[], int n, int m);
int LIS(int A[], int n);

int main(){
    int a=6;
    int b=8;
    int c=11;;
    int A[]={1,2,7,3,8,5};
    int B[]={2,6,1,5,8,7,3,5};
    int C[]={2,5,7,1,2,8,9,1,4,2,10};
    printf("%d ", LCS(A,B,a,b));
    printf("%d ", LIS(C,c));
}

int LCS(int A[], int B[], int n, int m){
    int f[n+1][m+1];
    for(int i=0;i<m+1;i++) f[0][i]=0;
    for(int j=0;j<n+1;j++) f[j][0]=0;
     for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(A[i-1]==B[j-1]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    return f[n][m];
}


int LIS(int A[], int n){
    int B[n];
    for(int i=0;i<n;i++){
        B[i]=A[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(B[j]>B[j+1]){
                int tmp=B[j];
                B[j]=B[j+1];
                B[j+1]=tmp;
            }
        }
    }
    return LCS(A,B,n,n);
}
