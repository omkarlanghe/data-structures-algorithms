#include <iostream>
#define MAX 1000

using namespace std;

class Stack {
	int top;

	public:
	int arr[MAX];

	Stack() { top = -1; }
};

bool Stack::push (int ele) {
	if(top > MAX - 1) {
		cout << "Stack is full" << endl;
		return (false);
	}

	arr[++top] = ele;
	cout << ele << " pushed into the stack" << endl;
	return (true);
}

int Stack::pop () {
	if(top < 0) {
		cout << "Stack is empty! Cannot pop" << endl;
		return (false);
	}
	int top = arr[top--];
	return (top);
	// return (arr[top--]);
}

int Stack::peep () {
	if(top < 0) {
		cout << "Stack is empty" << endl;
		return (0);
	}

	int peep = arr[top];
	return (peep);
}

bool Stack::isEmpty () {
	return (top < 0);
}

void Stack::display () {
	for(int i = 0 ; i < top ; i++) {
		cout << arr[i] << " ";
	}
}

int main () {
	Stack s;
	int element = 0, limit = 0;
	
	cout << "Enter the total number of elements in stack" << endl;
	cin >> limit;

	for(int i = 0 ; i < limit ; i++) {
		cout << "Enter " << i+1 << "st Element in stack" << endl;
		cin >> element;
		s.push(element);
	}

	cout << "Stack elements :: " << endl;
	s.display();
	return (0);
}
