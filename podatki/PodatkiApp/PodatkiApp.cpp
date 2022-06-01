#include <iostream>
#include "../podatki/urzad.h"
int main()
{
    Urzad urzad;
    urzad.dodajPrzykladoweDane();
    do
    {
        urzad.obsluz(std::cin, std::cout);
    } while (urzad.koniecProgramu == false);
}
