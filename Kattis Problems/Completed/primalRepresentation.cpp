#include<iostream>
#include<math.h>
#include<map>
#include<bitset>
#include<vector>
using namespace std;
bitset<100000000> bs;
vector<int> primes;
void sieve(long long n) {
        bs.set();
        long long _sieve_size = n + 1;
        bs[0] = bs[1] = 0;
        for (long long i = 2; i < _sieve_size; i++) {
                if (bs[i]) {
                        for (long long j = i*2; j <= _sieve_size; j+=i) {
                                bs[j] = 0;
                        }
			primes.push_back((int)i);
                }
        }
}

map<int, int> primeFactors(long long N) {
	map<int, int> factors;
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
	sieve(10000000);
	long long N;
	while (cin >> N) {
	    if (N < 0) {
	        cout << "-1 ";
	        N *= -1;
	    }
		long long ans = 1;
		map<int, int> factors = primeFactors(N);
		for (auto key : factors) {
			//ans *= pow(key.second, key.first);
			if (key.second != 1) {
			    cout << key.first << "^" << key.second << " ";
			}
			else {
			    cout << key.first << " ";
			}
		}
		cout << endl;
	}
	return 0;
} 

