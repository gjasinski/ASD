/*
    Problem nadluzszego rosnacego podciagu - LIS
    Dane:
        A[0, n-1] - tablica liczb
    Zadanie:
        Obliczyc dlugosc najdluzszego rosnacego podciagu niekoniecznie spojnego.
    Tests:
    https://www.hackerrank.com/challenges/longest-increasing-subsequent
*/
#include <stdio.h>
#include <cstdio>
int lis(int* A, int n);
void printSolution(int* A, int* P, int i);
struct node{
    int val, rank;
};
int lis_nlogn(int* A, int n);

int main(){
    int n;
    scanf("%d", &n);
    int* A = new int[n];
    for(int i=0;i<n;i++) scanf("%d", &A[i]);
    //printf("%d", lis(A,n));
    printf("%d", lis_nlogn(A, n));

}
//N^2 solution
int lis(int* A, int n){
    int F[n];
    int max=0;
    int P[n];
    F[0]=1;
    P[0]=-1;
    for(int i=1; i<n; i++){
        F[i]=1;
        P[i]=-1;
        for(int j=0; j<i; j++){
            if(A[j]<A[i] && F[j]+1>F[i]){
                F[i]=F[j]+1;
                P[i]=j;
            }
        }
        if(F[max]<F[i])max=i;
    }
    printSolution(A,P,max);
    return F[max];
}

void printSolution(int* A, int* P, int i){
    if(P[i]!=-1){
        printSolution(A, P, P[i]);
        printf("%d ", A[i]);
    }
}
int bsearch(node A[], int l, int r, int s){
    if (A[r].val<s)return r;
    while(r-1>l and r!=l){
        int m=(l+r)/2;
        if(A[m].val>=s) r=m;
        else l=m;
    }
    return l;
}
/*
    Nlogn solution
    http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
*/
int lis_nlogn(int* A, int n){
    node* auxTable= new node[n];
    int length=1;
    for(int i=0;i<n;i++) auxTable[i].val=auxTable[i].rank=-1;
    node ptr;
    ptr.rank=1;
    ptr.val=A[0];
    auxTable[0]=ptr;

    for(int i=1;i<n;i++){
        int j=bsearch(auxTable, 0,length-1, A[i]);
        if(auxTable[j].val>A[i]) auxTable[j].val=A[i];  //Case1 - decrease value
        else{
            if(j+1<length && auxTable[j].rank+1==auxTable[j+1].rank) auxTable[j+1].val=A[i]; //Case2 - for delta rank==1
            else{
                //case3 - for delta rank >1 or end of matrix
                ptr.rank=auxTable[j].rank+1;
                ptr.val=A[i];
                if(A[i]>auxTable[j].val) j++;
                for(j; j<length;j++){
                    node ptr2=auxTable[j];
                    auxTable[j]=ptr;
                    ptr=ptr2;
                }
                auxTable[length]=ptr;
                length++;
            }
        }
    }
    int max=auxTable[length-1].rank;
    delete [] auxTable;
    return max;
}
