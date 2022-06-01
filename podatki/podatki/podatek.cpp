#include "pch.h"
#include "podatek.h"
#include <conio.h>

int Podatek::podajID() const noexcept
{
	return ID;
}

int Podatek::podajDzialalnosc() const noexcept
{
	return rodzaj_dzialalnosci;
}

void Podatek::edytujNazwe(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj nazwe: ";
	input.ignore();
	std::getline(input, nazwa);
}

void Podatek::edytujProcent(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj procent (format: [To co napisano]%): ";
	input >> procent;
	procent = procent / 100;
}

void Podatek::edytujKwotaMin(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj kwote minimalna: ";
	input >> kwota_min;
}

void Podatek::edytujKwotaMax(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj kwote maksymalna: ";
	input >> kwota_max;
}

void Podatek::edytujRodzajDzialalnosci(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Wybierz rodzaj dzialalnosci.";
	//output wektora dzialalnosci
	input >> rodzaj_dzialalnosci;
}

void Podatek::pokaz(std::ostream& output)
{
	system("CLS");
	output << "Podatek nr " << ID << std::endl << procent * 100 << "%"
		<< "Kwota minimalna: " << kwota_min << std::endl
		<< "Kwota maksymalna: " << kwota_max << std::endl;
	_getch();
}

Podatek::Podatek(std::istream& input, std::ostream& output)
{
	ID = liczbaID;
	liczbaID++;
	edytujNazwe(input, output);
	edytujProcent(input, output);
	edytujKwotaMin(input, output);
	edytujKwotaMax(input, output);
	edytujRodzajDzialalnosci(input, output);
}

std::string Podatek::podajNazwe() const noexcept
{
	return nazwa;
}

double Podatek::podajProcent() const noexcept
{
	return procent;
}

double Podatek::podajKwotaMin() const noexcept
{
	return kwota_min;
}

double Podatek::podajKwotaMax() const noexcept
{
	return kwota_max;
}

void Podatek::edytuj(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Wybierz co chcesz edytowac : " << std::endl;
	output << "1. Nazwe" << std::endl;
	output << "2. Wartosc" << std::endl;
	output << "3. Kwote minimalna" << std::endl;
	output << "4. Kwote maksymalna" << std::endl;
	int wybor;
	input >> wybor;
	switch (wybor)
	{
	case 1:
		edytujNazwe(input, output);
		break;
	case 2:
		edytujProcent(input, output);
		break;
	case 3:
		edytujKwotaMin(input, output);
		break;
	case 4:
		edytujKwotaMax(input, output);
		break;
	case 5:
		edytujRodzajDzialalnosci(input, output);
	}
}

bool Podatek::operator==(const Podatek& p) const noexcept {
	return ID == p.ID;
}

int Podatek::liczbaID = 1;