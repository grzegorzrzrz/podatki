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
	OsobaFizyczna(int rodzaj_dz, std::string adr, std::string im, std::string naz, std::string pes)
		: imie(im), nazwisko(naz), pesel(pes)
	{
		rodzaj_dzialalnosci = rodzaj_dz;
		adres = adr;
		ID = liczbaID;
		liczbaID++;
	}
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
	OsobaPrawna(int rodzaj_dz, std::string adr, std::string nz, std::string nip)
		: nazwa(nz), NIP(nip)
	{
		rodzaj_dzialalnosci = rodzaj_dz;
		adres = adr;
		ID = liczbaID;
		liczbaID++;
	}
};