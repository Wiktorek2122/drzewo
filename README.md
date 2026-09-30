Drzewo BST w C++
Opis

Program przedstawia implementację binarnego drzewa wyszukiwania (BST) w języku C++.

Drzewo zostało stworzone przy użyciu klasy Drzewo, która umożliwia:

dodawanie elementów,

wyświetlanie drzewa,

wyświetlanie elementów w kolejności rosnącej,

automatyczne usuwanie drzewa z pamięci.

Zasada działania

Dla każdego węzła:

wartości mniejsze od wartości węzła trafiają do lewego poddrzewa,

wartości równe lub większe trafiają do prawego poddrzewa.

Struktura programu
Wezel

Przechowuje:

wartosc – wartość elementu,

lewo – wskaźnik na lewe dziecko,

prawo – wskaźnik na prawe dziecko.

wstaw()

Dodaje nowy element do drzewa zgodnie z zasadami BST.

pokazRosnaco()

Wyświetla elementy w kolejności rosnącej za pomocą przejścia:

lewo → korzeń → prawo

drukuj()

Wyświetla strukturę drzewa w postaci tekstowej.

usunDrzewo()

Usuwa wszystkie węzły drzewa i zwalnia zajętą pamięć.

Konstruktor i destruktor

Konstruktor ustawia początkowo pusty korzeń.

Destruktor automatycznie usuwa całe drzewo po zakończeniu działania obiektu.

Przykładowe dane
Podaj liczbe elementow: 7
Element 1: 8
Element 2: 3
Element 3: 10
Element 4: 1
Element 5: 6
Element 6: 6
Element 7: 14

Przykładowy wynik
Zawartosc drzewa:
        14
    10
8
            6
        6
    3
        1

Kolejnosc rosnaca: 1 3 6 6 8 10 14

Kompilacja

Program można skompilować za pomocą:

g++ main.cpp -o drzewo


Uruchomienie:

./drzewo

Technologie

C++

programowanie obiektowe

rekurencja

dynamiczna alokacja pamięci

binarne drzewo wyszukiwania (BST)#include <iostream>

using namespace std;

// Klasa drzewa BST
class Drzewo {
private:

    // Wezel drzewa
    struct Wezel {
        int wartosc;
        Wezel* lewo;
        Wezel* prawo;

        // Konstruktor wezla
        Wezel(int x) {
            wartosc = x;
            lewo = nullptr;
            prawo = nullptr;
        }
    };

    Wezel* korzen; // Korzen drzewa

    // Wstawianie elementu
    void wstaw(Wezel*& wezel, int x) {
        if (wezel == nullptr) {
            wezel = new Wezel(x);
            return;
        }

        // Mniejsze w lewo, rowne i wieksze w prawo
        if (x < wezel->wartosc) {
            wstaw(wezel->lewo, x);
        } else {
            wstaw(wezel->prawo, x);
        }
    }

    // Wyswietlanie rosnaco
    void pokazRosnaco(Wezel* wezel) {
        if (wezel == nullptr)
            return;

        pokazRosnaco(wezel->lewo);
        cout << wezel->wartosc << " ";
        pokazRosnaco(wezel->prawo);
    }

    // Wyswietlanie drzewa
    void drukuj(Wezel* wezel, int odstep) {
        if (wezel == nullptr)
            return;

        drukuj(wezel->prawo, odstep + 1);

        for (int i = 0; i < odstep; i++)
            cout << "    ";

        cout << wezel->wartosc << "\n";

        drukuj(wezel->lewo, odstep + 1);
    }

    // Usuwanie drzewa
    void usunDrzewo(Wezel* wezel) {
        if (wezel == nullptr)
            return;

        usunDrzewo(wezel->lewo);
        usunDrzewo(wezel->prawo);
        delete wezel;
    }

public:

    // Konstruktor
    Drzewo() {
        korzen = nullptr;
    }

    // Dodanie elementu
    void wstaw(int x) {
        wstaw(korzen, x);
    }

    // Wyswietlenie rosnaco
    void pokazRosnaco() {
        pokazRosnaco(korzen);
        cout << endl;
    }

    // Wyswietlenie drzewa
    void drukuj() {
        drukuj(korzen, 0);
    }

    // Destruktor
    ~Drzewo() {
        usunDrzewo(korzen);
    }
};

int main() {
    Drzewo drzewo; // Utworzenie drzewa
    int ilosc;

    // Pobranie liczby elementow
    cout << "Podaj liczbe elementow: ";
    cin >> ilosc;

    // Wczytanie elementow
    for (int i = 0; i < ilosc; i++) {
        int x;

        cout << "Element " << i + 1 << ": ";
        cin >> x;

        drzewo.wstaw(x); // Dodanie elementu do drzewa
    }

    // Wyswietlenie drzewa
    cout << "\nZawartosc drzewa:\n";
    drzewo.drukuj();

    // Wyswietlenie elementow rosnaco
    cout << "\nKolejnosc rosnaca: ";
    drzewo.pokazRosnaco();

    return 0;
}
