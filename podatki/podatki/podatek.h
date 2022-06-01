#pragma once
#include <string>
#include <iostream>

class Podatek {
private:
	static int liczbaID;
	std::string nazwa;
	int ID;
	int rodzaj_dzialalnosci;
	double procent;
	double kwota_min, kwota_max;
public:
	std::string podajNazwe() const noexcept;
	double podajProcent() const noexcept;
	double podajKwotaMin() const noexcept;
	double podajKwotaMax() const noexcept;
	int podajID() const noexcept;
	int podajDzialalnosc() const noexcept;

	void edytuj(std::istream& input, std::ostream& output);
	void edytujNazwe(std::istream& input, std::ostream& output);
	void edytujProcent(std::istream& input, std::ostream& output);
	void edytujKwotaMin(std::istream& input, std::ostream& output);
	void edytujKwotaMax(std::istream& input, std::ostream& output);
	void edytujRodzajDzialalnosci(std::istream& input, std::ostream& output);
	void pokaz(std::ostream& output);
	Podatek(std::istream& input, std::ostream& output);
	Podatek(std::string nz, double pr, int rodzaj = 0, double k_min = 0,
		double k_max = std::numeric_limits<double>::max())
		: nazwa(nz), procent(pr), kwota_min(k_min), kwota_max(k_max), rodzaj_dzialalnosci(rodzaj)
	{
		ID = liczbaID;
		liczbaID++;
	}
	bool operator==(const Podatek& p) const noexcept;
};