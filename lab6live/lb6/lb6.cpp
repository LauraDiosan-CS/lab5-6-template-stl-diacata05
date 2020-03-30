#include <iostream>
#include "Carte.h"
#include "Repo.h"

using namespace std;

void consola() {
    Repo<Carte> r;
    bool finish = true;
    while (finish) {
        int optiune = 0;
        cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Adaugare carte" << endl;
        cout << "2. Vizualizare carti" << endl;
        cout << "0. Exit" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
        {
            char* autor = new char[15];
            char* titlu = new char[15];
            bool status = 1;
            cout << "Introduceti autor: ";
            cin >> autor;
            cout << "Introduceti titlu: ";
            cin >> titlu;
            cout << "Introduceti status: ";
            cin >> status;
            Carte c(autor, titlu, status);
            r.add(c);
            break;
        }
        case 2:
            for (int i = 0; i < r.getAll().size(); i++) {
                cout << "pos: " << i << ", " << r.getAll()[i].toString() << endl;
            }
            break;
        case 0:
            finish = false;
            break;
        default:
            cout << "Nu exista optiunea!" << endl;
            break;
        }
    }
}

int main()
{
    /*cout << "Running tests..." << endl;
    teste();
    cout << "Tests passed!" << endl;*/

    consola();

    return 0;
}