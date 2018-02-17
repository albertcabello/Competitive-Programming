#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int main() {
	int p, a, b, c, d, n;
	cin >> p >> a >> b >> c >> d >> n;
	vector<long double> prices;
	for (int i = 1; i <= n; i++) {
		long double j = p*(sin(a*i+b)+cos(c*i+d)+2);
		prices.push_back(j);
	}
	long double diff = 0.000;
	long double max = prices[0];
	for (int i = 1; i < prices.size(); i++) {
		if (max - prices[i] > diff) {
			diff = max - prices[i];
		}
		if (prices[i] > max) {
			max = prices[i];
		}
	}
	cout << fixed << setprecision(6) << diff << endl;
	return 0;
}
