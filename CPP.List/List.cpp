#include "List.h"
#include <string>
#include <iostream>

using namespace std;

Node::Node(char value) {

	next = nullptr;
	prev = nullptr;

	this->value = value;

}

List::List(string alphabet) {

	root = nullptr;
	tail = nullptr;

	count = 0;

	this->alphabet = alphabet;

}

void List::AddNode(char value, int pos) {

	if (pos < 0 || pos > count) {

		cout << "Не удалось добавить элемент на позицию " << pos << endl;

		return;

	}

	Node* node = new Node(value);

	if (root == nullptr) {

		root = node;
		tail = node;

	}
	else if (pos == count) {

		Node* last = tail;

		node->prev = last;
		last->next = node;

		tail = node;

	}
	else if (pos == 0) {

		Node* first = root;

		first->prev = node;
		node->next = first;

		root = node;

	}
	else {

		int counter = 0;

		Node* current = root;

		while (counter != pos) {

			current = current->next;

			counter++;

		}

		current->prev->next = node;

		node->next = current;
		node->prev = current->prev;

		current->prev = node;

	}

	count++;

}

void List::Print() {

	Node* current = root;

	if (root == nullptr) {

		cout << "Список пуск" << endl;

		return;

	}

	while (current != nullptr) {

		cout << current->value << " ";

		current = current->next;

	}

	cout << endl;

}

void List::Delete(int pos) {

	if (pos < 0 || pos > count || root == nullptr) {

		cout << "Не удалось удалить элемент на позиции " << pos << endl;

		return;

	}

	if (pos == count - 1) {

		Node* last = tail->prev;

		if (last != nullptr) {

			last->next = nullptr;

			tail->prev = nullptr;
			tail->next = nullptr;

			delete tail;

			tail = last;

		}
		else {

			delete tail;

			root = nullptr;
			tail = nullptr;

		}

	}
	else if (pos == 0) {

		Node* first = root->next;
		first->prev = nullptr;

		root->next = nullptr;
		root->prev = nullptr;

		delete root;

		root = first;

	}
	else {

		int counter = 0;

		Node* current = root;

		while (counter != pos) {

			current = current->next;

			counter++;

		}

		Node* left = current->prev;
		Node* right = current->next;

		delete current;

		left->next = right;
		right->prev = left;

		if (left->prev == nullptr)
			root = left;

		if (right->next == nullptr)
			tail = right;

	}

	count--;

}

void List::ExcludeByAlphabet() {

	bool isClear = false;

	while (!isClear) {

		Node* current = root;

		bool nodeDeleted = false;

		for (int i = 0; i < count; i++) {

			char value = current->value;

			if (alphabet.find(value) != string::npos) {

				this->Delete(i);

				nodeDeleted = true;

				break;

			}

			current = current->next;

		}

		if (!nodeDeleted)
			isClear = true;

	}

}