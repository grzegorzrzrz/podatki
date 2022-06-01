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
	double kwota_min, kwota_max; // zamiast typ double to Kwota?
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
	Podatek(std::string, double, double, double, int);
	bool operator==(const Podatek& p) const noexcept;
	//Kwota policz(Kwota& kwota);
};