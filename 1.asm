;-----------------------------------------------------------------------------------------------
dane1 segment
    brakargumentow          db  "Nie podano argumentow!$"
    zamaloargumentow        db  "Podales jeden argument a powinienes podac dwa!$"
    zaduzoargumentow        db  "Podales za duzo arguemntow!$"
    arg1iloscznakow         db  "Pierwszy argument powinien miec jeden znak!$" 
    arg1znaki               db  "Pierwszy argument powinien miec jeden znak 0/1!$"
    arg2iloscznakow         db  "Drugi argument powinien miec 32 znaki!$" 
    arg2znaki               db  "Drugi argument powinien miec jeden znak 0-9, a-f!$"
    aa_blad                 db  "Procedura adresargumentu. Zbyt duzy argument!$"
    test1                   db  "TeST!!!$"
    tablica                 db  200 dup(?)
    liczbaargumentow        db  0h
    licz                    db  0h             
dane1 ends            



kod1 segment 
    start: 
        assume ss: stos1, ds:dane1 
        mov ax, seg tablica
        mov ds, ax
        
        mov ax, seg w_stos
        mov ss, ax
        mov sp, offset w_stos
        
        call wczytajargumenty
        call wypiszargumenty
        call sprawdzpoprawnoscargumentow
        call wyjdzzprogramu  
     
;Wczytywanie argumentow        
;======================================================================================================        
    wczytajargumenty proc ;wa_etykieta 
            push ax                         ; wrzucenie rejestrow na stos  
            push cx
            push dx                                        
            xor ax,ax                       ; i przygotowanie ich  
            xor cx,cx
            xor dx,dx

            
            mov al,byte ptr es:[80h]        ; pobieram dlugosc podanych argumentow              
        	mov cl,al                       ; przenosze do rejestru licznikowego, wartosc bedzie uzywana podczas wczytywania znakow            
        	;cmp cl,01h                     ; wejsja dla emulatora
        	cmp cl, 00h                     ; wejrsja dla dosbox bo dla pustego arg zacina sie        	
        	je wa_brakargumentow            ; wypisuje komunikat o nie podaniu argumentow
     	
        	mov ax,81h                      ; zapisuje poczatkowy adres poczatkowy argumentu -1, pierwszy znak jest na 82h 
        	mov si,ax
            mov di, offset tablica          ; zapisuje adres poczatkowy tablicy do ktorej bede kopiowal znaki
                     
            xor ax, ax                      ; przygotowanie ax do uzycia
            mov ah,0h                       ; flaga zapisu 0 - nie zapisywac dolara 1 - zapisac dolara      
            mov licz,ah                     ; wyzerowanie licznika
            mov dl,24h                      ; znak $ bedzie uzywany jako separator
            ; rejestr di -  adres w tablicy w ktorym miejscu nalezy zapisac znak
            ; rejestr si - adres z ktorego pobieramy znak z naglowka psp  
            ; dl - znak dolar
            ; ah - flaga zapisu
            ; cl - licznik znakow
        wa_wczytajznak:
            ; do ilosci znakow doliczana jest takze spacja pomiedzy polecenie i argumentem
            ; dlatego test ponizej jest poprawny
            inc si
            dec cl
            cmp cl,00h                      ; jesli licznik doszedl do zera
            je wa_koniecwczytywania         ; to skoncz wczywtywanie
            
            mov al,byte ptr es:[si]           
            cmp al,21h                      ; jesli znak jest znakiem sterujacym
            jl  wa_wz_wstawdolar            ; wczytaj kolejny znak  
            ; nie wiem czy te znaki tez usuwac?
            cmp al,7fh                      ; jesli znak jest znakiem sterujacym
            je wa_wz_wstawdolar             ;     
            mov ah,01h                      ; ustaw flage do zapisu $         
            mov byte ptr [di],al            ; zapisz znak w tablicy
            inc di                          ; inkrementuj pozycje w tablicy
            jmp wa_wczytajznak
            
            wa_wz_wstawdolar:
                ; wywolywane jest gdy wczytalismy bialy znak
                ; sprawdza czy powinno wstawic sie separator miedzy argumentami
                ; flaga w ah, 0 - nie zapisywac, 1 - zapisac separator
                cmp ah,0h                   ; sprawdzenie flagi
                je wa_wczytajznak
                mov ah,licz                 ; zwiekszenie licznika argumentow
                add ah,1
                mov licz,ah
                mov ah,0h                   ; ustawienie flagi zabraniajacej zapis separatora
                mov byte ptr [di],dl        ; zapisanie dolara oddzielajacego argumenty
                add di,1
                jmp wa_wczytajznak    
            
        wa_koniecwczytywania:
            cmp ah,0h                       ; jezeli flaga wskazuje zakaz zapisu separatora
            je wa_zapiszliczbeargumentow    ; to idz dalej
                   
        	mov byte ptr [di],dl            ; dodanie dolara za ostanim argumentem
        	mov ah,licz                     ; zliczenie ostatniego arguemntu
        	add ah,1                        
        	mov licz, ah
        	
        wa_zapiszliczbeargumentow:
        	mov ah,licz
        	mov liczbaargumentow,ah         ; zapisanie ilosci argumentow    
            jmp wa_wyjdz
            
        wa_brakargumentow:
            mov ah,00h
            mov licz,ah
            jmp wa_wyjdz

        wa_wyjdz:
            pop dx
            pop cx  
            pop ax
            ret
    wczytajargumenty endp
    
;======================================================================================================     
    sprawdzpoprawnoscargumentow proc
            push ax
            push bx
            push cx
            push dx
            mov al, liczbaargumentow        ; laduje liczbe arg
            cmp al,00h
            je spa_brakargumentow
            cmp al,02h 
            jl  spa_1argument               ; czy 1 arg?
            jg  spa_wiecejaguemntow         ; czy za duzo arg?
            
            mov ax,00h
            mov es,ax
            call dlugoscargumentu
            mov ax,es                       ; czy arg1 ma dlugosc 1
            cmp ax,01h   
            jne spa_argument1dlugosc
            
            mov ax,00h
            mov es,ax                       ; pobierz adres pierwszego argumentu
            call adresargumentu
            mov si,es
            mov al,byte ptr ds:[si]
            cmp al,31h
            jg spa_argument1zlyznak         ; jezeli znakw zapisie hex jest wiekszy niz 32h to wypisz komunikat
            cmp al,30h
            jl spa_argument1zlyznak         ; jezeli znakw zapisie hex jest mniejszy niz 31h to wypisz komunikat
              
            
            mov ax,01h
            mov es,ax
            call dlugoscargumentu
            xor ax,ax
            mov ax,es                       ; czy arg2 ma dlugosc 32
            cmp ax,20h   
            jne spa_argument2dlugosc       ; jezeli nie wypisz komunikat
            call sprawdzzbiorznakow         ; sprawdz poprawnosc znakowa argumentu 
            mov ax,es
            cmp ax,00h                      ; 0 - wypisz komunikat o niewlasciwych znakach
            je  spa_argument2znaki               
            
            jmp spa_wyjdz
        spa_brakargumentow:
            mov dx, offset brakargumentow
            mov ah, 09h
            int 21h
            call wyjdzzprogramu 
        spa_1argument:      
            mov dx,offset zamaloargumentow
            mov ah,09h
            int 21h
            call wyjdzzprogramu  
        spa_wiecejaguemntow:
            mov dx,offset zaduzoargumentow
            mov ah,09h
            int 21h
            call wyjdzzprogramu
        spa_argument1dlugosc:
            mov dx,offset arg1iloscznakow
            mov ah,09h
            int 21h
            call wyjdzzprogramu  
        spa_argument1zlyznak:
            mov dx,offset arg1znaki
            mov ah,09h
            int 21h
            call wyjdzzprogramu
        spa_argument2dlugosc:
            mov dx,offset arg2iloscznakow
            mov ah,09h
            int 21h
            call wyjdzzprogramu
        spa_argument2znaki:
            mov dx,offset arg2znaki 
            mov ah,09h
            int 21h
            call wyjdzzprogramu
        spa_wyjdz:
        
            pop dx
            pop cx
            pop bx
            pop ax
            ret
    sprawdzpoprawnoscargumentow endp
    
;---------------------------------------------------------------------
    sprawdzzbiorznakow proc                 ; etykieta ssz_
    ; procedura zwraca 0 w przypadku wystapienia znakow z poza zakresu 0-9,a-f
    ; zwraca 1 w przypadku wystepowania tylko i wylacznie znakow z zakresu 0-9,a-f
            push ax
            xor ax,ax
            mov al,01h
            mov es,ax
            call adresargumentu
            mov si,es
            dec si                          ; usunicie przesuniecia zlinijki nizej
        szz_start:
            inc si
            mov al,byte ptr ds:[si]
            cmp al,24h                      ; sprawdz czy znak=$ jezeli tak zwroc wynik pozytywny
            je  szz_zwrocok                 
            cmp al,30h                      ; sprawdz czy znak mniejszy niz znak 0 (30h='0')
            jl szz_zwrocblad
            cmp al,39h                      ; sprawdz czy znak mniejszy lub rowny niz znak(39h='9')
            jle szz_start                   ; wtedy idz do kolejnego znaku 
            cmp al,61h                      ; sprawdz czy znak mniejszyszy niz znak (61h='a')
            jl szz_zwrocblad                
            cmp al,66h                      ; sprawdz czy znak mniejszy lub rowny niz znak (66h='f')
            jle szz_start                   ; w przeciwnym wypadku zwraca blad
        ;! uwaga!
        ; przy dodaniu nowych opcji odkomentowac linie ponizej
            cmp al,66h
            jg  szz_zwrocblad
        ;koniec
        szz_zwrocblad:
            xor ax,ax
            mov al,00h
            mov es,ax
            pop ax
            ret
        szz_zwrocok:
            xor ax,ax
            mov al,01h
            mov es,ax
            pop ax
            ret
    sprawdzzbiorznakow endp
;Zwraca adres argumentu w rejestrze es    
;======================================================================================================    
    adresargumentu proc                     ; etykieta aa_, argument procedury przekazany przez es
            push ax                         ; zapis rejestrow
            push bx                         ; w celu przywrocenia po zakonczeniu dzialania procedury
            push cx                                                  
            xor ax,ax                       ; zerowanie rejestrow
            xor bx,bx
            xor cx,cx  
                                            
                                            ; al - ilosc argumentow
            mov al, liczbaargumentow        ; bl - argument ktorego adres chcemy uzyskac
            mov bx,es 
            cmp bx,ax                       ; jge - skok gdy wiekszy lub rowny
            jge aa_zlynumerargumentu        ; czy numer argumentu ktorego adres chcemy jest dostepny
                                            ; pierwszy argument 0 
                                            
            mov cx,bx                       ; szukany argument przekazujemy do rejestru licznikowego
            mov si,offset tablica           ; przkazujemy poczatek tablicy
            dec si                          ; aby sprawdzic takze pierwszy znak 
            cmp cx,00h                      ; jesli szukalismy 0 argumentu
            je aa_znalazlemadres
            
        aa_szukajdolar:                     ; petla dzialajaca do znaleznienia dolara         
            inc si
            mov al,byte ptr ds:[si]
            cmp al,24h
            jne aa_szukajdolar              ; gdy znak!='$'
        
            dec cx                          ; mzniejszenie rejestru licznikowego
            cmp cx,00h                      ; czy szukanya arg?
            jne aa_szukajdolar              ; procedura bardziej ogolna pozwala znalesc nie tylko 0, 1 arg!
        
        aa_znalazlemadres:             
            inc si
            mov es,si
                     
            pop cx
            pop bx
            pop ax
            ret  
       aa_zlynumerargumentu:
            mov dx,offset aa_blad
            mov ah,09h
            int 21h
            call wyjdzzprogramu    
    adresargumentu endp 

;Zwraca dlugosc argumentu    
;======================================================================================================     
    dlugoscargumentu proc                   ; etykieta da_, argument przekazany przez es 
    ; procedura zwraca w mlodszej czesci rejestru dlugosc argumentu          
            push ax                         ; zapis rejestrow                 
            push cx                         ; w celu przywrocenia po zakonczeniu dzialania procedury               
            xor ax,ax                       ; zerowanie rejestrow
            xor cx,cx 
             
            ; niesprawdzam poprawnosci argument, jest ona sprawdzona w procedurze adresargumentu
            ; wypisany jest wtedy komunikat i program konczy dzialanie
            call adresargumentu             ; argument juz jest w odpowiednim rejestrze
            mov si,es                       ; przeniesienie adresu do si
                        
        da_szukajdolar:                     ; petla dzialajaca do znaleznienia dolara         
            inc cx
            inc si
            mov al,byte ptr ds:[si]
            cmp al,24h
            jne da_szukajdolar              ; gdy znak!='$'
                 
            mov es,cx                       ; zapis wynik do rejestru i zakonczenie procedury
            pop cx
            pop ax
            ret  
    dlugoscargumentu endp

    
;Wypisanie argumentow    
;======================================================================================================
    wypiszargumenty proc                ; etykieta wya_
            push ax                     
            push bx
            push cx
            push dx
            push es
            xor ax,ax 
            xor bx,bx
            xor cx,cx
            xor dx,dx 
            
            mov bl,liczbaargumentow
            cmp bl,00h                   ; zabezpiecznie jezeli jest 0 argumentow
            jne wya_start               ; jne - skok gdy nie rowne
            pop es
            pop cx
            pop bx
            pop ax
            ret                         ; wyjscie z procedury dla 0 argumentow
            
        wya_start:                      ; do es prznosimy argument do wywolywanej procedury
            mov es,cx                   ; rozpoczynamy od 0
            call adresargumentu         ; pobranie adresu argumentu
            mov dx,es
            mov ah,09h                  ; wypisanie
            int 21h 
            
            ;xor dx,dx                   ; spacja
            ;mov dl,20h
            ;mov ah,02h
            ;int 21h
            
            ;mov es,cx                   ; wypisanie dlugosci argumentu
            ;call dlugoscargumentu
            ;mov dx,es
            ;add dx,30h
            ;int 21h 
            
            mov ah,02h
            mov dl,0dh 
            int 21h                     ; nowa linia
            mov dl,0ah
            int 21h
             
            inc cx
            cmp cl,bl
            jne wya_start
                
            pop es
            pop dx
            pop cx
            pop bx
            pop ax
            ret
    wypiszargumenty endp

    wyjdzzprogramu proc
        mov ah, 4ch ;wyjdz z programu
        int 21h
        ret
    wyjdzzprogramu endp    
kod1 ends 

stos1 segment stack
    dw 200 dup(?)
w_stos	dw ?
stos1 ends

end start 
