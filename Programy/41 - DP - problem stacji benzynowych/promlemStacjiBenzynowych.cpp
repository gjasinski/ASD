/*
    Problem stacji benzynowych
Czlog spala 1 l/km, bak o pojemnosci D litrow.
Dana jest tablica P[] - odleglosc od poczatku do n-tej stacji beznynowej.

1. Jak policzyc minimalna liczbe tankowan?
    Nalewamy paliwa do pelna, jedziemy do najdalszej stacji do ktorej mozemy dojechac. Nelwamy paliwa do pelna.

2. Obliczyc minimalny koszt przejazdu(ilosc tankowan nie ma znaczenia).
Dodatkowo dana tablica C[] - ceny na n-tej stacji.

    I sposob:
        Za kazdym razem gdy dojezadzamy do stacji podejmujemy decyzje:
        - jezeli jestesmy w stanie dojeac do tanszej stacji to tankujemy tylko tyle by do niej dojechac
        - jezeli wszystkie stacje do ktorych mozemy dojechac sa drozsze to tankujemy do pelna

    II sposob:
        Tworzymy tablice kosztow za przejechanie kilometra.
        - gdy jestesmy na stacji wpisujemy do D komorek tablicy cene paliwa
        - jezeli tablica jest wypelniona i cena paliwa jest mniejsza niz w tablicy to aktualizujemy D komorek

3. Czolg nie jedzie po lini, a po DAG-u.
    Tworzymy tablice wierzcholkow do ktorcyh mozemy dojec z danego wierzcholka gdy mamy x-litromw paliwa.

*/
