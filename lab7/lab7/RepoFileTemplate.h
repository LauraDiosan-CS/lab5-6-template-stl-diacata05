#ifndef REPOFILETEMPLATE_H
#define REPOFILETEMPLATE_H

#include "Repo.h"

template <class T>
class RepoFileTemplate : Repo<T> {
private:
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoFileTemplate();
	RepoFileTemplate(const char* fileNameIn, const char* fileNameOut);
	~RepoFileTemplate();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameOut);

	void add(T t);
	void update(int pos, T t);
	void del(int pos);
	deque<T> getAll();
	int getSize();


	void loadFromFile();
	void saveToFile();

	RepoFileTemplate<T>& operator=(const RepoFileTemplate<T>& r);

};

/*
	descr: constructor implicit
	in: -
	out: entitate RepoFileTemplate
*/
template <class T>
RepoFileTemplate<T>::RepoFileTemplate() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

/*
	descr: constructor cu parametrii
	in: const char* fileNameIn, const char* fileNameOut
	out: entitate RepoFileTemplate
*/
template <class T>
RepoFileTemplate<T>::RepoFileTemplate(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	//this->loadFromFile(); - apelam in serviciu
}

/*
	descr: destructor
	in: -
	out: -
*/
template <class T>
RepoFileTemplate<T>::~RepoFileTemplate() {
	if (this->fileNameIn) {
		delete[] this->fileNameIn;
		this->fileNameIn = NULL;
	}
	if (this->fileNameOut) {
		delete[] this->fileNameOut;
		this->fileNameOut = NULL;
	}
	Repo<T>::~Repo();
}

/*
	descr: setter pentru attributul fileNameIn
	in: const char* fileNameIn
	out: -
*/
template <class T>
void RepoFileTemplate<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

/*
	descr: setter pentru attributul fileNameOut
	in: const char* fileNameOut
	out: -
*/
template <class T>
void RepoFileTemplate<T>::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

/*
	descr: adaugare element
	in: -
	out: -
*/
template <class T>
void RepoFileTemplate<T>::add(T t) {
	Repo<T>::add(t);
	this->saveToFile();
}

/*
	descr: stergere element
	in: -
	out: -
*/
template <class T>
void RepoFileTemplate<T>::del(int pos) {
	Repo<T>::del(pos);
	this->saveToFile();
}

/*
	descr: update element
	in: -
	out: -
*/
template <class T>
void RepoFileTemplate<T>::update(int pos, T t) {
	Repo<T>::update(pos, t);
	this->saveToFile();
}

/*
	descr: get size
	in: -
	out: -
*/
template <class T>
int RepoFileTemplate<T>::getSize() {
	return Repo<T>::getSize();
}

/*
	descr: get all
	in: -
	out: deque<T>
*/
template <class T>
deque<T> RepoFileTemplate<T>::getAll() {
	return Repo<T>::getAll();
}

template <class T>
RepoFileTemplate<T>& RepoFileTemplate<T>::operator=(const RepoFileTemplate<T>& r) {
	if (this != &r) {
		delete[] this->fileNameIn;
		delete[] this->fileNameOut;
		this->fileNameIn = new char[strlen(r.fileNameIn) + 1];
		strcpy_s(this->fileNameIn, strlen(r.fileNameIn) + 1, r.fileNameIn);
		this->fileNameOut = new char[strlen(r.fileNameOut) + 1];
		strcpy_s(this->fileNameOut, strlen(r.fileNameOut) + 1, r.fileNameOut);
	}
	return *this;
}
/*
	descr: preluare din fisier
	in: -
	out: -
*/
template <class T>
void RepoFileTemplate<T>::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->elemente.clear();
		ifstream f(this->fileNameIn);
		while (!f.eof())
		{
			T t;
			f >> t;
			this->add(t);
		}
		f.close();
	}
}

/*
	descr: salvare in fisier
	in: -
	out: -
*/
template <class T>
void RepoFileTemplate<T>::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->elemente.size(); i++)
		{
			f << this->elemente[i] << endl;
		}
		f.close();
	}
}

#pragma once

#endif
