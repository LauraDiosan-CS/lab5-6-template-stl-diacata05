#include "Carte.h"
#include <string.h>
/*
	descr: constructor implicit
	in: -
	out: enitate Carte
*/
Carte::Carte() {
	this->autor = NULL;
	this->titlu = NULL;
	this->status = false;
}

/*
	descr: constructor cu parametrii
	in: char* a, char* t, bool s
	out: entitate Carte cu atribute setate
*/
Carte::Carte(char* a, char* t, bool s) {
	this->autor = new char[strlen(a) + 1];
	strcpy_s(this->autor, strlen(a) + 1, a);
	this->titlu = new char[strlen(t) + 1];
	strcpy_s(this->titlu, strlen(t) + 1, t);
	this->status = s;
}

/*
	descr: constructor de copiere
	in: -
	out: entitate Carte
*/
Carte::Carte(const Carte& c) {
	this->autor = new char[strlen(c.autor) + 1];
	strcpy_s(this->autor, strlen(c.autor) + 1, c.autor);
	this->titlu = new char[strlen(c.titlu) + 1];
	strcpy_s(this->titlu, strlen(c.titlu) + 1, c.titlu);
	this->status = c.status;
}

/*
	descr: destructor
	in: -
	out: -
*/
Carte::~Carte() {
	if (this->autor != NULL) {
		delete[] this->autor;
		this->autor = NULL;
	}
	if (this->titlu != NULL) {
		delete[] this->titlu;
		this->titlu = NULL;
	}
}

/*
	descr: getter pentru atributul autor
	in: -
	out: char* - autorul entitatii
*/
char* Carte::getAutor() {
	return this->autor;
}

/*
	descr: getter pentru atributul titlu
	in: -
	out: char* - titlul entitatii
*/
char* Carte::getTitlu() {
	return this->titlu;
}

/*
	descr: getter pentru atributul status
	in: -
	out: bool - statusul entitatii
*/
bool Carte::getStatus() {
	return this->status;
}


/*
	descr: setter pentru atributul autor
	in: char* a
	out: -
*/
void Carte::setAutor(char* a) {
	if (this->autor != NULL) {
		delete[] autor;
	}
	this->autor = new char[strlen(a) + 1];
	strcpy_s(this->autor, strlen(a) + 1, a);
}

/*
	descr: setter pentru atributul titlu
	in: char* t
	out: -
*/
void Carte::setTitlu(char* t) {
	if (this->titlu != NULL) {
		delete[] titlu;
	}
	this->titlu = new char[strlen(t) + 1];
	strcpy_s(this->titlu, strlen(t) + 1, t);
}

/*
	descr: setter pentru atributul status
	in: bool s
	out: -
*/
void Carte::setStatus(bool s) {
	this->status = s;
}

Carte& Carte::operator=(const Carte& c) {
	if (this != &c) {
		this->setAutor(c.autor);
		this->setTitlu(c.titlu);
		this->setStatus(c.status);
	}
	return *this;
}

char* Carte::toString() {
	char empty[] = "empty";
	if (this->autor != NULL && this->titlu != NULL) {
		int noChars = 60;
		char* s = new char[noChars];
		strcpy_s(s, noChars, "autor: ");
		strcat_s(s, noChars, this->autor);
		strcat_s(s, noChars, ", titlu: ");
		strcat_s(s, noChars, this->titlu);
		if (this->status) {
			strcat_s(s, noChars, ", status: imprumutata");
		}
		else {
			strcat_s(s, noChars, ", status: disponibila");
		}
		return s;
	}
	else
		return empty;
}

ostream& operator<<(ostream& os, Carte& const c)
{
	os << c.getAutor() << " " << c.getTitlu() << " " << c.getStatus();
	return os;
}

istream& operator>>(istream& is, Carte& const c) {
	char* autor = new char[15];
	char* titlu = new char[15];
	bool status = 0;
	is >> autor >> titlu >> status;
	c.setAutor(autor);
	c.setTitlu(titlu);
	c.setStatus(status);
	delete[] autor;
	delete[] titlu;
	return is;
}
