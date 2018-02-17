#include<iostream>
typedef long long ll;
using namespace std;
int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		ll N;
		cin >> N;
		ll ans = 0;
		ll first = 0;
		ll second = 1;
		while ((first += second) < N) {
			second += first;
			if (!(first % 2) && first < N) {
				ans += first;
			}
			if (!(second %2) && second < N) {
				ans += second;
			}
		}	
		cout << ans << endl;
	}
	return 0;
}
