#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;
bool eulerCircuits(bool** G, int n);

int main(){
    int n=5;
    bool** G = new bool*[n];
    for(int i=0; i<n; i++){
        G[i]=new bool[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=false;
        }
    }
    G[0][1]=G[0][4]=G[1][0]=G[1][4]=G[1][3]=G[1][2]=G[2][1]=G[2][3]=G[3][2]=G[3][1]=G[4][1]=G[4][1]=true;
    if(eulerCircuits(G, n)) printf("OK"); else printf("NO OK");
}

bool eulerCircuits(bool** G, int n){
    stack<int> s;
    s.push(0);
    int v;
    while(!s.empty()){
        v=s.top();
        s.pop();
        for(int i=0; i<n; i++){
            if(G[v][i]){
                s.push(v);
                G[v][i]=false;
                v=1;
                break;
            }
        }
    }
    return v==0;
}
