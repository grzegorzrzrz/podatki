#include "pch.h"
#include "framework.h"
#include "urzad.h"
#include "conio.h"
void Urzad::obsluz(std::istream& input, std::ostream& output) {
	system("CLS");
	output << "URZAD PODATKOWY" << std::endl;
	output << "Wybierz dzial:" << std::endl;
	output << "1. Faktury" << std::endl;
	output << "2. Osoby" << std::endl;
	output << "3. Dzialalnosci" << std::endl;
	output << "4. Podatki" << std::endl;
	output << "5. Policz podatek" << std::endl;
	output << "6. Wyjscie z programu" << std::endl;
	int wybor;
	input >> wybor;
	switch (wybor)
	{
	case 1:
		obsluzFaktury(input, output);
		break;
	case 2:
		obsluzOsoby(input, output);
		break;
	case 3:
		obsluzDzialalnosci(input, output);
		break;
	case 4:
		obsluzPodatki(input, output);
		break;
	case 5:
		system("CLS");
		output << "Podaj ID osoby:" << std::endl;
		input >> wybor;
		output << "Wyliczony podatek: ";
		output << policzPodatek(wybor);
		_getch();
		break;
	case 6:
		koniecProgramu = true;
		break;
	}
}

void Urzad::obsluzFaktury(std::istream& input, std::ostream& output) {
	system("CLS");
	output << "Co chcesz zrobic?:" << std::endl;
	output << "1. Dodaj fakture" << std::endl;
	output << "2. Edytuj fakture" << std::endl;
	output << "3. Usun fakture" << std::endl;
	output << "4. Pokaz fakture" << std::endl;
	output << "5. Pokaz wszystkie faktury" << std::endl;
	output << "6. Wstecz" << std::endl;
	int wybor;
	bool koniec;
	do
	{
		koniec = true;
	input >> wybor;
	switch (wybor)
	{
	case 1: {
		Faktura* faktura = new Faktura(input, output);
		faktura->pokaz(output);
		faktury.dodaj(*faktura);
		break;
	}
	case 2:
		system("CLS");
		output << "Podaj ID faktury:" << std::endl;
		input >> wybor;
		faktury.edytuj(wybor, input, output);
		break;
	case 3:
		system("CLS");
		output << "Podaj ID faktury:" << std::endl;
		input >> wybor;
		faktury.usun(wybor);
		break;
	case 4:
		system("CLS");
		output << "Podaj ID faktury:" << std::endl;
		input >> wybor;
		faktury.pokaz(wybor, output);
		break;
	case 5:
		faktury.pokaz(output);
		break;
	case 6:
		break;
	default:
		koniec = false;
	}
	} while (koniec == false);
}

void Urzad::obsluzOsoby(std::istream& input, std::ostream& output) {
	system("CLS");
	output << "Co chcesz zrobic?:" << std::endl;
	output << "1. Dodaj osobe" << std::endl;
	output << "2. Edytuj osobe" << std::endl;
	output << "3. Usun osobe" << std::endl;
	output << "4. Pokaz osobe" << std::endl;
	output << "5. Pokaz wszystkie osoby" << std::endl;
	output << "6. Wstecz" << std::endl;
	int wybor;
	bool koniec;
	do
	{
		koniec = true;
	input >> wybor;
	switch (wybor)
	{
	case 1: {
		system("CLS");
		output << "Wybierz rodzaj osoby:" << std::endl;
		output << "1. Osoba fizyczna" << std::endl;
		output << "2. Osoba prawna" << std::endl;
		input >> wybor;

		switch (wybor)
		{
		case 1: {
			Osoba* osoba = new OsobaFizyczna(input, output);
			osoba->pokaz(output);
			osoby.dodaj(*osoba);
			break;
		}
		case 2: {
			Osoba* osoba = new OsobaPrawna(input, output);
			osoba->pokaz(output);
			osoby.dodaj(*osoba);
			break;
		}
		}
	}
	case 2:
		system("CLS");
		output << "Podaj ID osoby:" << std::endl;
		input >> wybor;
		osoby.edytuj(wybor, input, output);
		break;
	case 3:
		system("CLS");
		output << "Podaj ID osoby:" << std::endl;
		input >> wybor;
		osoby.usun(wybor);
		break;
	case 4:
		system("CLS");
		output << "Podaj ID osoby:" << std::endl;
		input >> wybor;
		osoby.pokaz(wybor, output);
		break;
	case 5:
		osoby.pokaz(output);
		break;
	case 6:
		koniec=true;
		break;
	}
	} while (koniec == false);
}

void Urzad::obsluzDzialalnosci(std::istream& input, std::ostream& output) {
	system("CLS");
	output << "Co chcesz zrobic?:" << std::endl;
	output << "1. Dodaj dzialalnosc" << std::endl;
	output << "2. Edytuj dzialalnosc" << std::endl;
	output << "3. Usun dzialalnosc" << std::endl;
	output << "4. Pokaz dzialalnosc" << std::endl;
	output << "5. Pokaz wszystkie dzialalnosci" << std::endl;
	output << "6. Wstecz" << std::endl;
	int wybor;
	bool koniec;
	do
	{
		koniec = true;
	input >> wybor;
	system("CLS");
	switch (wybor)
	{
	case 1: {
		Dzialalnosc* dzialalnosc = new Dzialalnosc(input, output);
		dzialalnosc->pokaz(output);
		dzialalnosci.dodaj(*dzialalnosc);
		break;
	}
	case 2:
		output << "Podaj ID dzialalnosci:" << std::endl;
		input >> wybor;
		dzialalnosci.edytuj(wybor, input, output);
		break;
	case 3:
		output << "Podaj ID dzialalnosci:" << std::endl;
		input >> wybor;
		dzialalnosci.usun(wybor);
		break;
	case 4:
		output << "Podaj ID dzialalnosci:" << std::endl;
		input >> wybor;
		dzialalnosci.pokaz(wybor, output);
		break;
	case 5:
		dzialalnosci.pokaz(output);
		break;
	case 6:
		koniec == true;
		break;
	}
	} while (koniec == false);
}

void Urzad::obsluzPodatki(std::istream& input, std::ostream& output) {
	system("CLS");
	output << "Co chcesz zrobic?:" << std::endl;
	output << "1. Dodaj podatek" << std::endl;
	output << "2. Edytuj podatek" << std::endl;
	output << "3. Usun podatek" << std::endl;
	output << "4. Pokaz podatek" << std::endl;
	output << "5. Pokaz wszystkie podatki" << std::endl;
	output << "6. Wstecz" << std::endl;
	int wybor;
	bool koniec;
	do
	{
		koniec = true;
	input >> wybor;
	system("CLS");
	switch (wybor)
	{
	case 1: {
		Podatek* podatek = new Podatek(input, output);
		podatek->pokaz(output);
		podatki.dodaj(*podatek);
		break;
	}
	case 2:
		output << "Podaj ID podatku:" << std::endl;
		input >> wybor;
		podatki.edytuj(wybor, input, output);
		break;
	case 3:
		output << "Podaj ID podatku:" << std::endl;
		input >> wybor;
		podatki.usun(wybor);
		break;
	case 4:
		output << "Podaj ID podatku:" << std::endl;
		input >> wybor;
		podatki.pokaz(wybor, output);
		break;
	case 5:
		podatki.pokaz(output);
		break;
	case 6:
		koniec == true;
		break;
	}
	} while (koniec == false);
}

Kwota Urzad::policzPodatek(const int& id) {
	double suma = 0, doZaplaty = 0;
	for (auto faktura : faktury.podaj()) {
		if (faktura.podajOsobe() == id)
			suma += faktura.podajKwote();
	}
	for (auto podatek : podatki.podaj()) {
		if (podatek.podajDzialalnosc() == osoby.podaj(id).podajDzialalnosc() || podatek.podajDzialalnosc() == 0)
			if (suma - podatek.podajKwotaMin() > 0)
				doZaplaty += (suma < podatek.podajKwotaMax() ? suma : podatek.podajKwotaMax()) * podatek.podajProcent();
	}
	return doZaplaty;
}

void Urzad::dodajPrzykladoweDane()
{
	dzialalnosci.dodaj(*new Dzialalnosc("Indywidualna dzialalnosc gospodarcza"));
	dzialalnosci.dodaj(*new Dzialalnosc("Spolka cywilna"));

	osoby.dodaj(*new OsobaFizyczna(1,"ul. Lwowska 142, 42-400, Zawiercie","Jan","Kowalski","89030576819"));
	osoby.dodaj(*new OsobaPrawna(2, "ul. Mikolajska 59, 31-027, Krakow","Grunt spolka cywilna","8383403794"));

	podatki.dodaj(*new Podatek("Podatek dla spolek cywilnych",19, 2));
	podatki.dodaj(*new Podatek("Podatek dla indywidualnych dzialalnosci gospodarczych", 17,1,0,10000));
	podatki.dodaj(*new Podatek("Podatek za zarabianie za malo", 21, 1, 100, 10000));
	podatki.dodaj(*new Podatek("Podatek dla kazdego", 5, 0));
	Kwota a(9990);
	Kwota b(10001231);
	Kwota c(1000000);
	faktury.dodaj(*new Faktura(1,a));
	faktury.dodaj(*new Faktura(2,b));
	faktury.dodaj(*new Faktura(2,c));
}
