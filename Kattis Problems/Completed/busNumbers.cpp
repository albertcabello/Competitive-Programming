#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
	vector<int> cubes;
	map<int, int> busNumbers;
	int i = 0;
	int max;
	cin >> max;
	while (i*i*i <= max) {
		cubes.push_back(i*i*i);
		i++;
	}
	for (i = 0; i < cubes.size(); i++) {
		for (int j = i; j < cubes.size(); j++) {
			if (cubes[i] + cubes[j] <= max) {
				busNumbers[cubes[i] + cubes[j]] += 1;
			}
		}
	}
	int curHigh = -100;
	for (auto key : busNumbers) {
		if (key.second >= 2 & key.first >= curHigh) {
			curHigh = key.first;
		}
	}
	if (curHigh == -100) {
		cout << "none" << endl;
		return 0;
	}
	cout << curHigh << endl;
	return 0;
}
