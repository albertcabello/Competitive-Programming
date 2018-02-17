#include<iostream>
#include<vector>
#include<map>
#include<bitset>
using namespace std;
int main() {
	int Z;
	cin >> Z;
	cin.ignore();
	map<char, bitset<10> > fingers;
	fingers['a'] = bitset<10> (string("0110000000"));
	fingers['b'] = bitset<10> (string("0100000000"));
	fingers['c'] = bitset<10> (string("0111001111"));
	fingers['d'] = bitset<10> (string("0111001110"));
	fingers['e'] = bitset<10> (string("0111001100"));
	fingers['f'] = bitset<10> (string("0111001000"));
	fingers['g'] = bitset<10> (string("0111000000"));
	fingers['A'] = bitset<10> (string("1110000000"));
	fingers['B'] = bitset<10> (string("1100000000"));
	fingers['C'] = bitset<10> (string("0010000000"));
	fingers['D'] = bitset<10> (string("1111001110"));
	fingers['E'] = bitset<10> (string("1111001100"));
	fingers['F'] = bitset<10> (string("1111001000"));
	fingers['G'] = bitset<10> (string("1111000000"));
	map<int, int> ans;
	while (Z--) {
		string commands;
		getline(cin, commands);
		bitset<10> cur = fingers[commands[0]];
		for (int i = 0; i < 10; i++) {
			ans[i] = cur[9-i];
		}
		for (int z = 1; z <= commands.length(); z++) {
			bitset<10> next = fingers[commands[z]];
			for (int i = 0; i < 10; i++) {
				if (cur[9-i] == 0 && next[9-i] == 1) {
					ans[i] += 1;
				}
			}
			cur = next;
		}
		for (int i = 0; i < 10; i++) {
			if (!ans[i])
				cout << "0 ";
			else 
				cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
