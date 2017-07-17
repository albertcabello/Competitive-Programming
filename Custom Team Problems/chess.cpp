#include<iostream>
#include<utility>
using namespace std;
int main() {
	int c;
	cin >> c;
	while (c--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		pair<int, int> ans1, ans2;
		//y1=x1+b
		int b1p = y1-x1;
		int b1n = y1+x1;
		int b2p = y2-x2;
		int b2n = y2+x2;
		//Intersection must be on the bishops with opposite slopes;
//		int xint1 = (b2n-b1p)/2;
//		int xint2 = (b1n-b2p)/2;
//		int yint1 = xint2 + b2p;
//		int yint2 = xint1 + b1p;
		int xint1 = (b1n-b2p)/2;
		int yint1 = xint1+b2p;
		int xint2 = (b2n-b1p)/2;
		int yint2 = xint2+b1p;
		if (xint1 < xint2) {
			if (xint1 > 0 && yint1 > 0) {
				cout << xint1 << " " << yint1 << " ";
			}
			if (xint2 > 0 && yint2 > 0) {
				cout << xint2 << " " << yint2 << endl;
			}
		}
		else if (xint1 == xint2) {
			if (yint1 < yint2) {
				if (xint1 > 0 && yint1 > 0) {
					cout << xint1 << " " << yint1 << " ";
				}
				if (xint2 > 0 && yint2 > 0) {
					cout << xint2 << " " << yint2;
				}
				cout << endl;
			}
			else {
				if (xint2 > 0 && yint2 > 0) {
					cout << xint2 << " " << yint2 << " ";
				}
				if (xint1 > 0 && yint1 > 0) {
					cout << xint1 << " " << yint1;
				}
				cout << endl;
			}
		}
		else {
			if (xint2 > 0 && yint2 > 0) {
				cout << xint2 << " " << yint2 << " ";
			}
			if (xint1 > 0 && yint1 > 0) {
				cout << xint1 << " " << yint1;
			}
			cout << endl;
		}

				
	}
	return 0;
}
