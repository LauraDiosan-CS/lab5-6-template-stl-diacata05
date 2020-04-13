#include "UI.h"

/*
	descr: constructor implicit
	in: -
	out: entitate UI
*/
UI::UI() {}

/*
	descr: constructor cu parametrii
	in: Serice _s
	out: entitate Service
*/
UI::UI(Service _s) {
	this->s = _s;
}

/*
	descr: constructor de copiere
	in: UI& ui
	out: entitate UI
*/
UI::UI(const UI& ui) {
	this->s = ui.s;
}

/*
	descr: destructor
	in: -
	out: -
*/
UI::~UI() {}

/*
	descr: afisare meniu
	in: -
	out: -
*/
void UI::afisareMeniu() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1. Adaugare carte" << endl;
    cout << "2. Update carte" << endl;
    cout << "3. Sterge carte" << endl;
	cout << "4. Vizualizare carti" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "5. Imprumut" << endl;
    cout << "6. Returnare" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "0. Exit" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

/*
    descr: afisare elemente cu pozitie
    in: -
    out: -
*/
void UI::afisareElemente() {
    deque<Carte> repoCopy = this->s.getAll();
    if (repoCopy.size() == 0) {
        cout << "Nu sunt carti introduse!" << endl;
        return;
    }
    for (int i = 0; i < repoCopy.size(); i++) {
        cout << "pos: " << i << ", " << repoCopy[i].toString() << endl;
    }
}
/*
	descr: consola
	in: -
	out: -
*/
void UI::consola() {
    char a[] = "autor";
    char t[] = "titlu";

    bool finish = true;
    while (finish) {
        int optiune = 0;
        this->afisareMeniu();
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
        {
            char* autor = this->readChar(a);
            char* titlu = this->readChar(t);
            bool status = this->readBool();
            this->s.addCarte(autor, titlu, status);
            break;
        }
        case 2:
        {
            if (this->s.getAll().size() == 0) {
                cout << "Nu exista carti!" << endl;
            }
            else {
                this->afisareElemente();
                int pos = this->readPozitie();
                cout << "Introduceti noile date!" << endl;
                char* autor = this->readChar(a);
                char* titlu = this->readChar(t);
                bool status = this->readBool();
                this->s.updateCarte(pos, autor, titlu, status);
                delete[] autor;
                delete[] titlu;
            }
            break;
        }
        case 3:
        {
            if (this->s.getAll().size() == 0) {
                cout << "Nu exista carti!" << endl;
            }
            else {
                this->afisareElemente();
                int pos = this->readPozitie();
                this->s.deleteCarte(pos);
            }
            break;
        }
        case 4:
            this->afisareElemente();
            break;
        case 5:
        {
            char* titlu = new char[15];
            cout << "Introduceti titlu:";
            cin >> titlu;
            int value = this->s.imprumut(titlu);
            switch (value) {
            case 0:
                cout << "Carte imprumutata!" << endl;
                break;
            case 1:
                break;
            case 2:
                cout << "Din pacate nu exista carti de acelasi autor!" << endl;
                break;
            case 3:
                cout << "Cartea nu exista!" << endl;
                break;
            }
            if (titlu) {
                delete[] titlu;
                titlu = NULL;
            }
            break;
        }
        case 6:
        {
            char* titlu = this->readChar(t);
            int value = this->s.returnare(titlu);
            switch (value) {
            case 0:
                cout << "Carte returnata!" << endl;
                break;
            case 1:
                cout << "Carte nu exista!" << endl;
                break;
            case 2:
                cout << "Cartea nu apare ca fiind imprumutata!" << endl;
                break;
            }
            delete[] titlu;
            break;
        }
        case 0:
            finish = false;
            break;
        default:
            cout << "Nu exista optiunea!" << endl;
            break;
        }
    }
}

/*
    descr: read char
    in: char* deCitit
    out: char *
*/
char* UI::readChar(char* deCitit) {
    char* string = new char[15];
    cout << "Introduceti " << deCitit << ": ";
    cin >> string;
    return string;
}

/*
    descr: read bool
    in: -
    out: bool
*/
bool UI::readBool() {
    bool status = 0;
    cout << "Introduceti status (0=disponibila, 1=imprumutata): ";
    cin >> status;
    return status;
}
/*
    descr: read pozitie
    in: -
    out: int
*/
int UI::readPozitie() {
    int pos = 0;
    cout << "Introduceti pozitie: ";
    cin >> pos;
    return pos;
}
