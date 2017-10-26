#include<iostream>
#include<string>
using namespace std;

class animal {
protected:
	string name;
	int height, weight;

public:
	void set_name(string n) {
		name = n;
	}
	string get_name() {
		return name;
	}
	virtual string speak() = 0;
};

class Dog : public animal {
	string voice = "Bhouu Bhouu";
public:
	string speak() {
		return voice;
	}
};

class Cat : public animal {
	string voice = "Meow";
public:
	string speak() {
		return voice;
	}
};

int main() {
	Dog dog;
	Cat cat;
	animal* arr[2];
	arr[0] = &dog;
	arr[1] = &cat;
	for (int i = 0; i < 2; i++)
		cout << arr[i]->speak() << endl;
	return 0;
}