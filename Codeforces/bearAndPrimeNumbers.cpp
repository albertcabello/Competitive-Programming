#include<iostream>
#include<vector>
#include<math.h>
#include<bitset>
using namespace std;
bitset<10000000000> bs;
void sieve(long n) {
	bs.set();
	long _sieve_size = n + 1;
	bs[0] = bs[1] = 0;
	for (long i = 2; i < _sieve_size; i++) {
		if (bs[i]) {
			for (long j = i*2; j <= _sieve_size; j+=i) {
				bs[j] = 0;
			}
		}
	}
}
void segmented_sieve(long low,long high) {
	int a = sqrt(high);
	sieve(a);
	for (int i = 2; i < low; i++) {
		if (bs[i]) {
			for (int j = (low/i) * i; j <= high; j+=i) {
				bs[j] = 0;
			}
		}
	}
}
int main() {
	long N;
	cin >> N;
	vector<long> nums;
	while (N--) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> N;
	while (N--) {
		int count = 0;
		long low, high;
		cin >> low >> high;
		if (low == 2) {
			sieve(high);
		}
		else {
			segmented_sieve(low, high);
		}
		for (int a : nums) {
			for (long i = low; i <= high; i++) {
				if (bs[i] && (a % i == 0)) {
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
