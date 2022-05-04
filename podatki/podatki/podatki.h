#pragma once
enum WALUTA {
	PLN = 100,
	EUR = 470,
	USD = 450,
};

class Urzad {};

class Kwota {
private:
	double wartosc;
	WALUTA waluta;
public:
	Kwota(const double& war = 0, const WALUTA& wal = PLN) : wartosc(war), waluta(wal) {};
	double get() const noexcept {
		return wartosc * waluta / 100;
	}
};

class Faktura {
private:
	static int liczbaID;
	int ID;
	int osoba;
	Kwota kwota;
public:
	Faktura(const int& os, const Kwota& kw) : osoba(os), kwota(kw) {
		ID = liczbaID;
		liczbaID++;
	};
	double get() const noexcept {
		return kwota.get();
	}
	int getID() const noexcept {
		return ID;
	}
};

int Faktura::liczbaID = 1;

class Osoba {};

class OsobaFizyczna : public Osoba {};

class OsobaPrawna : public Osoba {};

class Dzialalnosc {};

class Podatek {};

class Kontener {};
