#include <stdlib.h>
#include <stdio.h>

bool subsetSumRecursive(int* v, int n, int target);
bool subsetSumDynamic(int* v, int n, int target);

int main(){
    int n=10;
    int v[]={1,7,10,5,2,6,8,4,3};
    int target=20;
    if(subsetSumRecursive(v, n, target)) printf("OK"); else printf("NOPE");
    if(subsetSumDynamic(v, n, target)) printf("OK"); else printf("NOPE");
}

bool subsetSumRecursive(int* v, int n, int target){
    if (target==0) return true;
    if(n==0) return false;
    if(v[n-1]>target) return subsetSumRecursive(v, n-1, target);
    else return subsetSumRecursive(v, n-1, target-v[n-1]) || subsetSumRecursive(v, n-1, target);
}


bool subsetSumDynamic(int* v, int n, int target){
    bool subset[target+1][n+1];
    for(int i=0; i<= target; i++) subset[i][0]=false;
    for(int i=0; i<= n;i++) subset[0][i]=true;
    for(int i=1; i<=target; i++){
        for(int j=1; j<=n; j++){
            subset[i][j]=subset[i][j-1];
            if(i>=v[j-1]) subset[i][j] = subset[i][j] || subset[i-v[j-1]][j-1];
        }
    }
    return subset[target][n];
}
