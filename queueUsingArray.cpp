#include<iostream>
using namespace std;

class queue{
	int front;
	int top;
	int* arr;
	int size;
	public:
		
		queue(int s){
			size= s;
			arr = new int[size];
			front = -1;
			top = front;
		}
		
		void push(int data);
	    void pop();
	    int peek();
	    bool isempty();
	    bool isfull();
};

int main()
{
   queue q(4);
   q.pop();
   cout<<q.peek()<<endl;
   q.push(29);
   q.push(31);
   q.push(90);
   q.push(7);
   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();
   return 0;	
}

void queue::push(int data)
{
	if(!isfull())
	{
		if(front==-1)
			front++;
		
		arr[++top] = data;
		cout<<"Element pushed"<<endl;
	}
	else
	{
		cout<<"Queue is full"<<endl;
	}
	cout<<top<<" "<<front<<endl;
}
 
void queue::pop(){
	if(!isempty())
	{
	    front++;
	    cout<<"Element popped"<<endl;
	}
	else
	{
		cout<<"Queue is empty"<<endl;
	}
	
	if(top<front)
	    {
	    	front = -1;
	    	top=-1;
		}
	cout<<top<<" "<<front<<endl;
}

int queue::peek(){
    if(!isempty())
    {
    	return arr[front];
	}
	else
	{
		cout<<"Queue is empty"<<endl;
		return -1;
	}
}

bool queue::isfull()
{
	if(top == size-1)
	{
		return true;
	}
	else
	    return false;
}

bool queue::isempty()
{
	if(top==front && top==-1)
	{
		return true;
	}
	else
	    return false;
}
