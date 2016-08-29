#include <iostream>
using namespace std;

int count(char tictac[]) {
    int countX = 0;
    int countO = 0;
    for (int i = 0; i<9; i++) {
        if (tictac[i] == 'X')
            countX ++;
        else
            countO++;
    }
    if (countX == 5)
        return 1;
    else
        return 0;
}

void check(char tictac[]) {
    int flagX = 0, flagO = 0;
    for (int i = 0; i<=6; i = i + 3) {
        if (tictac[i] == tictac[i+1] && tictac[i] == tictac[i+2]) {
            if (tictac[i] == 'X')
                flagX = 1;
            else
                flagO = 1;
        }
    }
    for (int i = 0; i <3; i++) {
        if (tictac[i] == tictac[i + 3] && tictac[i] == tictac[i+6]) {
            if (tictac[i] == 'X')
                flagX = 1;
            else
                flagO = 1;
        }
    }
    
    if (tictac[0] == tictac[4] && tictac[0] == tictac[8]) {
        if (tictac[0] == 'X')
                flagX = 1;
            else
                flagO = 1;
    }
    
    if (tictac[6] == tictac[4] && tictac[6] == tictac[2]) {
        if (tictac[6] == 'X')
                flagX = 1;
            else
                flagO = 1;
    }
    
    int countX = 0;
    int countO = 0;
    for (int i = 0; i<9; i++) {
        if (tictac[i] == 'X')
            countX++;
        else
            countO++;
    }
    
    if (flagX) {
        if (flagO) {
            cout << "Invalid" << endl;
            return;
        }
        if (countX == countO + 1) {
            cout <<"Valid" <<endl;
            return;
        }
        else
            cout <<"Invalid" <<endl;
        return;
    }
    if (countX != countO + 1) {
            cout <<"Invalid" <<endl;
            return;
        }
    if(flagO) {
        cout<<"Invalid"<<endl;
        return;
        if (countX == countO)
            cout <<"Valid"<<endl;
        else
            cout<<"Invalid"<<endl;
        return;
    }
    
    if(!flagO && !flagX) {
        cout << "Valid" << endl;
    }
    
}

int main() {
	int T;
	char tictac[9];
	int countX = 0, countO = 0;
	cin>>T;
	char a;
	for (int i = 0; i < T; i++) {
	    for (int j = 0; j < 9; j++) {
	        cin>>tictac[j];
	    }
	   check(tictac);
	}
}
