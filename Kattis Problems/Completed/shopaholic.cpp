#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> items;
	while (N--) {
		int num;
		cin >> num;
		items.push_back(num);
	}
	sort(items.begin(), items.end(), greater<long long>());
	long long discount = 0;
	long long sofar = 0;
	for (int i = 0; i < items.size(); i++) {
		if (sofar == 2) {
			sofar = 0;
			discount += items[i];
			continue;
		}
		sofar++;
	}
	cout << discount << endl;
	return 0;
}
