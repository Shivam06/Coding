#include<iostream>
using namespace std;

int min_num_of_cards(float overhang) {
	int count = 1;
	float sum = 0;
	while (sum <= overhang) {
		count++;
		sum += 1.00/float(count);
	}
	return count - 1;
}

int main() {
	float overhang = -1;
	while(1) {
		cin>>overhang;
		if (overhang != 0.00)
			cout << min_num_of_cards(overhang) << " card(s)"<<endl;
		else
			break;
	}
	return 0;
}