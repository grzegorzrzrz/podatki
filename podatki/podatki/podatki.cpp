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

void Faktura::pokaz(std::ostream& output) const noexcept {
	output << "Faktura nr " << ID << std::endl;
	output << "Osoba ID " << osoba << std::endl;
	output << "Kwota " << kwota << std::endl;
}

void Faktura::edytuj(std::istream& input, std::ostream& output) noexcept {
	output << "Wybierz co chcesz edytowac : " << std::endl;
	output << "1. ID osoby" << std::endl;
	output << "2. Kwote" << std::endl;
	int wybor;
	input >> wybor;
	switch (wybor) {
	case 1:
		int nowaOsoba;
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

int Faktura::liczbaID = 1;
int Osoba::liczbaID = 1;

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
int Osoba::podajID() const noexcept
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

std::string Osoba::podajAdres() const noexcept
{
	return adres;
}

void Osoba::edytujAdres(std::istream& input, std::ostream& output)
{
	output << "Podaj adres: ";
	input >> adres;
}

void Osoba::edytujRodzajDzialalnosci(std::istream& input, std::ostream& output)
{
	output << "Wybierz rodzaj dzialalnosci.";
		//output wektora dzialalnosci?
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
	output << "Imie i nazwisko : " << imie << " " << nazwisko << std::endl
		<< "PESEL: " << pesel << std::endl
		<< "Adres: " << adres << std::endl
	<< "Rodzaj dzialalnosci: " << rodzaj_dzialalnosci << std::endl;
}

void OsobaFizyczna::edytujImie(std::istream& input, std::ostream& output)
{
	output << "Podaj imie: ";
	input >> imie;
}

void OsobaFizyczna::edytujNazwisko(std::istream& input, std::ostream& output)
{
	output << "Podaj nazwisko: ";
	input >> nazwisko;
}

void OsobaFizyczna::edytujPesel(std::istream& input, std::ostream& output)
{
	output << "Podaj pesel: ";
	input >> pesel;
}

void OsobaFizyczna::edytuj(std::istream& input, std::ostream& output)
{
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
		output << "Nazwa: " << nazwa << std::endl
			<< "NIP: " << NIP << std::endl
			<< "Adres: " << adres << std::endl
		<< "Rodzaj dzialalnosci: " << rodzaj_dzialalnosci << std::endl;
}

void OsobaPrawna::edytuj(std::istream& input, std::ostream& output)
{
	output << "Wybierz co chcesz edytowac : " << std::endl;
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
	output << "Podaj nazwe osoby prawnej: ";
	input >> nazwa;
}

void OsobaPrawna::edytujNIP(std::istream& input, std::ostream& output)
{
	output << "Podaj NIP: ";
	input >> NIP;
}
