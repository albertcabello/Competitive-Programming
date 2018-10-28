#include<iostream>
#include<vector>
#include<math.h>
#include<bitset>
using namespace std;
bitset<1000000000> bs;
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
void segmented_sieve(long long low, long long high) {
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
	sieve(1000000000);
	return 0;
}
