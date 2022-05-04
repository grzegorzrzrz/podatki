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