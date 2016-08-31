#include<iostream>
using namespace std;



class stack{
	
	struct node{
		int data;
		node* link;
		int min;
	};
	
	node* head;
	
	public:
		stack()
		{
			head = NULL;
		}
        
        void push(int data)
        {
        	node* newnode = new node;
        	newnode->data = data;
        	newnode->link = head;
        	
        	if(head!= NULL)
        	{
        	if(data < head->min)
        	{
        		newnode->min = data;
			}
			else
			{
				newnode->min = head->min;
			}
		    }
			else
			{
				newnode->min = data;
			} 
        	head = newnode;
        	cout<<"Element pushed"<<endl;
		}
		
		void pop(){
			if(!isempty())
			{
			node* temp = head;
			head = head->link;
			delete temp;
			cout<<"Element popped"<<endl;
		    }
		    else
		    {
		    	cout<<"Stack is empty"<<endl;
			}
		}
		
		int peak(){
			if(!isempty())
			{
				return head->data;
			}
			else
			{
				return -1;
			}
		}
		
		int min()
		{
			if(!isempty())
				return head->min;
			else
			{
				cout<<"Stack is empty"<<endl;
			}
		}
		
		bool isempty()
		{
			return (head==NULL? true : false);
		}
};

int main()
{
  stack s;
  s.push(23);
  cout<<"min : "<<s.min();
  s.push(12);
  cout<<"min : "<<s.min();
  s.push(15);
  cout<<"min : "<<s.min();
  s.push(32);
  cout<<"min : "<<s.min();
  cout<<s.peak()<<endl;
  s.pop();
  cout<<s.peak()<<endl;
  s.pop();
  cout<<s.peak()<<endl;
  s.pop();
  cout<<s.peak()<<endl;
  s.pop();
  cout<<s.peak()<<endl;
  
  
  
  return 0;
  	
}
