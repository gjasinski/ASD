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

