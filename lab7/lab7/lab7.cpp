#include <iostream>
#include "UI.h"
#include "Teste.h"
#include "Carte.h"
#include "RepoFileTemplate.h"

using namespace std;

int main()
{

    cout << "Running tests..." << endl;
    teste();
    cout << "Tests passed!" << endl;

    UI ui;

    ui.consola();

    return 0;
}