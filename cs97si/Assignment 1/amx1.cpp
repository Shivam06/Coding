#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;

class customer {
public:
	int trans_count;
	int total_spend;
	float tip_perc;
	int tip_amount;

	customer() {
		trans_count = 0;
		total_spend = 0;
		tip_amount = 0;
		tip_perc = 0;
	}
};

unordered_map<string, int> hash_cust_id;

int main() {
	int A, B, C;
	cin>>A;
	string hash_rest[A];
	int restraunts[A];
	vector<customer> customers_details;
	
	for (int i; i < A; i++) {
		cin>>hash_rest[i]>>restraunts[i];
	}

	cin>>B;
	string c_id, r_id, date, time;
	int amount;
	
	for(int i = 0; i< B; i++) {
		cin>>
	}

	cin>>C;

	for(int i = 0; i < C; i++) {

	}

	return 0;
}