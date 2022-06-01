#include "pch.h"
#include "faktura.h"
#include <conio.h>
Kwota::Kwota(std::istream& input, std::ostream& output) {
	system("CLS");
	output << "Podaj kwote:" << std::endl;
	input >> wartosc;
	output << "Podaj znak waluty:" << std::endl;
	input >> waluta;
	output << "Podaj kurs:" << std::endl;
	input >> kurs;
}

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


Faktura::Faktura(std::istream& input, std::ostream& output) {
	ID = liczbaID;
	liczbaID++;
	output << "Podaj ID osoby:" << std::endl;
	input >> osoba;
	Kwota kw(input, output);
	kwota = kw;
};

double Faktura::podajKwote() const noexcept {
	return kwota.podaj();
}

int Faktura::podajID() const noexcept {
	return ID;
}

int Faktura::podajOsobe() const noexcept {
	return osoba;
}

void Faktura::pokaz(std::ostream& output) const noexcept {
	system("CLS");
	output << "Faktura nr " << ID << std::endl;
	output << "Osoba ID " << osoba << std::endl;
	output << "Kwota " << kwota << std::endl;
	_getch();
}

void Faktura::edytuj(std::istream& input, std::ostream& output) noexcept {
	system("CLS");
	output << "Wybierz co chcesz edytowac : " << std::endl;
	output << "1. ID osoby" << std::endl;
	output << "2. Kwote" << std::endl;
	int wybor;
	input >> wybor;
	system("CLS");
	switch (wybor) {
	case 1:
		int nowaOsoba;
		//output wektora osob??
		output << "Podaj nowy numer ID osoby :" << std::endl;
		input >> nowaOsoba;
		osoba = nowaOsoba;
		this->pokaz(output);
		break;
	case 2:
		double wartosc, kurs;
		std::string waluta;
		output << "Podaj nowa kwote" << std::endl;
		output << "Wartosc" << std::endl;
		input >> wartosc;
		output << "Waluta" << std::endl;
		input >> waluta;
		output << "Kurs" << std::endl;
		input >> kurs;
		kwota = *new Kwota(wartosc, waluta, kurs);
		this->pokaz(output);
		break;
	}
}

bool Faktura::operator==(const Faktura& f) const noexcept {
	return ID == f.ID;
}

int Faktura::liczbaID = 1;