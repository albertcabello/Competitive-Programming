#include<iostream>
#include<queue>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin.ignore();
		priority_queue<int, vector<int> > godzilla, mecha;
		int ng, nm;
		cin >> ng >> nm;
		while (ng--) {
			int t;
			cin >> t;
			godzilla.push(t);
		}
		while (nm--) {
			int t;
			cin >> t;
			mecha.push(t);
		}
		while (godzilla.size() && mecha.size()) {
			int gf, mf;
			gf = godzilla.top();
			mf = mecha.top();
			if (gf == mf) {
				mecha.pop();
			}
			if (gf > mf) {
				mecha.pop();
			}
			if (gf < mf) {
				godzilla.pop();
			}
		}
		if (godzilla.size()) {
			cout << "Godzilla" << endl;
		}
		if (mecha.size()) {
			cout << "MechaGodzilla" << endl;
		}
		if (!mecha.size() && !godzilla.size()) {
			cout << "uncertain" << endl;
		}
	}
	return 0;
}
