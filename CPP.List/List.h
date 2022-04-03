#pragma once
#include <string>

using namespace std;

class Node {
	public:
		char value;
		Node* next;
		Node* prev;
		Node(char value);
};

class List {
	private:
		string alphabet;
	public:
		Node* root;
		Node* tail;
		int count;
		List(string alphabet);
		void AddNode(char value, int pos);
		void Print();
		void Delete(int pos);
		void ExcludeByAlphabet();
};