#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> words = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s",
		"cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", 
		"ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", 
		"pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", 
		"os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db",
		"sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm",
		"eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", 
		"am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr" };

unordered_map<string, bool> seen;
int lim = 20000;
bool build(string s) {
	if (s == "") {
		return true;
	}
	if (seen.count(s)) return seen[s];
	if (find(words.begin(), words.end(), s.substr(0,1)) != words.end()) { //A single character works
		if (find(words.begin(), words.end(), s.substr(0,2)) != words.end()) {
			//Both a single character and a two char string work
			//Try to find a match with either
			if (build(s.substr(1, string::npos))) {
				if (s.length()) seen[s] = true;
				return true;
			}
			if (build(s.substr(2, string::npos))) {
				if (s.length()) seen[s] = true;
				return true;
			}
			if (s.length()) seen[s] = false;
			return false;
		}
		//Only a single character matches
		bool status = build(s.substr(1, string::npos));
		if (s.length()) seen[s] = status;
		return status;
	}
	if (find(words.begin(), words.end(), s.substr(0,2)) != words.end()) { //A 2 char string works
		bool status = build(s.substr(2, string::npos));
		if (s.length()) seen[s] = status;
		return status;
	}
	if (s.length()) seen[s] = false;
	return false; //No single or double char that works
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (build(s)) {
			cout << "YES" << endl;
			seen.clear();
		}
		else {
			cout << "NO" << endl;
			seen.clear();
		}
	}
	return 0;
}
