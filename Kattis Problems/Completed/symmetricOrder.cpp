#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int count;
	cin >> count;
	int set = 1;
	while (count) {
		vector<string> names;
		int j = 0;
		for (int i = 0; i < count; i++) {
			string name;
			cin >> name;
			if (!(i % 2)) {
				names.push_back(name);
			}
			else {
				j++;
				names.insert(names.end()-i, name);
			}
		}
		cout << "SET " << set << endl;
		for (int i = 0; i < j; i++) {
			string name = names[0];
			names.erase(names.begin());
			names.push_back(name);

		}

		for (auto a : names) {
			cout << a << endl;
		}
		cin >> count;
		set++;
	}
	return 0;
}
			
