#pragma once
#include "lista.h"

template<typename T>
class Kontener {
private:
	List<T> lista = {};
public:
	Kontener() = default;
	~Kontener() {
		for (auto& it : lista) {
			delete& it;
		}
	}
	void dodaj(const T& cos) noexcept {
		lista.pushBack(cos);
	}
	void edytuj(const int& id, std::istream& input, std::ostream& output) noexcept {
		for (auto cos = lista.begin(); cos != lista.end(); cos++)
			if (cos->podajID() == id) {
				cos->edytuj(input, output);
				break;
			}
	}
	void usun(const int& id) noexcept {
		for (auto cos = lista.begin(); cos != lista.end(); cos++)
			if (cos->podajID() == id) {
				lista.erase(*cos);
				break;
			}
	}
	void pokaz(const int& id, std::ostream& output) const noexcept {
		for (auto cos = lista.begin(); cos != lista.end(); cos++)
			if (cos->podajID() == id) {
				cos->pokaz(output);
				break;
			}
	}
	void pokaz(std::ostream& output) const noexcept {
		for (auto cos = lista.begin(); cos != lista.end(); cos++)
			cos->pokaz(output);
	}
	T podaj(const int& id) const noexcept {
		for (auto cos = lista.begin(); cos != lista.end(); cos++)
			if (cos->podajID() == id) 
				return *cos;
	}
	List<T> podaj() const noexcept {
		return lista;
	}
};