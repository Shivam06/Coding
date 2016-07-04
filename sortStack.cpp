#include<iostream>
#include<stack>
using namespace std;

class mod_stack{
	stack<int> s1;
	stack<int> s2;
	
	public:
		void push(int data){
			if(!s1.empty()){
				while(!s1.empty() && s1.top()<data){  // VERY IMPORTANT - while(s1.top()<data && !s1.empty()) give run time. As if it get empty I cant access top element.
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(data);
				while(!s2.empty()){
					s1.push(s2.top());
					s2.pop();
				}
			}
			else
			{
				s1.push(data);
			}
			cout<<"Element pushed"<<endl;
		}
		
		void pop(){
			if(!s1.empty()){
				s1.pop();
				cout<<"Element popped"<<endl;
			}
			else
			{
				cout<<"No element"<<endl;
			}
		}
		
		int peak(){
			if(!s1.empty()){
				return s1.top();
			}
			else
			{
				return -1;
			}
		}
};

int main(){
	mod_stack ms;
	ms.push(34);
	ms.push(12);
	ms.push(19);
	ms.push(3);
	cout<<ms.peak()<<endl;
	ms.pop();
	cout<<ms.peak()<<endl;
	ms.pop();
	cout<<ms.peak()<<endl;
	ms.pop();
	cout<<ms.peak()<<endl;
	ms.pop();
	cout<<ms.peak()<<endl;
	ms.pop();
	return 0;
}
