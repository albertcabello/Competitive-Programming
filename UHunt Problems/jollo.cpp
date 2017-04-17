#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int max_element(vector<int> j) {
	int ans = j[0];
	for (int i = 0; i < j.size(); i++) {
		if (j[i] > ans) {
			ans = j[i];
		}
	}
	return ans;
}
int main() {
	int card1, card2, card3, card4, card5;
	cin >> card1 >> card2 >> card3 >> card4 >> card5;
	while (card1 != 0) {
		vector<int> princess;
		princess.push_back(card1);
		princess.push_back(card2);
		princess.push_back(card3);
		vector<int> seen = {card1, card2, card3, card4, card5};
		int countGreater = 0;
		for (int i = 0; i < princess.size(); i++) {
			if (princess[i] < card4) {
				countGreater++;
				card4 = 0;
			}
			else if (princess[i] < card5) {
				countGreater++;
				card5 = 0;
			}
		}
		if (countGreater < 2) {
			cout << "-1" << endl;
		}
		else {
			int temp = max_element(princess) + 1;
			bool found = false;
			while (!found) {
				if (find(seen.begin(), seen.end(), temp) != seen.end()) {
					temp++;
				}
				else {
					found = true;
					cout << temp << endl;
				}
			}
		}
		cin >> card1 >> card2 >> card3 >> card4 >> card5;
	}
	return 0;
}
