#ifndef UI_H
#define UI_H

#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	UI(Service _s);
	UI(const UI& ui);
	~UI();

	void afisareMeniu();
	void afisareElemente();
	void consola();

	char* readChar(char* deCitit);
	bool readBool();
	int readPozitie();
};


#pragma once

#endif
