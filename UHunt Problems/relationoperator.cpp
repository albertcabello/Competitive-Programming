//Relation Operator on UHunt

#include<iostream>
using namespace std;

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		//cout << "for loop";
		int num1;
		int num2;
		cin >> num1 >> num2;
		if (num1 > num2) {
			cout << ">"<<endl;
		}
		else if (num1 < num2) {
			cout << "<"<<endl;
		}
		else {
			cout << "="<<endl;
		}
	}
	return 0;
}
