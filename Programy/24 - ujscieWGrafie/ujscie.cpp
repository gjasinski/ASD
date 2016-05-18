/*
Jak znalezc ujscie w grafie w czasie liniowym?
Graf podany macierzowo.

Dwie petle i,j,
W wewnetrzenej petli jezeli jest krawedz z wierzcholka i do j => nie ma krawedzi z wierzolka j => i.
    jezeli jest krawedz z j do i => nie ma krawedzi z i do j.

Sa dwie petle, ale za kazdym razem gdy jest jakas krawedz eliminujemy jedna z mozliwosci, i z dwuch petli robi sie algortym liniowy.

*/

#include <stdlib.h>
#include <stdio.h>

bool ujscie(int ** G, int n);

int main(void){
    int n=5;
    int** G= new int*[n];
    for(int i=0;i<n;i++) G[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)G[i][j]=0;
    G[0][3]=G[1][3]=G[2][3]=G[4][3]=1;
    if(ujscie(G,n)) printf("Jest ujscie");
        else printf("Nie ma ujscia");
}
void print(int** G, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ", G[i][j]);
        printf("\n");
    }
}

bool ujscie(int ** G, int n){
    int* wynik = new int[n];
    for(int i=0;i<n;i++) wynik[i]=1;
    print(G, n);
    for(int i=0;i<n;i++){
        if(wynik[i]==0) continue;
        for(int j=0;j<n;j++){
            printf("%d %d\n", i,j);
            if(i==j)continue;
            if(G[i][j]==1){
                wynik[i]=0;
            }else{
                wynik[j]=0;
            }
            if(G[j][i]==1){
                wynik[j]=0;
            }
            else{
                wynik[i]=0;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d ", wynik[i]);
    for(int i=0;i<n;i++) if(wynik[i]) return true;
    return false;
}

