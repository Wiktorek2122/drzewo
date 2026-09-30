#include <iostream>

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
