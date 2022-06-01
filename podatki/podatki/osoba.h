#pragma once
#include <string>
#include <iostream>

class Osoba {
protected:
	static int liczbaID;
	int ID;
	int rodzaj_dzialalnosci;
	std::string adres;
public:
	int podajID() const noexcept;
	int podajDzialalnosc() const noexcept;
	std::string podajAdres() const noexcept;
	void edytujAdres(std::istream& input, std::ostream& output);
	void edytujRodzajDzialalnosci(std::istream& input, std::ostream& output);
	virtual void pokaz(std::ostream& output) = 0;
	virtual void edytuj(std::istream& input, std::ostream& output) = 0;
	bool operator==(const Osoba& o) const noexcept;
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
	void edytujImie(std::istream& input, std::ostream& output);
	void edytujNazwisko(std::istream& input, std::ostream& output);
	void edytujPesel(std::istream& input, std::ostream& output);
	OsobaFizyczna(std::istream& input, std::ostream& output);
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
	void edytujNazwe(std::istream& input, std::ostream& output);
	void edytujNIP(std::istream& input, std::ostream& output);
	OsobaPrawna(std::istream& input, std::ostream& output);
};