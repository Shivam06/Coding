#include<iostream>
#include<stack>
using namespace std;

class setOfStack{
	stack<int>* s;
	int count;
	int* size;
	int maxd;
	int maxc;
	
	public:
		setOfStack(int si,int m){
			maxd = m;
			maxc = si;
			size = new int[si];   // Array which is created dynamically does not initialize itself to zero array.
			for(int i=0;i<si;i++)
			    size[i] = 0;
			count = 0;
			s = new stack<int>[si];
		}
	
		void push(int data);
		void pop();
		int peak();
		//void popAt();
		bool isempty();
		bool  isfull();
};

int main()
{
  setOfStack sos(3,2);
  sos.pop();
  sos.push(30);
  sos.push(12);
  sos.push(14);
  sos.push(19);
  sos.push(33);
  sos.push(28);
  sos.push(100);
  cout<<sos.peak()<<endl;
  sos.pop();
  return 0;
}

void setOfStack::push(int data){
	if(!isfull())
	{
		if(size[count] == maxd)
		{
			count++;
	    }
		s[count].push(data);
		size[count]++;
	    cout<<"Element Pushed"<<endl;
	}
	else
	{
		cout<<"Stack is full"<<endl;
	}
}

void setOfStack::pop(){
	if(!isempty())
	{
		s[count].pop();
		size[count]--;
		if(size[count]==0)
		{
			count--;
		}
		cout<<"Element popped"<<endl;
	}
	else
	{
		cout<<"Stack is empty"<<endl;
	}
}

int setOfStack::peak(){
	if(!isempty())
	{
		return s[count].top();
	}
	else
	{
		cout<<"Stack is empty"<<endl;
		return  -1;
	}
}

bool setOfStack::isempty(){
	if(count==0 && s[count].empty())
	{
		return true;
	}
	else
	    return false;
}

bool setOfStack::isfull(){
	if(count == maxc-1 && size[count] == maxd)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
