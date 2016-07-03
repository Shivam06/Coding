#include<iostream>
using namespace std;

class stack{
	private :
		int top;
	    int* arr;
	    int size;
	public:
		stack(int s){
			top = -1;
			size = s;
			arr = new int[size];
		}
		void push(int data);
		void pop();
		int isempty();
		int isfull();
		int peek();	
};

int main()
{
	stack s(4);
	s.pop();
	s.pop();
	s.push(34);
	s.push(27);
	s.push(23);
	s.push(12);
	s.push(11);
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.peek()<<endl;
    return 0;
}

void stack:: push(int data){
	if(isfull())
	{
	   cout<<"No scope to push more."<<endl;	
	}
	else
	{
       	arr[++top] = data;	
       	cout<<"data pushed"<<endl;
	}
	//cout<<top<<endl;
}

void stack:: pop(){
	if(isempty())
	{
	    cout<<"Stack is empty"<<endl;
	}
	else
	{
		arr[top--] = 0;
		cout<<"data popped"<<endl;
	}
	//cout<<top<<endl;
}

int stack::peek()
{
	if(!isempty())
	    return arr[top];
}

int stack:: isempty(){
	if(top==-1)
	    return 1;
	else
	    return 0;
}

int stack:: isfull(){
	if(top == size-1)
	    return 1;
	else
	    return 0;
}
