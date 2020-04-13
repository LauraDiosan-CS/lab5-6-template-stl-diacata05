#ifndef REPO_H
#define REPO_H

#include "Carte.h"
#include <deque>

using namespace std;
template <class T>
class Repo {
protected:
	deque<T> elemente;
public:
	Repo();
	Repo(const Repo& repo);
	~Repo();

	deque<T> getAll();
	void add(T t);
	void del(int pos);
	void update(int pos, T t);

	int getSize();

	Repo& operator=(const Repo& repo);
};

/*
	descr: constructor implicit
	in: -
	out: entitate Repo
*/
template <class T>
Repo<T>::Repo() {}

/*
	descr: constructor de copiere
	in: const Repo& repo
	out: entitate Repo
*/
template <class T>
Repo<T>::Repo(const Repo& repo) {
	this->elemente = repo.elemente;
}

/*
	descr: destructor
	in: -
	out: -
*/
template <class T>
Repo<T>::~Repo() {
	this->elemente.clear();
}

/*
	descr: get all
	in: -
	out: toate elementele
*/
template <class T>
deque<T> Repo<T>::getAll() {
	return this->elemente;
}

/*
	descr: adaugare carte
	in: Produs p
	out: -
*/
template <class T>
void Repo<T>::add(T t) {
	this->elemente.push_back(t);
}

/*
	descr: stergere carte
	in: int pos
	out: -
*/
template <class T>
void Repo<T>::del(int pos) {
	this->elemente.erase(this->elemente.begin() + pos);
}

/*
	descr: update
	in: int pos, T t
	out: -
*/
template <class T>
void Repo<T>::update(int pos, T t) {
	this->elemente[pos] = t;
}

/*
	descr: getSize
	in: -
	out: int
*/
template <class T>
int Repo<T>::getSize() {
	return this->elemente.size();
}

template <class T>
Repo<T>& Repo<T>::operator=(const Repo<T>& repo) {
	if (this != &repo) {
		this->elemente = repo.elemente;
	}
	return *this;
}

#pragma once

#endif