#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<string> permutations;

bool cmp(const char a, const char b) {
	map<char, int> alphabet;
	alphabet['A'] = 0;
	alphabet['a'] = 1;
	alphabet['B'] = 2;
	alphabet['b'] = 3;
	alphabet['C'] = 4;
	alphabet['c'] = 5;
	alphabet['D'] = 6;
	alphabet['d'] = 7;
	alphabet['E'] = 8;
	alphabet['e'] = 9;
	alphabet['F'] = 10;
	alphabet['f'] = 11;
	alphabet['G'] = 12;
	alphabet['g'] = 13;
	alphabet['H'] = 14;
	alphabet['h'] = 15;
	alphabet['I'] = 16;
	alphabet['i'] = 17;
	alphabet['J'] = 17;
	alphabet['j'] = 18;
	alphabet['K'] = 19;
	alphabet['k'] = 20;
	alphabet['L'] = 21;
	alphabet['l'] = 22;
	alphabet['M'] = 23;
	alphabet['m'] = 24;
	alphabet['N'] = 25;
	alphabet['n'] = 26;
	alphabet['O'] = 27;
	alphabet['o'] = 28;
	alphabet['P'] = 29;
	alphabet['p'] = 30;
	alphabet['Q'] = 31;
	alphabet['q'] = 32;
	alphabet['R'] = 33;
	alphabet['r'] = 34;
	alphabet['S'] = 35;
	alphabet['s'] = 36;
	alphabet['T'] = 37;
	alphabet['t'] = 38;
	alphabet['U'] = 39;
	alphabet['u'] = 40;
	alphabet['V'] = 41;
	alphabet['v'] = 42;
	alphabet['W'] = 43;
	alphabet['w'] = 44;
	alphabet['X'] = 45;
	alphabet['x'] = 46;
	alphabet['Y'] = 47;
	alphabet['y'] = 48;
	alphabet['Z'] = 49;
	alphabet['z'] = 50;
	return (alphabet[a] < alphabet[b]);	


}
 
void permute(string a) {
	string start = a;
        do {
		permutations.push_back(a);
	} while (next_permutation(a.begin(), a.end(), cmp));
}

int main() {
	int count;
	cin >> count;
	vector<string> strings;
	for (int i = 0; i < count; i++) {
		string a;
		cin >> a;
		sort(a.begin(), a.end(), cmp);
		permute(a);
		//sort(permutations.begin(), permutations.end());
		for (string b : permutations) {
			cout << b << endl;
		}
		permutations.clear();
	}
	
	
	return 0;
}

