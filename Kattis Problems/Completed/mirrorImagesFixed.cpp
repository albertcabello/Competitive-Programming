#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int count;
	int test = 1;
	cin >> count;
	while (count--) {
		int l,w;
		cin >> l >> w;
		vector<string> arr;
		string line;
		for (int i = 0; i < l; i++) {
			cin >> line;
			reverse(line.begin(), line.end());
			arr.push_back(line);
		}
		reverse(arr.begin(), arr.end());
		cout << "Test " << test << endl;
		for (auto a : arr) {
			cout << a << endl;
		}
		test++;
	}
	return 0;
}
	
