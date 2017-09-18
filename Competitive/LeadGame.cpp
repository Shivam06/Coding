#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int main() {
	int N, A, B, winner = 0, max_winner, lead, max_lead = INT_MIN, sum_A=0, sum_B=0;
	cin>>N;

	for (int i = 0; i < N; i++) {
		cin>>A>>B;
		sum_A += A;
		sum_B += B;
		if (sum_A>sum_B) 
			winner = 1;
		else
			winner = 2;
		lead = abs(sum_A-sum_B);
		if (lead > max_lead) {
			max_lead = lead;
			max_winner = winner;
		}
	}

	cout << max_winner << " " << max_lead;
	return 0;
}