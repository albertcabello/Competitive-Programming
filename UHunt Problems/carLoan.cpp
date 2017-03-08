#include<iostream>
using namespace std;
int main() {
	double owed, value, payment, down;
	int termLength, countGiven, count=0;
	cin >> termLength >> down >> value >> countGiven;
	int month, nextMonth;
	double interest;
	while (termLength > 0) {
		owed = value;
		payment = value / termLength;
		value += down;
//		cout << "Term Length: " << termLength << endl;
		cin >> month;
		for (int i = 0; i < countGiven-1; i++) {
			cin >> interest >> nextMonth;
			int j = month;

			while (j < nextMonth) {
//				cout << "Month: " << j << " Corresponding Interest: " << interest << endl;
				/*count++;
				j++; */
				
				if (j == 0) {
					j++;
					value *= (1-interest);
					//cout << "Month: " << j << " Owed: " << owed << " Worth: " << value << endl;
					if (owed <= value) {
						//cout << "Inside if statement to break" << endl;
						break;
					}
				}
				else {
					count++;
					j++;
					owed -= payment;
					value *= (1-interest);
				//	cout << "Month: " << j << " Owed: " << owed << " Worth: " << value << endl;
					
				}
			} 
			month = nextMonth;
		}
		cin >> interest;
//		cout << "Interest for any further months: " << interest << endl;
		while (owed >= value) {
			count++;
			owed -= payment;
			value *= (1-interest);
		//	cout << "AMonth: " << count << " Owed: " << owed << " Worth: " << value << endl;

		}
		if (count == 1) {
			cout << "1 month" << endl;
		}
		else {
			cout << count << " months" << endl;
		}
//		cout << "FINAL ANSWER FOR THIS TEST CASE: " << count << endl;
		count = 0;
		cin >> termLength >> down >> value >> countGiven;
	}

	return 0;
}
