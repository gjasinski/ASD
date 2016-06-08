#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int knapsackProblemGreedy(int* val, int* weight, int W, int n);
int knapsackProblemDynamic(int* val, int* weight, int maxW, int n);

int main(){
    int n=5;
    int val[]={15,10,9,5,20};
    int weight[]={4,5,3,5,10};
    int maxWeight=10;
    printf("%d ", knapsackProblemGreedy(val, weight, maxWeight, n));
    printf("%d ", knapsackProblemDynamic(val, weight, maxWeight, n));
}

int knapsackProblemGreedy(int* val, int* weight, int W, int n){
    double valuePerWeight[n];
    for(int i=0; i<n; i++) valuePerWeight[i]=val[i]/weight[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(valuePerWeight[j]<valuePerWeight[j+1]){
                int tmp=valuePerWeight[j+1];
                valuePerWeight[j+1]=valuePerWeight[j];
                valuePerWeight[j]=tmp;
                tmp=val[j+1];
                val[j+1]=val[j];
                val[j]=tmp;
                tmp=weight[j+1];
                weight[j+1]=weight[j];
                weight[j]=tmp;
            }
        }
    }
    int wsum, vsum;
    wsum=vsum=0;
    for(int i=0; i<n; i++){
        if(wsum+weight[i]<=W){
            wsum+=weight[i];
            vsum+=val[i];
        }else{
            if(vsum<val[i]){
                vsum=val[i];
                wsum=weight[i];
            }
        }
    }
    return vsum;
}

int knapsackProblemDynamic(int* val, int* weight, int maxW, int n){
    int i, w;
    int k[n+1][maxW+1];
    for(int i=0; i<n; i++) k[i][0]=0;
    for(int i=0; i<maxW; i++) k[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int w=1; w<=maxW; w++){
                if(weight[i]>w){
                    k[i][w]=k[i-1][w];
                }
                else{
                    k[i][w]=max(val[i-1]+k[i-1][w-weight[i-1]], k[i-1][w]);
                }
            }

    }
    return k[n][maxW];
}


