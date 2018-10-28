#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, cur;
	cur = 1;
	while (cin >> n >> m, n && m) {
		vector<vector<char> > array;
		for (int i = 0; i < n; i++) {
			vector<char> line;
			for (int j = 0; j < m; j++) {
				char a;
				cin >> a;
				line.push_back(a);
			}
			array.push_back(line);
		}

		if (cur != 1) {
			cout << endl;
		}
		cout << "Field #" << cur << ":" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (array[i][j] == '*') {
					cout << "*";
					continue;
				}
				int ans = 0;
				if (i-1 >= 0) //U
					array[i-1][j] == '*' ? ans++ : ans+=0;
				if (i+1 < n) //D
					array[i+1][j] == '*' ? ans++ : ans+=0;
				if (j-1 >= 0) //L
					array[i][j-1] == '*' ? ans++ : ans+=0;
				if (j+1 < m) //R
					array[i][j+1] == '*' ? ans++ : ans+=0;
				if (i-1 >= 0 && j-1 >= 0) //UL
					array[i-1][j-1] == '*' ? ans++ : ans+=0;
				if (i-1 >= 0 && j+1 < m) //UR
					array[i-1][j+1] == '*' ? ans++ : ans+=0;
				if (i+1 < n && j-1 >=0) //DL
					array[i+1][j-1] == '*' ? ans++ : ans+=0;
				if (i+1 < n && j+1 < m) //DR
					array[i+1][j+1] == '*' ? ans++ : ans+=0;

				cout << ans;
			}
			cout << endl;
		}
		cur++;
	}
}
