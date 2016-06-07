#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;
int stronglyConnectedComponents(bool** G, int n);

int main(){
    int n=8;
    bool** G = new bool*[n];
    for(int i=0; i<n; i++){
        G[i]=new bool[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=false;
        }
    }
    G[0][2]=G[1][0]=G[1][3]=G[2][1]=G[2][3]=G[2][4]=G[3][5]=G[4][6]=G[4][5]=G[5][3]=G[5][7]=G[6][4]=G[6][7]=true;
    printf("%d ", stronglyConnectedComponents(G,n));
}
void dfs(bool** G, bool* visited, int n, int i, stack<int> &s){
    visited[i]=true;
    for(int e=0; e<n; e++){
        if(G[i][e] && !visited[e]) dfs(G, visited, n, e, s);
    }
    s.push(i);;
}


int stronglyConnectedComponents(bool** G, int n){
    stack<int> s;
    bool visited[n];
    for(int i=0;i<n;i++) visited[i]=false;
    for(int i=0; i<n; i++) if(!visited[i]) dfs(G, visited, n, i, s);
    bool** GT = new bool*[n];
    for(int i=0; i<n;i++) GT[i]= new bool[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            GT[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(G[i][j]) GT[j][i]=true;;
        }
    }
    int count=0;
    int tmp;
    stack <int> stmp;
    for(int i=0; i<n; i++) visited[i]=false;
    while(!s.empty()){

        tmp=s.top();
        s.pop();
        if(!visited[tmp]){
            count++;
            dfs(GT, visited, n, tmp, stmp);
        }
    }
    return count;
}
