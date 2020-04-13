#include "Service.h"

/*
	descr: constructor implicit
	in: -
	out: entitate Service
*/
Service::Service() {
	this->repo = RepoFileTemplate<Carte>("carti.in", "carti.out");
	this->repo.loadFromFile();
}

/*
	descr: constructor cu parametrii
	in: RepoFile r
	out: entitate Service
*/
Service::Service(RepoFileTemplate<Carte> r) {
	this->repo = r;
	this->repo.loadFromFile();
}

/*
	descr: constructor de copiere
	in: Service &s
	out: entitate Service
*/
Service::Service(const Service& s) {
	this->repo = s.repo;
}

/*
	descr: destructor
	in: -
	out: -
*/
Service::~Service() {}

/*
	descr: adaugare carte
	in: char* autor, char* titlu, bool status
	out: -
*/
void Service::addCarte(char* autor, char* titlu, bool status) {
	Carte c(autor, titlu, status);
	this->repo.add(c);
}

/*
	descr: stergere carte de pe pozitie
	in: int pos
	out: -
*/
void Service::deleteCarte(int pos) {
	this->repo.del(pos);
}

/*
	descr: update detalii carte
	in: int pos, Carte c
	out: -
*/
void Service::updateCarte(int pos, char* autor, char* titlu, bool status) {
	Carte c(autor, titlu, status);
	this->repo.update(pos, c);
}

/*
	descr: find by titlu
	in: char* titlu
	out: int
*/
int Service::findByTitlu(char* titlu) {
	deque<Carte> carti = this->repo.getAll();
	for (int i = 0; i < carti.size(); i++) {
		if (strcmp(carti[i].getTitlu(), titlu) == 0) {
			return i;
		}
	}
	return -1;
}

/*
	descr: find by autor
	in: char* autor
	out: deque<Carte>
*/
deque<Carte> Service::findByAutor(char* autor) {
	deque<Carte> repoCarti = this->repo.getAll();
	deque<Carte> carti;
	for (int i = 0; i < repoCarti.size(); i++) {
		if (strcmp(repoCarti[i].getAutor(), autor) == 0 && repoCarti[i].getStatus() == 0) {
			carti.push_back(repoCarti[i]);
		}
	}
	return carti;
}

/*
	descr: functionalitate imprumut
	in: char* titlu
	out: int
*/
int Service::imprumut(char* titlu) {
	int pos = this->findByTitlu(titlu);
	if (pos != -1) {
		if (this->getAll()[pos].getStatus() == 0) {
			this->repo.update(pos, Carte(this->getAll()[pos].getAutor(), titlu, 1));
			return 0;
		}
		else {
			deque<Carte> carti = this->findByAutor(this->getAll()[pos].getAutor());
			if (carti.size() == 0) {
				return 2;
			}
			else {
				cout << "Cartea este indisponibila!" << endl;
				cout << "Carti ale aceluiasi autor: " << endl;
				for (int i = 0; i < carti.size(); i++) {
					cout << carti[i].toString() << endl;
				}
				return 1;
			}
		}
	}
	if(pos==-1) {
		return 3;
	}
}

/*
	descr: functionalitate returnare
	in: char* titlu
	out: int
*/
int Service::returnare(char* titlu) {
	int pos = this->findByTitlu(titlu);
	if (pos != -1) {
		if (this->getAll()[pos].getStatus() == 1) {
			this->repo.update(pos, Carte(this->getAll()[pos].getAutor(), titlu, 0));
			return 0;
		}
		else {
			return 2;
		}
	}
	if (pos == -1) {
		return 1;
	}
}


/*
	descr: get all
	in: -
	out: deque<Carte>
*/
deque<Carte> Service::getAll() {
	return this->repo.getAll();
}

Service& Service::operator=(const Service& s) {
	if (this != &s) {
		this->repo = s.repo;
	}
	return *this;
}