#include "pch.h"
#include "dzialalnosc.h"


Dzialalnosc::Dzialalnosc(std::string nazwa) : rodzaj_dzialalnosci(nazwa)
{
	ID = liczbaID;
	liczbaID++;
}

Dzialalnosc::Dzialalnosc(std::istream& input, std::ostream& output)
{
	ID = liczbaID;
	liczbaID++;
	edytuj(input, output);
}

std::string Dzialalnosc::podajRodzajDzialalnosci() const noexcept
{
	return rodzaj_dzialalnosci;
}

int Dzialalnosc::podajID() const noexcept
{
	return ID;
}

void Dzialalnosc::pokaz(std::ostream& output)
{
	output << ID << ". " << rodzaj_dzialalnosci << std::endl;
}

void Dzialalnosc::edytuj(std::istream& input, std::ostream& output)
{
	output << "Podaj nazwe rodzaju dzialalnosci: ";
	input >> rodzaj_dzialalnosci;
}

bool Dzialalnosc::operator==(const Dzialalnosc& d) const noexcept {
	return ID == d.ID;
}

int Dzialalnosc::liczbaID = 1;