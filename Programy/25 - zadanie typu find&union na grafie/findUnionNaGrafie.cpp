/*
Mamy dany graf nieskierowany, kazda krawedz ma pewna wage.
Graf reprezentuje np. siec komunikacji miejskiej.
Nalezy znalesc taka trase z A do B, aby mozna bylo podzielic pewna ilosc osob na najmniejsza ilosc grup.
Podzielone grupy nie moga sie dzielic w czasie podrozy.


Rozwiazenie I:

Sortujemy pary wierzcholkow, po wadze miedzy nimi.
Scalamy od najwiekszej wagi, za kazdym razem sprawdzamy czy czy wierzcholki A i B.
sa w jednej skladowej, Dzialamy do skutku.

Rozwiazanie II:
Wyszukiwanie binarne. Losujemy liczbe z zakresu pomiedzy minimalna a maksymalna waga.
Usuwamy wszyskie krawedzie ktore maja mniejsza wage od wylosowanej. Jezel wiercholki
A i B sa w jednej skladowej spojej to losujemy mniejsza liczbe, jezeli nie sa w jednej
skladowej spojej to losujemy wieksza liczbe. Dzilamy do zmniejszajac przedzial do momentu
osiagniecia przedzialu o rozmiarze 1.
*/

//Nie testowane, moga byc bledy
#include <cstdio>
#include <stdlib.h>
#include <climits>

struct Vertex{
    int id, rank;
    Vertex* parent;
};

struct Edge{
    Vertex* v1,* v2;
    int weight;
};


int main(){
}

void sort(Edge*& e, int edges){
    for(int i=0; i<edges; i++){
        for(int j=0; j<edges-1; j++){
            if(e[j].weight<e[j+1].weight){
                Edge tmp=e[j];
                e[j]=e[j+1];
                e[j+1]=tmp;
            }
        }
    }
}

Vertex* findSet(Vertex* v){
    if(v->parent==v) return v;
    else return findSet(v->parent);
}

bool diffrentSets(Vertex* v1, Vertex* v2){
    return findSet(v1)!=findSet(v2);
}

void unionVertices(Vertex* v1, Vertex* v2){
    Vertex* s1 = findSet(v1);
    Vertex* s2 = findSet(v2);
    if(s1->rank>s2->rank){
        s2->parent=s1->parent;
    }else{
        s1->parent=s2;
        if(s1->rank==s2->rank) s2->rank++;
    }
}

int findMaximumGroupSize(Edge* e, int edges,Vertex** v, int vertices, int A, int B){
//A==>B from vertex A to B find best route
    sort(e, edges);
    int lowestRouteCapacity=INT_MAX;
    for(int i=0; i<edges; i++){
        if(!diffrentSets(v[A], v[B])) return lowestRouteCapacity;
        if(diffrentSets(e[i].v1, e[i].v2)){
            unionVertices(e[i].v1, e[i].v2);
            lowestRouteCapacity=e[i].weight;
        }
    }
    return -1;
}


//Nie testowane, na pewno sa bledy
struct Vertexb{
    int* edge;
    int edges;
    int* weight;
};


bool binaryDFS(Vertexb* v, int vertex, bool* visited, int limit, int target){
    visited[vertex]=true;
    if(vertex==target) return true;
    bool result = false;
    for(int i=0; i<v[vertex].edges; i++){
        if(v[vertex].weight[i]>=limit)result = binaryDFS(v, v[vertex].edge[i], visited, limit, target);
        if(result) return true;
    }
    return false;
}

int binaryFindMaximumGroupSize(Vertexb* v, int n, int A, int B){
    int maximumWeight=0;
    bool visited[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
        for(int j=0; j<v[i].edges; j++){
            if(maximumWeight<v[i].weight[j]) maximumWeight=v[i].weight[j];
        }
    }
    bool search=true;
    int upLimit=maximumWeight;
    int downLimit=0;
    int limit=maximumWeight/2;
    int bestRoute=0;
    while (search){
        if(binaryDFS(v,A,visited,limit,B)){
            if(limit>bestRoute)bestRoute=limit;
            if(downLimit<limit)downLimit=limit;
            limit=(limit+upLimit)/2;
        }
        else{
            if(upLimit>limit)upLimit=limit;
            limit=(limit+downLimit)/2;
        }
        if(downLimit==upLimit) break;
        for(int i=0; i<n; i++)visited[i]=false;
    }
    return bestRoute;

}


