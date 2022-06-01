#pragma once
#include <string>
#include <iostream>

class Kwota {
private:
	double wartosc;
	std::string waluta;
	double kurs;
public:
	Kwota(const double& war = 0, const std::string& wal = "PLN", const double& ks = 1) : wartosc(war), waluta(wal), kurs(ks) {};
	Kwota(std::istream& input, std::ostream& output);
	double podaj() const noexcept;
	friend std::ostream& operator<<(std::ostream&, const Kwota&);
};

std::ostream& operator<<(std::ostream&, const Kwota&);


class Faktura {
private:
	static int liczbaID;
	int ID;
	int osoba;
	Kwota kwota;
public:
	Faktura(const int&, const Kwota&);
	Faktura(std::istream& input, std::ostream& output);
	double podajKwote() const noexcept;
	int podajID() const noexcept;
	int podajOsobe() const noexcept;
	void pokaz(std::ostream& output) const noexcept;
	void edytuj(std::istream& input, std::ostream& output) noexcept;
	bool operator==(const Faktura&) const noexcept;
};