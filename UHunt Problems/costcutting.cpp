//Cost Cutting UHunt problem ID: 11727
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		vector<int> nums;
		nums.push_back(num1);
		nums.push_back(num2);
		nums.push_back(num3);
		auto result = minmax_element(nums.begin(), nums.end());
		nums[result.first-nums.begin()] = 0;
		nums[result.second-nums.begin()] = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] != 0) {
				cout << "Case " << i+1 << ": " << nums[j] << endl;
			}
		}
	}
	return 0;
}
