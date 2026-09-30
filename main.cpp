#include <iostream>
#include <string>

using namespace std;

struct Wezel {
    int wartosc;
    Wezel* lewo;
    Wezel* prawo;

    Wezel(int x) {
        wartosc = x;
        lewo = nullptr;
        prawo = nullptr;
    }
};

void wstaw(Wezel*& korzen, int x) {
    if (korzen == nullptr) {
        korzen = new Wezel(x);
        return;
    }

    if (x < korzen->wartosc) {
        wstaw(korzen->lewo, x);
    } else {
        wstaw(korzen->prawo, x);
    }
}

void pokazRosnaco(Wezel* korzen) {
    if (korzen == nullptr)
        return;

    pokazRosnaco(korzen->lewo);
    cout << korzen->wartosc << " ";
    pokazRosnaco(korzen->prawo);
}

void drukuj(Wezel* korzen, int odstep) {
    if (korzen == nullptr)
        return;

    drukuj(korzen->prawo, odstep + 1);

    for (int i = 0; i < odstep; i++)
        cout << "    ";

    cout << korzen->wartosc << "\n";

    drukuj(korzen->lewo, odstep + 1);
}

void usunDrzewo(Wezel* korzen) {
    if (korzen == nullptr)
        return;

    usunDrzewo(korzen->lewo);
    usunDrzewo(korzen->prawo);
    delete korzen;
}

int main() {
    Wezel* drzewo = nullptr;
    int ilosc;

    cout << "Podaj liczbe elementow: ";
    cin >> ilosc;

    for (int i = 0; i < ilosc; ++i) {
        int x;

        cout << "Element " << i + 1 << ": ";
        cin >> x;

        wstaw(drzewo, x);
    }

    cout << "\nZawartosc drzewa:\n";
    drukuj(drzewo, 0);

    cout << "\nKolejnosc rosnaca: ";
    pokazRosnaco(drzewo);
    cout << "\n";

    usunDrzewo(drzewo);
    drzewo = nullptr;

    return 0;
}
