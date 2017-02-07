#include<iostream>
#include<vector>
using namespace std;

// Make templates
template<class T>
class stack{
private:
	int top;
	vector<T> v;

public:
	stack() {
		top = -1;
	}
	void push(T x);
	void pop();
	T top_element();
	bool isempty();
};

template<class T>
void stack<T>::push(T x) {
	top++;
	v.push_back(x);
	cout << "Element Pushed" << endl;
}

template<class T>
void stack<T>::pop() {
	if (!isempty()) {
		top--;
		cout << "Element Popped" << endl;
	}
	else 
		cout << "Stack is empty" << endl;
}

template<class T>
T stack<T>::top_element() {
	if (!isempty()) {
		return v[top];
	}
	else {
		cout << "Stack Empty" << endl;
		return '?	';
	}
}

template<class T>
bool stack<T>::isempty() {
	return top == -1;
}

int main() {
	stack<char> s1;
	s1.push('s');
	s1.push('h');
	s1.push('i');
	cout << s1.top_element() << endl;
	s1.pop();
	cout << s1.top_element() << endl;
	s1.pop();
	cout << s1.top_element() << endl;
	s1.pop();
	cout << s1.top_element() << endl;
	return 0;
}