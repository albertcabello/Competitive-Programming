#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	int b, br, bs, a, as;
	cin >> b >> br >> bs >> a >> as;
	double bMax = (br-b)*bs;
	double time = ceil(bMax/as);
	if (bMax == as*time) {
		time++;
	}
	cout << a+time << endl;
	return 0;
}
