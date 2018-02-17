#include<iostream>
using namespace std;
int main() {
	int count;
	cin >> count;
	while (count--) {
		int num;
		cin >> num;
		int first;
		bool found = false;
		for (int i = 0; i < num; i++) {
			int cur;
			cin >> cur;
			if (i == 0) {
				first = cur;
				continue;
			}
			if (first + i != cur && !found) {
				cout << i+1 << endl;
				found = true;
			}
		}	
	}
	return 0;
}

				
			
