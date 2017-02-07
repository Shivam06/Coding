#include<iostream>
#include<vector>
using namespace std;

template<class T>
class queue{
private:
	int top, front;
	vector<T> v1;
public:
	queue() {
		top = -1;
		front = -1;
	}
	void push(T x);
	void pop();
	T front_element();
	bool isempty();
};

template<class T>
void queue<T>::push(T x) {
	if(isempty()) {
		front++;
	}
	v1.push_back(x);
	top++;
}

template<class T>
void queue<T>::pop() {
	if(!isempty()) {
		front++;
	}
	else {
		cout << "Queue is empty!" << endl;
	}
}

template<class T>
T queue<T>::front_element() {
	if (!isempty()) {
		return v1[front];
	}
	else {
		cout << "Queue is empty!" << endl;
		return '?';
	}
}

template<class T>
bool queue<T>::isempty() {
	if(front == top + 1 || front == -1) {
		return true;
	}
	else
		return false;
}

int main() {
	queue<char> q;
	q.push('s');
	q.push('h');
	q.push('i');
	cout << q.front_element() << endl;
	q.pop();
	cout << q.front_element() << endl;
	q.pop();
	cout << q.front_element() << endl;
	q.pop();
	cout << q.front_element() << endl;
	return 0;
}