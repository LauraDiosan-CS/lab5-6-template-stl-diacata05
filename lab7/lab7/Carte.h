#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <ostream>
using namespace std;

class Carte {
protected:
	char* autor;
	char* titlu;
	bool status;
public:
	Carte();
	Carte(char* a, char* t, bool s);
	Carte(const Carte& c);
	~Carte();

	char* getAutor();
	char* getTitlu();
	bool getStatus();
	void setAutor(char* a);
	void setTitlu(char* t);
	void setStatus(bool s);

	Carte& operator=(const Carte& p);
	friend ostream& operator<<(ostream& os, Carte& const c);
	friend istream& operator>>(istream& os, Carte& const c);

	char* toString();
};

#pragma once

#endif