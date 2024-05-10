#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		next = NULL;
	}
};

class Stack {
private:
	Node* top;

public:
	Stack() {
		top = NULL;
	}

	int push(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next= top;
		top = newNode;
		cout << "Push value: " << value << endl;
		return value;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty." << endl;
		}
		cout << "Popped value: " << top->data << endl;
		top = top->next;
	}

	void peek() {
		if (top == NULL) {
			cout << "List is empty. " << endl;
		}
		else {
			Node* current = top;
			while (current != NULL) {
				cout << current->data << "" << endl;
				current = current->next;
			}
			cout << endl;
		}
	}

	bool isEmpty() {
		return top == NULL;
	}
};

int main() {
	Stack stack;

	int choice = 0;
	int value;

	while (choice != 5) {
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Peek\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			stack.push(value);
			break;
		case 2:
			if (!stack.isEmpty()) {
				stack.pop();
			}
			else {
				cout << "Stack is empty. Cannot pop." << endl;
			}
			break;
		case 3:
			if (!stack.isEmpty()) {
				stack.peek();
			}
			else {
				cout << "Stack is empty. No top value." << endl;
			}
			break;
		}
	}
}