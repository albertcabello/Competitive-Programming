#include<iostream>
using namespace std;
int main() {
	int l,w;
	cin >> w >> l;
	while (l != 0 && w != 0) {
		int count;
		int rx, ry, mx, my, dist;
		rx = ry = mx = my = 0;
		cin >> count;
		char com;
		while (count --) {
			cin >> com >> dist;
			switch (com) {
				case 'u':
					ry += dist;
					my += dist;
					if (my >= l-1) my = l-1;
					break;
				case 'd':
					ry -= dist;
					my -= dist;
					if (my < 0) my = 0;
					break;
				case 'l':
					rx -= dist;
					mx -= dist;
					if (mx < 0) mx = 0;
					break;
				default:
					rx += dist;
					mx += dist;
					if (mx >= w-1) mx = w-1;
					break;
			}
		}
		cout << "Robot thinks " << rx << " " << ry << endl;
		cout << "Actually at " << mx << " " << my << endl << endl;
		cin >> w >> l;
	}
	return 0;
}
