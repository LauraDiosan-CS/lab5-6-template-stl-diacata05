#ifndef CARTE_H
#define CARTE_H

#include <iostream>

class Carte {
private:
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
	char* toString();
};

#pragma once

#endif