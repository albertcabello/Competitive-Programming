//Division of Nlognia Uhunt Problem
#include<iostream>
using namespace std;

int main() {
	int count;
	cin >> count;
	while (count != 0) {
		int originx = 0;
		int originy = 0;
		cin >> originx >> originy;
		for (int i = 0; i < count; i++) {
			int num1 = 0;
			int num2 = 0;
			cin >> num1 >> num2;
			if (num1 == originx || num2 == originy) {
				cout << "divisa" << endl;
			}
			if (num1 > originx && num2 > originy) {
				cout << "NE"<<endl;
			}
			if (num1 > originx && num2 < originy) {
				cout << "SE"<<endl;
			}
			if (num1 < originx && num2 < originy) {
				cout << "SO" << endl;
			}
			if (num1 < originx && num2 > originy) {
				cout << "NO" << endl;
			}
		}
		cin >> count;
	}
	return 0;
}
