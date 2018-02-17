#include<iostream>
#include<map>
#include<bitset>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
bitset<10000000> bs;
void sieve(long long n) {
        bs.set();
        long long _sieve_size = n + 1;
        bs[0] = bs[1] = 0;
        for (long long i = 2; i < _sieve_size; i++) {
                if (bs[i]) {
                        for (long long j = i*2; j <= _sieve_size; j+=i) {
                                bs[j] = 0;
                        }
                }
        }
}

set<string> powerset(string n) {
	set<string> ans;
	if (n == "") {
		return ans;
	}
	ans.insert(n);
	for (int i = 0; i < n.length(); i++) {
		string temp = n;
		temp.erase(temp.begin() + i);
		set<string> ps = powerset(temp);
		ans.insert(ps.begin(), ps.end());
	}
	return ans;

}

int main() {
	int N;
	cin >> N;
	sieve(10000000);
	while (N--) {
		string num;
		cin >> num;
		long long ans = 0;
		map<string, bool> visited;
		for (string ps : powerset(num)) {
			sort(ps.begin(), ps.end());
			do {
				if (!visited[ps]) {
					visited[ps] = 1;
					if (ps == "0") {
						continue;
					}
					if (ps[0] == '0') {
						continue;
					}
					if (bs[stoll(ps)]) {
						ans++;
					}
				}
			} while (next_permutation(ps.begin(), ps.end()));
		}
		cout << ans << endl;
	}
	return 0;
}

