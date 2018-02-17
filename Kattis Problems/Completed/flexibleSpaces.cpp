#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int w, p;
	cin >> w >> p;
	vector<int> parts;
	parts.push_back(w);
	while (p--) {
		int temp;
		cin >> temp;
		parts.push_back(temp);
	}
	parts.push_back(0);
	sort(parts.begin(), parts.end());
	map<int, bool> ans;
	for (int i = 0; i < parts.size(); i++) {
		for (int j = i; j < parts.size(); j++) {
//			cout << parts[i] << " " << parts[j] << endl;
			//ans.push_back(parts[j] - parts[i]);
			ans[parts[j]-parts[i]] = 1;
//			cout << parts[j] - parts[i] << endl;
		}
	}
	for (auto it : ans) {
		if (it.first) 
			cout << it.first << endl;
	}
	return 0;
}
	
