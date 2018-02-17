#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	int n1, n2;
	map<int, vector<int> > parents;
	int k = 1;
	while (cin >> n1 >> n2) {
		if (n1 == -1 && n2 == -1) {
			return 0;
		}
		if (n1 == 0 && n2 == 0) {
			bool rootFound = 0;
			bool didBreak = 0;
//			cout << "Parent map: " << endl;
//			for (auto key : parents) {
//				cout << key.first << " ";
//				for (auto a : key.second) {
//					cout << a << " ";
//				}
//				cout << endl;
//			}
			for (auto key : parents) {
				vector<int> exampleZero = {0};
				if (key.second == exampleZero && !rootFound) {
					rootFound = 1;
				}
				else if (key.second == exampleZero && rootFound) {
					didBreak = 1;
					break;
				}
				else if (key.second.size() > 1) {
					didBreak = 1;
					break;
				}
			}
			if (!didBreak && rootFound) {
				cout << "Case " << k << " is a tree." << endl;
			}
			else {
				cout << "Case " << k << " is not a tree." << endl;
			}
			k++;
			parents.clear();
			continue;
		}
		vector<int> orig = parents[n2];
		if (orig.size() == 1 && orig[0] == 0) {
			orig = {n1};
		}
		else {
			orig.push_back(n1);
		}
		parents[n2] = orig;
		if (parents[n1].size() == 0) {
			parents[n1] = {0};
		}
	}
	return 0;
}
