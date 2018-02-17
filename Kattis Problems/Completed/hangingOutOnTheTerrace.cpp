#include<iostream>
using namespace std;
int main() {
	int max, Z, count, ans, groupSize;
	count = ans = 0;
	cin >> max >> Z;
	while (Z--) {	
		string command;
		cin >> command;
		cin >> groupSize;
		if (command == "enter") {
			if (count + groupSize > max)
				ans++;
			else
				count += groupSize;
		}
		else if (command == "leave") {
			count -= groupSize;
		}
	}
	cout << ans << endl;
	return 0;
}
