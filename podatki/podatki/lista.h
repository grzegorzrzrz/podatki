#pragma once

template<typename T>
class List {
private:
	class Node {
	public:
		T value;
		Node* next = nullptr;
		Node(const T& v) : value(v) {};
		~Node() {
			delete next;
		}
	};
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	List() = default;
	void pushBack(const T& v) {
		Node* newNode = new Node(v);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
	}
	void erase(const T& v) noexcept {
		if (head == nullptr)
			return;
		for (auto it = begin(); it != end(); it++) {
			if (it.current->next != nullptr && it.current->next->value == v) {
				it.current->next = it.current->next->next;
			}
		}
	}
	class iterator {
	private:
		Node* current;
		iterator(Node* pt) : current(pt) {};
		friend List;
	public:
		iterator& operator++() {
			if (current == nullptr)
				throw std::out_of_range("Iterator out of range.");
			current = current->next;
			return *this;
		}
		iterator& operator++(int) {
			if (current == nullptr)
				throw std::out_of_range("Iterator out of range.");
			current = current->next;
			return *this;
		}
		bool operator!=(const iterator& pt) const noexcept {
			return current != pt.current;
		};
		T operator*() const {
			if (current == nullptr)
				throw std::out_of_range("Iterator out of range.");
			return current->value;
		}
	};

	iterator begin() const noexcept {
		return iterator(head);
	}
	iterator end() const noexcept {
		return iterator(nullptr);
	}
};