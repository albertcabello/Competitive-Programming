#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int num;
	vector<int> nums;
	while (cin >> num) {
		nums.push_back(num);
		if (nums.size() % 2 == 1) {
			nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
			cout << nums[nums.size()/2] << endl;
		}
		else {
			sort(nums.begin(), nums.end());
			cout << (nums[nums.size()/2] + nums[nums.size()/2 - 1])/2 << endl;
		}
			
	}
	return 0;
}
