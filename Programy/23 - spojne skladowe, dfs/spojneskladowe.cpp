/*
Prosze zaimplementowac funkcje ktora zwraca ;iczbe spojnych skladowych grafu.

Funkcja korzysta z algorytmu dfs.
Graf jest podany w reprezentacji macierzowej.
*/

#include <iostream>

using namespace std;

int spojneSkladowe(bool** v, int n);

int main(){
    int n=10;
    //bool** v = new (ptr*)
    bool** v = new bool *[n];
    for(int i=0;i<n;i++) v[i]= new bool[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) v[i][j]=false;
    }
    v[0][1]=v[0][2]=1;
    v[1][2]=v[1][0]=1;
    v[2][1]=v[2][0]=1;

    v[4][5]=v[5][3]=v[5][7]=1;

    v[6][7]=v[7][6]=v[7][5]=1;

    v[8][9]=v[9][8]=1;
    cout<<spojneSkladowe(v,n);
}

void dfs(bool** v, int n, bool* visited, int i){
    visited[i]=true;
    for(int j=0;j<n; j++){
        if(i==j) continue;
        if(v[i][j] && !visited[j]) dfs(v,n,visited,j);
    }
}

int spojneSkladowe(bool* v[], int n){
    int count=0;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)visited[i]=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(v,n,visited,i);
            count++;
        }
    }
    return count;
}
