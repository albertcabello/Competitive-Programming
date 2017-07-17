#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	while(N--) {
		float v, ang, x, h1, h2;
		cin >> v >> ang >> x >> h1 >> h2;
		ang *= M_PI/180.0;
		float t = x/(v * cos(ang));
		float y = v * t * sin(ang) - 0.5*(9.8)*pow(t, 2);
		bool safe = h1+1 < y && y < h2-1;
		if (safe) {
			cout << "Safe" << endl;
		}
		else {
			cout << "Not safe" << endl;
		}
	}
	return 0;
}
