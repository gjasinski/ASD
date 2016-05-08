/*
Zaimplementowac funkcje sprawdzajaca czy graf jest dwudzielny.
Rozwiazanie z uzyciem algorytmu bfs.
Graf podany w reprezentacji listowej.
*/
#include <iostream>
#include <queue>
using namespace std;

struct Vertex{
    int color;  //0-niepokolorowane
    int* to;
    int edges;
};

bool dwudzielny(Vertex* V, int n);

int main(){
    Vertex* V= new Vertex[6];
    V[0].edges=1;
    V[0].to = new int[1];
    V[0].to[0]=1;

    V[1].edges=2;
    V[1].to = new int[2];
    V[1].to[0]=0;
    V[1].to[1]=2;

    V[2].edges=1;
    V[2].to = new int[1];
    V[2].to[0]=1;

    V[3].edges=2;
    V[3].to = new int[2];
    V[3].to[0]=4;
    V[3].to[1]=5;

    V[4].edges=1;
    V[4].to = new int[1];
    V[4].to[0]=3;

    V[5].edges=2;
    V[5].to = new int[2];
    V[5].to[0]=3;
    V[5].to[0]=4;

    if(dwudzielny(V,6)) cout<<"Dwudzielny";
        else cout<<"Nie dwudzielny";
}


bool dwudzielny(Vertex* V, int n){
    queue <int> q;
    for(int i=0;i<n;i++){
        V[i].color=0;
    }
    for(int p=0; p<n; p++){
        if(V[p].color==0) q.push(p);
        while(!q.empty()){
            int current=q.front();
            q.pop();
            for(int i=0;i<V[current].edges;i++){
                int j=V[current].to[i];
                int color=3-V[current].color;
                if(V[j].color==0){
                    V[j].color=color;
                    q.push(j);
                }
                else{
                    if(V[j].color!=color) return false;
                }
            }
        }
    }
    return true;
}
