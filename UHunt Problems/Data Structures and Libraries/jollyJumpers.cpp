#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string line;
	int count;
	while (cin >> count) {
		vector<int> nums;
		vector<bool> taken (count-1, 0);
		while (count--) {
			int cur;
			cin >> cur;
			nums.push_back(cur);
		}
		for (int i = 0; i < nums.size() - 1; i++) {
			int dif = abs(nums[i] - nums[i+1])-1;
			if (dif >= 0 && dif <= taken.size()) {
				taken[abs(nums[i] - nums[i+1])-1] = 1;
			}
		}
		if (find(taken.begin(), taken.end(), 0) != taken.end()) {
			cout << "Not jolly" << endl;
		}
		else {
			cout << "Jolly" << endl;
		}
	}


	return 0;
}
