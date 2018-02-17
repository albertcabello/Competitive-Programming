#include<iostream>
#include<math.h>
#include<map>
#include<bitset>
#include<vector>
using namespace std;
bitset<10000000000> bs;
vector<long long> primes;
void sieve(long long n) {
        bs.set();
        long long _sieve_size = n + 1;
        bs[0] = bs[1] = 0;
        for (long long i = 2; i < _sieve_size; i++) {
                if (bs[i]) {
                        for (long long j = i*2; j <= _sieve_size; j+=i) {
                                bs[j] = 0;
                        }
			primes.push_back((long long)i);
                }
        }
}

map<long long, long long> primeFactors(long long N) {
	map<long long, long long> factors;
	long long PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		while (N % PF == 0) {
			N /= PF;
			factors[PF] = factors[PF] + 1;
		}
		PF = primes[PF_idx++];
	}
	if (N != 1) {
		factors[N] = 1;
	}
	return factors;
}

int main() {
	sieve(1e6);
	long long Z;
	cin >> Z;
	while (Z--) {
		long long N;
		cin >> N;
		long long ans = 0;
		map<long long, long long> factors = primeFactors(N);
		ans = factors.rbegin()->first;
		cout << ans << endl;
	}
	return 0;
}

