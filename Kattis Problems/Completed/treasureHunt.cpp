#include<iostream>
#include<utility>
#include<map>
#include<queue>
#include<vector>
using namespace std;


int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<char> > arr;
	for (int i = 0; i < r; i++) {
		vector<char> line;
		for (int j = 0; j < c; j++) {
			char c;
			cin >> c;
			line.push_back(c);
		}
		arr.push_back(line);
	}

	map<pair<int, int>, bool> visited; //If we visit a node twice, it's a cycle
	int cur_r, cur_c;
	cur_r = cur_c = 0;
	int count = 0;
	while (!visited[make_pair(cur_r, cur_c)]) {
//		cout << "Current coords: " << cur_r << " " << cur_c << endl;
		if (cur_c < 0 || cur_c >= c || cur_r < 0 || cur_r >= r) {
			cout << "Out" << endl;
			return 0;
		}

		if (arr[cur_r][cur_c] == 'T') {
			break;
		}

		visited[make_pair(cur_r, cur_c)] = 1;
		count++;
		switch(arr[cur_r][cur_c]) {
			case 'E':
				cur_c++; break;
			case 'S':
				cur_r++; break;
			case 'N':
				cur_r--; break;
			case 'W':
				cur_c--; break;
			case 'T':
				cout << count << endl; return 0;
		}
	}
	if (arr[cur_r][cur_c] == 'T') {
		cout << count << endl;
	}
	else {
		cout << "Lost" << endl;
	}

	return 0;
}
