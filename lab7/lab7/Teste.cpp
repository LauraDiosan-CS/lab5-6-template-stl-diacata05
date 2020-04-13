#pragma once
#include "Carte.h"
#include "Service.h"
#include "Repo.h"
#include "RepoFile.h"
#include <assert.h>

void testeCarte() {
	char autor[] = "autor";
	char titlu[] = "titlu";

	Carte c1;

	assert(c1.getAutor() == NULL);
	assert(c1.getTitlu() == NULL);
	assert(c1.getStatus() == 0);

	Carte c2(autor, titlu, 0);

	assert(strcmp(c2.getAutor(), autor) == 0);
	assert(strcmp(c2.getTitlu(), titlu) == 0);
	assert(c2.getStatus() == 0);

	Carte c3 = c2;

	assert(strcmp(c3.getAutor(), autor) == 0);
	assert(strcmp(c3.getTitlu(), titlu) == 0);
	assert(c3.getStatus() == 0);

	c3.setAutor(titlu);
	c3.setTitlu(autor);
	c3.setStatus(1);

	assert(strcmp(c3.getAutor(), titlu) == 0);
	assert(strcmp(c3.getTitlu(), autor) == 0);
	assert(c3.getStatus() == 1);

}

void testeRepo() {
	char autor[] = "autor";
	char titlu[] = "titlu";

	Carte c(autor, titlu, 0);

	Repo<Carte> r;

	assert(r.getSize() == 0);

	r.add(c);
	r.add(c);
	r.add(c);

	assert(r.getSize() == 3);

	r.del(1);

	assert(r.getSize() == 2);

	Carte c2(titlu, autor, 1);

	r.update(0, c2);

	assert(strcmp(r.getAll()[0].getAutor(), titlu) == 0);
	assert(strcmp(r.getAll()[0].getTitlu(), autor) == 0);
	assert(r.getAll()[0].getStatus() == 1);
	
}

void testeRepoFileTemplate() {
	char autor[] = "autor";
	char titlu[] = "titlu";

	RepoFileTemplate<Carte> rf("test_carti.in", "test_carti.out");
	rf.loadFromFile();
	
	assert(rf.getSize() == 4);
		
	Carte c(autor, titlu, 0);

	rf.add(c);

	assert(rf.getSize() == 5);
}

void testeService() {
	char autor[] = "autor";
	char titlu[] = "titlu";

	Service s;

	assert(s.getAll().size() == 6);

	s.addCarte(autor, titlu, 0);

	assert(strcmp(s.getAll()[s.getAll().size()-1].getAutor(), autor) == 0);
	assert(strcmp(s.getAll()[s.getAll().size()-1].getTitlu(), titlu) == 0);
	assert(s.getAll()[s.getAll().size()-1].getStatus() == 0);

	s.updateCarte(0, autor, titlu, 0);

	assert(strcmp(s.getAll()[0].getAutor(), autor) == 0);
	assert(strcmp(s.getAll()[0].getTitlu(), titlu) == 0);
	assert(s.getAll()[0].getStatus() == 0);

	s.deleteCarte(0);
	s.deleteCarte(1);

	assert(s.getAll().size() == 5);

	char titlu2[] = "titlu2";
	char titlu12[] = "titlu12";
	char titlu5[] = "titlu5";
	char nTitlu[] = "nTitlu";

	int value = s.imprumut(titlu5);
	assert(value == 0);

	value = s.imprumut(nTitlu);
	assert(value == 3);

	value = s.imprumut(titlu5);
	assert(value == 1);

	value = s.imprumut(titlu12);
	assert(value == 2);

	value = s.returnare(titlu5);
	assert(value == 0);

	value = s.returnare(nTitlu);
	assert(value == 1);

	value = s.returnare(titlu2);
	assert(value == 2);
}


void teste() {
	testeCarte();
	testeRepo();
	testeRepoFileTemplate();
	testeService();
}