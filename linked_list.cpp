#include<iostream>
#include<string>

using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T>* link;

	Node() :link(nullptr) {}
	Node(T& data) :data(data), link(nullptr) {}
	Node(T& data, Node<T>* link) :data(data), link(link) {}
};

template <class T>
class Chain {
private:
	Node<T>* head;
	int size;
public:
	Chain() :head(nullptr), size(0) {}
	bool IsEmpty() {
		if (size == 0)return true;
		else return false;
	}

	void print() {

		Node<T>* current = head;
		while (current) {
			cout << current->data << "->";
			current = current->link;
		}
		cout << "NULL" << endl;
	}

	void Insert(int index, T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (index == 0) {
			newNode->link = head;
			head = newNode;
		}
		else {
			Node<T>* current = head;
			for (int i = 0; i < index - 1; i++)current = current->link;
			newNode->link = current->link;
			current->link = newNode;
		}
		size++;
	}

	void Delete(int index) {
		Node<T>* toDelete = nullptr;
		if (index == 0) {
			toDelete = head;
			head = head->link;
		}
		else {
			Node<T>* current = head;
			for (int i = 0; i < index - 1; i++) current = current->link;
			toDelete = current->link;
			current->link = toDelete->link;
		}
		delete toDelete;
		size--;
	}
};

int main() {
	int index, value;
	Chain<int> list;
	char command;
	while (cin >> command) {
		switch (command) {
		case 'E':
			if (list.IsEmpty())cout << "True" << endl;
			else cout << "false" << endl;
			break;
		case 'P':
			list.print();
			break;
		case 'I':
			cin >> index >> value;
			list.Insert(index, value);
			break;
		case 'D':
			cin >> index;
			list.Delete(index);
			break;
		default:
			break;
		}
	}
}