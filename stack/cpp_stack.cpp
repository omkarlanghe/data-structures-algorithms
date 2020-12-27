#include <iostream>
#define MAX 1000

using namespace std;

class Stack {
	int top;

	public:
	int arr[MAX];

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peep();
	bool isEmpty();
	void display();
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
		return (0);
	} else {
		int top = arr[top--];
		cout << " ==============>>>> " << top << endl;
		return (top);
		// return (arr[top--]);
	}
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
	for(int i = 0 ; i <= top ; i++) {
		cout << arr[i] << endl;
	}
}

int main () {
	Stack s;
	// int element = 0, limit = 0;
	
	/* cout << "Enter the total number of elements in stack" << endl;
	cin >> limit;

	for(int i = 0 ; i < limit ; i++) {
		cout << "Enter " << i+1 << "st Element in stack" << endl;
		cin >> element;
		s.push(element);
		cout << "-------------" << endl;
	} */

	s.push(10);
    	s.push(20);
    	s.push(30);
    	cout << s.pop() << " Popped from stack\n";


	//cout << "Stack elements :: " << endl;
	//s.display();

	//cout << "Poped element is " << s.pop() << endl;
	//cout << "Stack elements ::" << endl;
	//s.display();

	return (0);
}
