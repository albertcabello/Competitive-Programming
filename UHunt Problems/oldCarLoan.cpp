//Loansome car buyer UHunt problem
#include<iostream>
using namespace std;
int main() {
	int termLength, countGiven;
	double down, worth, payment, owed;
	cin >> termLength >> down  >> worth >> countGiven;
	while (termLength > 0) {
		owed = worth;
		payment = worth / termLength;
		worth += down;
		cout << "Payment: " << payment << endl;
		int month;
		double interest;
		int count = 0;
		cin >> month >> interest; //Handle the 0th month
		worth *= (1-interest);
		cout << "Owed: " << owed << " Worth: " << worth << endl;
		//Rest of months

		for (int i = 1; i < countGiven; i++) {
			double next_i;
			cin >> month >> next_i;
			while (count < month && owed > worth) {
				count++;
				cout << "mo: " << count << endl;
				owed -= payment;
				worth *= (1-interest);
				cout << "Owed: " << owed << " Worth: " << worth << " Interest: " << interest << endl;
			}
			interest = next_i;
		}
		//If the previous loop didnt find the month and all the interest rates have stopped depreciating 
		while (owed > worth) {
			count++;
			owed -= payment;
			worth *= (1-interest);
			cout << "Owed: " << owed << " Worth: " << worth << endl;
		}
		if (count == 1) {
			cout << "1 month" << endl;
		}
		else {
			cout << count << " months" << endl;
		}
		cin >> termLength >> payment >> worth >> countGiven;
		
	}

				

	return 0;
}
