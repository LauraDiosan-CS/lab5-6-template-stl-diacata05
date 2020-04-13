#ifndef SERVICE_H
#define SERVICE_H
#include <deque>
#include "RepoFile.h"
#include "RepoFileTemplate.h"
#include "Carte.h"

class Service {
private:
	RepoFileTemplate<Carte> repo;
public:
	Service();
	Service(RepoFileTemplate<Carte> r);
	Service(const Service& s);
	~Service();

	void addCarte(char* autor, char* titlu, bool status);
	void updateCarte(int pos, char* autor, char* titlu, bool status);
	void deleteCarte(int pos);

	int findByTitlu(char* titlu);
	deque<Carte> findByAutor(char* autor);

	int imprumut(char* titlu);
	int returnare(char* titlu);



	deque<Carte> getAll();

	Service& operator=(const Service& s);

};
#endif


#pragma once
