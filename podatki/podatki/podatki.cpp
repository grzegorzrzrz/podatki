#include "pch.h"
#include "framework.h"
#include "podatki.h"

double Kwota::podaj() const noexcept {
	return wartosc * kurs;
}

std::ostream& operator<<(std::ostream& o, const Kwota& kwota) {
	o << kwota.wartosc << kwota.waluta;
	return o;
}

Faktura::Faktura(const int& os, const Kwota& kw) : osoba(os), kwota(kw) {
	ID = liczbaID;
	liczbaID++;
};

double Faktura::podajKwote() const noexcept {
	return kwota.podaj();
}

int Faktura::podajID() const noexcept {
	return ID;
}

void Faktura::pokaz() const noexcept {
	std::cout << "Faktura nr " << ID << std::endl;
	std::cout << "Osoba ID " << osoba << std::endl;
	std::cout << "Kwota " << kwota << std::endl;
}

void Faktura::edytuj() noexcept {
	std::cout << "Wybierz co chcesz edytowac : " << std::endl;
	std::cout << "1. ID osoby" << std::endl;
	std::cout << "2. Kwote" << std::endl;
	int wybor;
	std::cin >> wybor;
	switch (wybor) {
	case 1:
		int nowaOsoba;
		std::cout << "Podaj nowy numer ID osoby :" << std::endl;
		std::cin >> nowaOsoba;
		osoba = nowaOsoba;
		this->pokaz();
		break;
	case 2:
		double wartosc, kurs;
		std::string waluta;
		std::cout << "Podaj nowa kwote" << std::endl;
		std::cout << "Wartosc" << std::endl;
		std::cin >> wartosc;
		std::cout << "Waluta" << std::endl;
		std::cin >> waluta;
		std::cout << "Kurs" << std::endl;
		std::cin >> kurs;
		kwota = *new Kwota(wartosc, waluta, kurs);
		this->pokaz();
		break;
	}
}

int Faktura::liczbaID = 1;

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

int Dzialalnosc::liczbaID = 1;

int Podatek::liczbaID = 1;

void Podatek::pokaz(std::ostream& output)
{
	output << "Podatek nr " << ID << std::endl << procent * 100 << "%"
		<< "Kwota minimalna: " << kwota_min << std::endl
	<< "Kwota maksymalna: " << kwota_max << std::endl;
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

Podatek::Podatek(std::string nz, double pr, double k_min = 0,
	double k_max = std::numeric_limits<double>::max(), int rodzaj = 0)
	: nazwa(nz), procent(pr), kwota_min(k_min), kwota_max(k_max), rodzaj_dzialalnosci(rodzaj)
{
	ID = liczbaID;
	liczbaID++;
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
	output << "Wybierz co chcesz edytowac : " << std::endl;
	output << "1. Nazwe" << std::endl;
	output << "2. Wartosc" << std::endl;
	output << "3. Kwote minimalna" << std::endl;
	output << "4. Kwote maksymalna" << std::endl;
	output << "5. Rodzaj dzialalnosci" << std::endl;
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
		break;
	}
}

void Podatek::edytujNazwe(std::istream& input, std::ostream& output)
{
	output << "Podaj nazwe: ";
	input >> nazwa;
}

void Podatek::edytujProcent(std::istream& input, std::ostream& output)
{
	output << "Podaj procent (format: [To co napisano]%): ";
	input >> procent;
	procent = procent / 100;
}

void Podatek::edytujKwotaMin(std::istream& input, std::ostream& output)
{
	output << "Podaj kwote minimalna: ";
	input >> kwota_min;
}

void Podatek::edytujKwotaMax(std::istream& input, std::ostream& output)
{
	output << "Podaj kwote maksymalna: ";
	input >> kwota_max;
}

void Podatek::edytujRodzajDzialalnosci(std::istream& input, std::ostream& output)
{
	output << "Wybierz rodzaj dzialalnosci.";
	//output wektora dzialalnosci
	input >> rodzaj_dzialalnosci;
}