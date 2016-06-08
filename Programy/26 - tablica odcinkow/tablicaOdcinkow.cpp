/*
Mamy strukture
struct Line{
    int a,b;
};
Oraz tablice odcinkow:
Line L[n];
int start;
int end;

Nalezy sprawdzic czy da sie przejsc od start do end po odcinkach. Z odcinka naodcinek mozna przechodzic
tylko wtedy gdy odcinek z ktorego zchodziy koczysie sie w x a odcinek na ktory wchodzimy zaczyna sie w x;
np
L[0] => (0,5);
L[1] => (4,6);
L[2] => (5,11);
Mozna przejsc po odcinku 0, 2 nie mozna po 0,1 i 1,2.


Tworzymy haszmape, z listowym rozwiazywaniem konfliktow.
Wrzycamy kazdy odcinek do hashmapy. Klucz wartosc a, a do haszmapy wrzucamy b.
Otrzymalismy graf w reprezentacji listowej. Uzywajac dfs sprawdzamy czy da sie dojsc od start do end.
Jezeli chce sie otrzymac najkrotasza droge, nalezy uzyc bfs.
*/
