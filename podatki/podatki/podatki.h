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

class Dzialalnosc {
private:
	std::string rodzaj_dzialalnosci;
	int ID;
public:
	std::string podajRodzajDzialalnosci() const noexcept;
	int podajID() const noexcept;
	void edytuj(std::istream& input);
	void pokaz(std::ostream& output);
};

class Podatek {
private:
	std::string nazwa;
	int ID;
	int rodzaj_dzialalnosci;
	double procent;
	double kwota_min, kwota_max; // zamiast typ double to Kwota?
public:
	std::string podajNazwe() const noexcept;
	double podajProcent() const noexcept;
	double podajKwotaMin() const noexcept;
	double podajKwotaMax() const noexcept;
	void edytuj(std::istream& input, std::ostream& output);
	void edytujNazwe(std::istream& input);
	void edytujProcent(std::istream& input);
	void edytujKwotaMin(std::istream& input);
	void edytujKwotaMax(std::istream& input);
	void edytujRodzajDzialalnosci(std::istream& input);
	void pokaz(std::ostream& output);
};

template<typename T>
class Kontener {
private:
	std::vector<T> wektor = {};
public:
	Kontener() = default;
	void dodaj(const T& cos) noexcept {
		wektor.push_back(cos);
	}
	void edytuj(const int& id) noexcept {
		for (auto cos = wektor.begin(); cos != wektor.end(); cos++)
			if (cos->podajID() == id) {
				cos->edytuj();
				break;
			}
	}
	void usun(const int& id) noexcept {
		for (auto cos = wektor.begin(); cos != wektor.end(); cos++)
			if (cos->podajID() == id) {
				wektor.erase(cos);
				break;
			}
	}
	void pokaz(const int& id) const noexcept {
		for (auto cos = wektor.begin(); cos != wektor.end(); cos++)
			if (cos->podajID() == id) {
				cos->pokaz();
				break;
			}
	}
	void pokaz() const noexcept {
		for (auto cos = wektor.begin(); cos != wektor.end(); cos++)
			cos->pokaz();
	}
};
