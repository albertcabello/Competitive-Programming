#include<iostream>
#include<vector>
using namespace std;
int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		vector<int> num;
		int n, k;
		while (n--) {
			char a;
			cin >> a;
			cout << a << endl;
			num.push_back(a-'0');
		}
		for (auto a : num) {
			cout << a;
		}
		cout << endl;
	}
	return 0;
}
