#include<iostream>
#include<map>
#include<bitset>
using namespace std;
string base8to16S(string a) {
	map<string, string> trans;
	trans["0"] = "000";
	trans["1"] = "001";
	trans["2"] = "010";
	trans["3"] = "011";
	trans["4"] = "100";
	trans["5"] = "101";
	trans["6"] = "110";
	trans["7"] = "111";
	string base8 = "";
	for (int i = 0; i < a.length(); i++) {
		base8 += trans[string(1,a[i])];
	}
	while (base8.length() % 4 != 0) {
		base8 = "0" + base8;
	}
	map<string, string> base16;
	string ans = "";
	base16["0000"] = "0";
	base16["0001"] = "1";
	base16["0010"] = "2";
	base16["0011"] = "3";
	base16["0100"] = "4";
	base16["0101"] = "5";
	base16["0110"] = "6";
	base16["0111"] = "7";
	base16["1000"] = "8";
	base16["1001"] = "9";
	base16["1010"] = "A";
	base16["1011"] = "B";
	base16["1100"] = "C";
	base16["1101"] = "D";
	base16["1110"] = "E";
	base16["1111"] = "F";
	for (int i = 0; i < base8.length(); i+=4) {
		ans += base16[base8.substr(i,4)];
//		cout << base16[base8.substr(i,4)];
	}
//	cout << endl;
	return ans;
}
int main() {
	string num;
	cin >> num;
	string ans = base8to16S(num);
	while (ans[0] == '0' && ans.size() > 1) {
		ans.erase(0,1);
	}
	cout << ans << endl;
	return 0;
}
