#include "pch.h"
#include "dzialalnosc.h"
#include <iostream>
#include <conio.h>

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
	system("CLS");
	output << ID << ". " << rodzaj_dzialalnosci << std::endl;
	_getch();
}

void Dzialalnosc::edytuj(std::istream& input, std::ostream& output)
{
	//system("CLS");
	output << "Podaj nazwe rodzaju dzialalnosci: ";
	input.ignore();
	std::getline(input, rodzaj_dzialalnosci);
}

bool Dzialalnosc::operator==(const Dzialalnosc& d) const noexcept {
	return ID == d.ID;
}

int Dzialalnosc::liczbaID = 1;