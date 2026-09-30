Drzewo BST w C++

Program przedstawia implementację binarnego drzewa poszukiwań (BST — Binary Search Tree) w języku C++.

Program pozwala:

wczytać liczbę elementów,

wstawić wartości do drzewa BST,

wyświetlić strukturę drzewa,

wyświetlić elementy w kolejności rosnącej,

zwolnić pamięć zajmowaną przez drzewo.

Wymagania

Do uruchomienia programu potrzebny jest kompilator obsługujący standard C++, np.:

GCC / G++

Clang

Microsoft Visual C++

Program korzysta ze standardowych bibliotek:

#include <iostream>
#include <string>

Struktura programu
struct Wezel

Reprezentuje pojedynczy węzeł drzewa.

Każdy węzeł zawiera:

int wartosc;
Wezel* lewo;
Wezel* prawo;


wartosc — wartość przechowywana w węźle,

lewo — wskaźnik na lewe poddrzewo,

prawo — wskaźnik na prawe poddrzewo.

Konstruktor ustawia wartość oraz inicjalizuje oba wskaźniki jako nullptr.

wstaw()
void wstaw(Wezel*& korzen, int x)


Dodaje element do drzewa BST.

Zasada działania:

jeśli miejsce jest puste, tworzony jest nowy węzeł,

jeśli x jest mniejsze od wartości aktualnego węzła, element trafia do lewego poddrzewa,

w przeciwnym przypadku trafia do prawego poddrzewa.

Wartości równe istniejącym elementom są więc umieszczane w prawym poddrzewie.

pokazRosnaco()
void pokazRosnaco(Wezel* korzen)


Wyświetla elementy drzewa w kolejności rosnącej.

Wykorzystuje przejście in-order:

lewe poddrzewo,

aktualny węzeł,

prawe poddrzewo.

Dzięki właściwościom BST otrzymujemy wartości posortowane rosnąco.

drukuj()
void drukuj(Wezel* korzen, int odstep)


Wyświetla strukturę drzewa w formie tekstowej.

Prawe poddrzewo jest wyświetlane przed węzłem, a lewe po nim. Zwiększanie wartości odstep powoduje przesunięcie kolejnych poziomów drzewa w prawo.

Przykładowy wynik:

        15
    10
        7
5
        3
    2

usunDrzewo()
void usunDrzewo(Wezel* korzen)


Usuwa wszystkie węzły drzewa i zwalnia zajmowaną przez nie pamięć.

Węzły są usuwane od dołu:

lewe poddrzewo,

prawe poddrzewo,

aktualny węzeł.

Uruchomienie

Po zapisaniu programu np. jako main.cpp można go skompilować za pomocą:

g++ main.cpp -o drzewo


Następnie:

./drzewo


W systemie Windows:

drzewo.exe

Przykład działania

Dla danych:

Podaj liczbe elementow: 7
Element 1: 8
Element 2: 3
Element 3: 10
Element 4: 1
Element 5: 6
Element 6: 14
Element 7: 4


Program może wyświetlić:

Zawartosc drzewa:
        14
    10
8
        6
            4
    3
        1

Kolejnosc rosnaca: 1 3 4 6 8 10 14

Złożoność

Dla drzewa o wysokości h operacja wstawiania ma złożoność:

O(h)


W przypadku dobrze zbalansowanego drzewa jest to średnio około:

O(log n)


Natomiast dla drzewa silnie niezbalansowanego, np. gdy wartości są podawane w kolejności rosnącej, może wynosić:

O(n)


Przejście całego drzewa (pokazRosnaco() oraz usunDrzewo()) ma złożoność:

O(n)


gdzie n oznacza liczbę elementów w drzewie.

Autor

Projekt edukacyjny przedstawiający podstawową implementację binarnego drzewa poszukiwań w języku C++.
