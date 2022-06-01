#pragma once
#include <string>
#include <iostream>

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
	bool operator==(const Dzialalnosc& p) const noexcept;
};