#include<iostream>
#include<list>
using namespace std;

class animal_house{
	list <int> cat;
	list <int> dog;
	int count;
	
	public:
		animal_house(){
			count = 0;
		}
		
		void enqueue(char c){
			if(c=='c'){
				cat.push_back(++count);
				cout<<"Cat pushed"<<endl;
			}
			else
			{
				dog.push_back(++count);
				cout<<"Dog pushed"<<endl;
			}
		}
		
		void dequeue_cat(){
			if(!cat.empty())
			{
				cat.pop_front();
				cout<<"Cat popped"<<endl;
			}
			else
			{
				cout<<"Sorry no cat available for sale. You can try our well built dogs"<<endl;
			}
		}
		
		void dequeue_dog(){
			if(!dog.empty())
			{
				dog.pop_front();
				cout<<"Dog popped"<<endl;
			}
			else
			{
				cout<<"Sorry no dogs. Try cute cats"<<endl;
			}
		}
		
		void dequeue_any(){
			if(!dog.empty() || !cat.empty()){
				if(dog.front() > cat.front()){
					if(!cat.empty())
					{
					cat.pop_front();
					cout<<"cat popped"<<endl;
				    }
				    else
				    {
				    	dog.pop_front();
				        cout<<"dog popped"<<endl;
					}
				}
				else{
					if(!dog.empty())
					{
						dog.pop_front();
						cout<<"dog popped"<<endl;
				    }
				    else
				    {
				    	cat.pop_front();
				    	cout<<"cat popped"<<endl;
					}
				}
			}
			else{
				cout<<"No animal available. Try after few days."<<endl;
			}
		}
};

int main(){
	animal_house house;
	house.enqueue('c');
	house.enqueue('c');
	house.enqueue('d');
	house.enqueue('c');
	house.dequeue_any();
	house.dequeue_any();
	house.dequeue_any();
	house.dequeue_any();
	house.dequeue_any();
	house.dequeue_any();
	return 0;
}
