#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		int num;
		cin >> num;
		for (int j = num; j > 0; j--) {
			string sj = to_string(j);
			string sortedsj = sj;
			sort(sortedsj.begin(), sortedsj.end());
			if (sortedsj == sj) {
				cout << "Case #" << i+1 << ": " << sj << endl;
				break;
			}
		}
	}
	return 0;
}
