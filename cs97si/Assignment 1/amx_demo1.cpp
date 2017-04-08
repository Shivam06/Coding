#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct node {
    int data, lower_limit, upper_limit;
    node* left;
    node* right;
};

node* construct_node() {
    node* newnode = new node;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void construct_seg_tree(node*& head, int arr[], int start, int end) {
    
    head->lower_limit = start;
    head->upper_limit = end;

    if (start >= end) {
        head->data = arr[start];
        return;
    }

    int mid = (start + end)/2;
    head->left = construct_node();
    head->right = construct_node();
    construct_seg_tree(head->left, arr, start , mid);
    construct_seg_tree(head->right, arr, mid + 1, end);
    
    head->data = min(head->left->data, head->right->data);
}   

int find_min(node* head, int l, int u) {
    if (head->lower_limit >= l && head->upper_limit <= u)
        return head->data;

    else if (head->lower_limit > u ||  head->upper_limit < l)
        return INT_MAX;

    else 
        return min(find_min(head->left, l, u), find_min(head->right, l, u));
}

void update_seg_tree(node*& head, int idx, int d2) {
    
    if (head->lower_limit == idx && head->upper_limit == idx){
        head->data = d2;
        return;
    }

    int mid = (head->lower_limit + head->upper_limit)/2;
    if (idx <= mid)
        update_seg_tree(head->left, idx, d2);
    else
        update_seg_tree(head->right, idx, d2);

    head->data = min(head->left->data, head->right->data);
}

void update(int arr[], node*& head, int idx, int d2) {
    arr[idx] = d2;
    update_seg_tree(head, idx, d2);
}

void delete_seg_tree(node*& head, int idx) {
    
}

int main()
{
    int T;
    int a, b;
    char type;
    vector<int> v;
    cin>>T;
    
    for (int i = 0; i<T; i++) {
        cin>>type;
        
        if (type == 'i') {
            scanf("%d",&a);
            v.push_back(a);   // constant amortized                         --                    constant
        }
        
        else if (type == 'd') {
            scanf("%d",&a);
            int tmp = v[a -1];
            for (int i = a; i<v.size(); i++)
                v[i-1] = v[i];               
            v.erase(v.end()-1);
        }
        
        else if (type == 'q') {
            scanf("%d%d",&a,&b);
            int min = *min_element(v.begin() + a - 1, v.begin() + b);
            cout << min << endl;
        }
        
        else if (type == 'u') {
            scanf("%d%d",&a,&b);
            v[a - 1] = b;            // constant
        }
    }
    
    return 0;
}
