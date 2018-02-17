#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
struct contestant{
	int groupNum;
	int totSolved = 0;
	int totTime = 0;
	bool solved[12];
	int times[12];
};
bool cmp(contestant l, contestant r) {
	if (l.totSolved ==  r.totSolved) {
		if (l.totTime == r.totTime) {
			return l.groupNum < r.groupNum;
		}
		return l.totTime < r.totTime;
	}
	return l.totSolved > r.totSolved;
}
int main() {
	int z;
	cin >> z;
	cin.ignore();
	cin.ignore();
	while(z--) {
		vector<contestant> groups(150);
		string line;
		getline(cin, line);
		while (line != "") {
			stringstream ss;
			ss.str(line);
			int a, b, c;
			char d;
			ss >> a >> b >> c >> d;
			groups[a].groupNum = a;
			if (d == 'C' && !groups[a].solved[b]) {
				groups[a].totSolved++;
				groups[a].solved[b] = 1;
				groups[a].times[b] += c;
				groups[a].totTime += groups[a].times[b];
			}
			if (d == 'I') {
				groups[a].times[b] += 20;
			}
			getline(cin, line);
		}
		//cin.ignore();
		sort(groups.begin(), groups.end(), cmp);
		for (int i = 0; i < groups.size(); i++) {
			if (groups[i].groupNum) {
				cout << groups[i].groupNum << " " << groups[i].totSolved << " " << groups[i].totTime << endl;
			}
		}
		if (z > 0) {
			cout << endl;
		}
	}
	return 0;
}
