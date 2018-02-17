#include<iostream>
using namespace std;
int main() {
	string pitch, hit;
	int hitCount, strikes, outs, ans;
	hitCount = strikes = outs = ans = 0;
	while (cin >> pitch >> hit) {
		if (pitch == "FB" && hit == "F") {
			ans += hitCount+1;
			hitCount = 0;
			strikes = 0;
		}
		if (pitch == "C" && hit == "S") {
			hitCount++;
			strikes = 0;
			if (hitCount == 4) {
				ans++;
				hitCount--;
				strikes = 0;
			}
		}
		if (pitch == "FB" && hit == "S") {
			strikes++;
			if (strikes == 3) {
				outs++;
				if (outs == 3) {
					cout << ans << endl;
					return 0;
				}
			}
		}
		if (pitch == "C" && hit == "F") {
			strikes++;
			if (strikes == 3) {
				outs++;
				if (outs == 3) {
					cout << ans << endl;
					return 0;
				}
			}
		}

	}
	return 0;
}

		
