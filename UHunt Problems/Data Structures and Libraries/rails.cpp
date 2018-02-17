#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
int main() {
	int N;
	int i;
	cin >> N;
	while (N) {
		int desired[N];
		cin.ignore();
		string line;
		getline(cin, line);
		while (line != "0") {
			int cur = 0;
			i = 0;
			stringstream ss;
			ss.str(line);
			while (i < N) {
				int t;
				ss >> t;
				desired[i] = t;
//				cout << t << " ";
				i++;
			}
//			cout << endl;
			stack<int> rail;
			for (i = 1; i <= N; i++) {	
				rail.push(i);
				while (rail.size() && rail.top() == desired[cur]) {
					rail.pop();
					cur++;
				}
			}
			if (rail.size()) {
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
			getline(cin, line);
		}
		cout << endl;
		cin >> N;
	}
	return 0;
}
