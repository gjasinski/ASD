/*

    Przyczepa o pojemnosci W.
    Paczki o rozmiarach 2^n.
    Np. 1,2,2,4,8,16,32,128,256,1024
    Oidac algorytm ktory wypelni przyczepe w maksymalnym stopniu.
    Uzywajac jak najmnijeszej ilosci paczek.

    Rozwiazanie:
        Nalezy brac za kazdym razem najwieksza paczke jaka zmiesci sie na przyczepie.

        Dlaczego to jest najlepszy(ilosciowo) wybor?
        Korzystamy tu z wlasnosci liczb ktore sa potegami liczby 2.
        Jezeli liczba x sie nie miesci, a z liczb mniejszym niz x uzbieralismy wiecej niz x,
        to zanczy ze liczba x tez sie musi zmiesci! =>sprzecznosc
        np. nie miesci sie 64, a my uzbieralismy 32+16+8+8+2>64 sprzecznosc!

*/
