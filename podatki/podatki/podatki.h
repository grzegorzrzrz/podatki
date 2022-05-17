#pragma once
#include <vector>
#include <iostream>
#include <limits>
#include <string>

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

class Osoba {
protected:
	int ID;
	int rodzaj_dzialalnosci;
	std::string adres;
public:
	int podajID() const noexcept;
	std::string podajAdres() const noexcept;
	void edytujAdres(std::istream& input);
	void edytujRodzajDzialalnosci(std::istream& input);
	virtual void pokaz()=0;
	virtual void edytuj()=0;


};

class OsobaFizyczna : public Osoba {
private:
	std::string imie;
	std::string nazwisko;
	std::string pesel;
public:
	std::string podajImie() const noexcept;
	std::string podajNazwisko() const noexcept;
	std::string podajPesel() const noexcept;
	void pokaz(std::ostream& output);
	void edytuj(std::istream& input, std::ostream& output);
	void edytujImie(std::istream& input);
	void edytujNazwisko(std::istream& input);
	void edytujPesel(std::istream& input);

};

class OsobaPrawna : public Osoba {
private:
	std::string nazwa;
	std::string NIP;
public:
	std::string podajNazwe() const noexcept;
	std::string podajNIP() const noexcept;
	void pokaz(std::ostream& output);
	void edytuj(std::istream& input, std::ostream& output);
	void edytujNazwe(std::istream& input);
	void edytujNIP(std::istream& input);
};

class Dzialalnosc {
private:
	static int liczbaID;
	std::string rodzaj_dzialalnosci;
	int ID;
public:
	Dzialalnosc(std::string nazwa);
	Dzialalnosc(std::istream& input, std::ostream& output);
	std::string podajRodzajDzialalnosci() const noexcept;
	int podajID() const noexcept;
	void edytuj(std::istream& input, std::ostream& output);
	void pokaz(std::ostream& output);
};


class Podatek {
private:
	static int liczbaID;
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
	void edytujNazwe(std::istream& input, std::ostream& output);
	void edytujProcent(std::istream& input, std::ostream& output);
	void edytujKwotaMin(std::istream& input, std::ostream& output);
	void edytujKwotaMax(std::istream& input, std::ostream& output);
	void edytujRodzajDzialalnosci(std::istream& input, std::ostream& output);
	void pokaz(std::ostream& output);
	Podatek(std::istream& input, std::ostream& output);
	Podatek(std::string, double, double, double, int);
	//Kwota policz(Kwota& kwota);
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
