#pragma once
#include <vector>
#include <iostream>

class Urzad {};

class Kwota {
private:
	double wartosc;
	std::string waluta;
	double kurs;
public:
	Kwota(const double& war = 0, const std::string& wal = "PLN", const double& ks = 1 ) : wartosc(war), waluta(wal), kurs(ks) {};
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
	double podajKwote() const noexcept;
	int podajID() const noexcept;
	void pokaz() const noexcept;
	void edytuj() noexcept;
};

class Osoba {};

class OsobaFizyczna : public Osoba {};

class OsobaPrawna : public Osoba {};

class Dzialalnosc {};

class Podatek {};

class Kontener {};
