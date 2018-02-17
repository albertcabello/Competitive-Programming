#include<iostream>
#include<sstream>
#include<vector>
#include<utility>
using namespace std;
int main() {
	int Z;
	cin >> Z;
	cin.ignore();
	while (Z--) {
		vector<int> nums;
		string line;
		getline(cin, line);
		stringstream ss;
		ss.str(line);
		int ans = 0;
		int num;
		while (ss >> num) {
			nums.push_back(num);
		}
		int last = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			if (last > nums[i]) {
				
		cout << endl;
	}
	return 0;
}
