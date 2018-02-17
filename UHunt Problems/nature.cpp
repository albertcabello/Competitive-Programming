#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	int count, relations;
	cin >> count >> relations;
	while (count != 0 && relations != 0) {
		map<string, vector<string>> circleOfLife;
		while (count--) {
			string animal;
			cin >> animal;
		}
		while (relations--) {
			string meal, predator;
			cin >> meal >> predator;
			vector<string> temp = circleOfLife[meal];
			temp.push_back(meal);
			circleOfLife[predator] = temp;
		}
		int max = 0;
		for (auto it : circleOfLife) {
			if (it.second.size() > max) {
				max = it.second.size();
			}
		}
		cout << max+1 << endl;
		cin.ignore();cin.ignore();
		cin >> count >> relations;
	}
	return 0;
}


