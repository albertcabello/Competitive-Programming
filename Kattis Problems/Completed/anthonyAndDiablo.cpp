#include<iostream>
#include<math.h>
using namespace std;
int main() {
	double a, n;
	cin >> a >> n;
	if ((n*n)/(4*M_PI) > a) {
		cout << "Diablo is happy!" << endl;
	}
	else {
		cout << "Need more materials!" << endl;
	}
	return 0;
}
