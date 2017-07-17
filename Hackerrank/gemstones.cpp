#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main() {
	int count;
	cin >> count;
	vector<int> letters(26);
	int save = count;
	while (count--) {
		set<char> stones;
		string gem;
		cin >> gem;
		for (int i = 0; i < gem.length(); i++) {
			stones.insert(gem[i]);
		}
		for (char a : stones) {
			letters[a-'a'] += 1;
		}
	}
	int ans = 0;
	for (int a : letters) {
		if (a == save) ans++;
	}
	cout << ans;
	return 0;
}

