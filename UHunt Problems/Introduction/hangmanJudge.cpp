#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
string remove_duplicates(string a) {
	string ans = "";
	map<char, int> seen;
	for (int i = 0; i < a.length(); i++) {
		if (seen[a[i]] != 1) {
			ans += a[i];
			seen[a[i]] = 1;
		}
	}
	return ans;
}
int main() {
	int round;
	cin >> round;
	while (round != -1) {
		map<char,int> seen;
		string ans, choice;
		cin >> ans >> choice;
		choice = remove_duplicates(choice);
		int count = 0;
		for (int i = 0; i < choice.length(); i++) {
			if (ans == "") {
				break;
			}
			if (find(ans.begin(), ans.end(), choice[i]) != ans.end()) {
				seen[choice[i]] = 1;
				ans.erase(remove(ans.begin(), ans.end(), choice[i]), ans.end());
			}
			else {
				count++;
			}
		}
		if (ans == "" && count < 7) {
			cout << "Round " << round << endl << "You win." << endl;
		}
		else if (ans != "" && count < 7) {
			cout << "Round " << round << endl << "You chickened out." << endl;
		}
		else { 
			cout << "Round " << round << endl << "You lose." << endl;
		}
		cin >> round;
	}
	return 0;
}
