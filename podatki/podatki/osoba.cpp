#include "pch.h"
#include "osoba.h"
#include <conio.h>
OsobaFizyczna::OsobaFizyczna(std::istream& input, std::ostream& output)
{
	ID = liczbaID;
	liczbaID++;
	edytujImie(input, output);
	edytujNazwisko(input, output);
	edytujPesel(input, output);
	edytujAdres(input, output);
	edytujRodzajDzialalnosci(input, output);
}

int Osoba::podajID() const noexcept
{
	return ID;
}

int Osoba::podajDzialalnosc() const noexcept
{
	return rodzaj_dzialalnosci;
}

std::string Osoba::podajAdres() const noexcept
{
	return adres;
}

void Osoba::edytujAdres(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj adres: ";
	input.ignore();
	std::getline(input, adres);
}

void Osoba::edytujRodzajDzialalnosci(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Wybierz rodzaj dzialalnosci.";
	input >> rodzaj_dzialalnosci;
}

std::string OsobaFizyczna::podajImie() const noexcept
{
	return imie;
}

std::string OsobaFizyczna::podajNazwisko() const noexcept
{
	return nazwisko;
}

std::string OsobaFizyczna::podajPesel() const noexcept
{
	return pesel;
}

void OsobaFizyczna::pokaz(std::ostream& output)
{
	system("CLS");
	output << "Imie i nazwisko : " << imie << " " << nazwisko << std::endl
		<< "PESEL: " << pesel << std::endl
		<< "Adres: " << adres << std::endl
		<< "Rodzaj dzialalnosci: " << rodzaj_dzialalnosci << std::endl;
	_getch();
}

void OsobaFizyczna::edytujImie(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj imie: ";
	input >> imie;
}

void OsobaFizyczna::edytujNazwisko(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj nazwisko: ";
	input >> nazwisko;
}

void OsobaFizyczna::edytujPesel(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj pesel: ";
	input >> pesel;
}

void OsobaFizyczna::edytuj(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Wybierz co chcesz edytowac : " << std::endl;
	output << "1. Imie" << std::endl;
	output << "2. Nazwisko" << std::endl;
	output << "3. Pesel" << std::endl;
	output << "4. Adres" << std::endl;
	output << "5. Rodzaj dzialalnosci" << std::endl;
	int wybor;
	input >> wybor;
	switch (wybor)
	{
	case 1:
		edytujImie(input, output);
		break;
	case 2:
		edytujNazwisko(input, output);
		break;
	case 3:
		edytujPesel(input, output);
		break;
	case 4:
		edytujAdres(input, output);
		break;
	case 5:
		edytujRodzajDzialalnosci(input, output);
		break;
	}

}

OsobaPrawna::OsobaPrawna(std::istream& input, std::ostream& output)
{
	ID = liczbaID;
	liczbaID++;
	edytujNazwe(input, output);
	edytujNIP(input, output);
	edytujAdres(input, output);
	edytujRodzajDzialalnosci(input, output);
}

std::string OsobaPrawna::podajNazwe() const noexcept
{
	return nazwa;
}

std::string OsobaPrawna::podajNIP() const noexcept
{
	return NIP;
}

void OsobaPrawna::pokaz(std::ostream& output)
{
	system("CLS");
	output << "Nazwa: " << nazwa << std::endl
		<< "NIP: " << NIP << std::endl
		<< "Adres: " << adres << std::endl
		<< "Rodzaj dzialalnosci: " << rodzaj_dzialalnosci << std::endl;
	_getch();
}

void OsobaPrawna::edytuj(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Wybierz co chcesz edytowac: " << std::endl;
	output << "1. Nazwe" << std::endl;
	output << "2. NIP" << std::endl;
	output << "3. Adres" << std::endl;
	output << "4. Rodzaj dzialalnosci" << std::endl;
	int wybor;
	input >> wybor;
	switch (wybor)
	{
	case 1:
		edytujNazwe(input, output);
		break;
	case 2:
		edytujNIP(input, output);
		break;
	case 3:
		edytujAdres(input, output);
		break;
	case 4:
		edytujRodzajDzialalnosci(input, output);
		break;
	}
}

void OsobaPrawna::edytujNazwe(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj nazwe osoby prawnej: ";
	input.ignore();
	std::getline(input, nazwa);
}

void OsobaPrawna::edytujNIP(std::istream& input, std::ostream& output)
{
	system("CLS");
	output << "Podaj NIP: ";
	input >> NIP;
}

bool Osoba::operator==(const Osoba& o) const noexcept {
	return ID == o.ID;
}

int Osoba::liczbaID = 1;