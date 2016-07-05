#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

	
class tree{
    node* head;
    int find_height(node* h){
    	if(h == NULL)
    	    return -1;
    	
        else
            return max(find_height(h->left),find_height(h->right)) + 1;
	}
    
    void insertHelp(node*& head,int x){
			
		if(head== NULL)
		{
			head = new node;
			head->data = x;
			head->left = NULL;
			head->right = NULL;
			return;
		}
			
		if(head->data >= x){
			insertHelp(head->left,x);
		}
		else
		{
			insertHelp(head->right,x);
		}
		
		if(difference(head) <=1 && difference(head)>=-1)
		{
			return;
		}
		else
		{
			avl_rotation(head);
		}
	}
	
	void inTravHelp(node* h){
		if(h==NULL)
		{
			return;
		}
		
		inTravHelp(h->left);
		cout<<h->data<<"  ";
		inTravHelp(h->right);
	}

	int difference(node* h){
		return find_height(h->left) - find_height(h->right) +1;
	}
	
	void shift_right(node*& h){
		node* temp = h->left->right;
		h->left->right = h;
		node* temp1 = h->left;
		h->left = temp;
		h = temp1;
	}
    
	void shift_left(node*& h)
	{
		node* temp = h->right->left;
		h->right->left = h;
		h->right = temp;
	 } 
	 
	bool findData(node* h,int x){
		if(h->data==x){
				return 1;
			}
		if(h==NULL)
		{
			return 0;
		}
		
		if(h->data>x){
			return findData(h->left,x);
		}
		
		else
		{
			return findData(h->right,x);
		}
	}
	
	void avl_rotation(node*&head){
		if(difference(head)>0 && difference(head->left)>0){
				shift_right(head);
			}	
		else if(difference(head)>0 && difference(head->left)<0){
				shift_left(head->left);
				shift_right(head);
			}
		else if(difference(head)<0 && difference(head->right)<0){
				shift_left(head);
			}
		else{
				shift_right(head->right);
				shift_left(head);
			}
	}
    public:
    	tree(){
    		head = NULL;
		}
		
		int height(){
		    return find_height(head);	
		}
		
		void insert(int x){
			insertHelp(head,x);
		}
		
		void inorder_traversal(){
			inTravHelp(head);
		}
		
		bool find(int x){
			return findData(head,int x);
		}
		
		void deleteNode(int x){
			
			if(find(x)){
				cout<<"Can't find the speccified data in your tree."<<endl;
			}
		 	else{
		 		if(h->data==x){
		 	    delete h;
		 	    h=NULL;
				return;
				}
		
				if(h->data>x){
					 find(h->left);
				}
		
				else
				{
					 find(h->right);
				}	
				
				if(difference(h)<=1 && difference(h)>=-1){
					return;
				}	
				
				else
				{
					avl_rotation(h);
				} 
		}
	}
		
};

int main(){
	tree t1;
	t1.insert(10);
	t1.insert(20);
	t1.insert(30);
	t1.insert(40);
	t1.insert(50);
	t1.insert(25);
	t1.inorder_traversal();
	cout<<endl;
	cout<<t1.height()<<endl;
	return 0;
}
