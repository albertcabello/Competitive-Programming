#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
using namespace std;

vector<string> tokenize(string str, char delim) {
	vector<string> ans;
	size_t start = str.find_first_not_of(delim), end=start;
	while (start != string::npos) {
		end = str.find(delim, start); //Next occurence of delimeter
		ans.push_back(str.substr(start, end-start)); //Add token to vector
		start = str.find_first_not_of(delim, end);
	}
	return ans;
}

int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		int Y;
		cin >> Y;
		map<string, int> p;
		map<string, int> vals;
		vals["upper"] = 2;
		vals["middle"] = 1;
		vals["lower"] = 0;
		while (Y--) {
			string name;
			cin >> name;
			name.pop_back(); //Remove the : from the name

			string classes;
			cin >> classes;
			vector<string> classVec = tokenize(classes, '-');

			string t;
			cin >> t;  //The word "class"

			while(classVec.size() < 10) {
				classVec.insert(classVec.begin(), "middle");
			}
			int num = 0;
			for (int i = 0; i < 10; i++) {
				num += vals[classVec[i]] * (pow(3, i));
			}
			p[name] = num;

		}

		while (p.size() > 0) {
			int curMax = 0;
			string max;
			for (auto a : p) {
				if (a.second > curMax) {
					curMax = a.second;
					max = a.first;
				}
			}
			cout << max << endl;
			p.erase(max);
		}
		for (int i = 0; i < 30; i++) {
			cout << "=";
		}
		cout << endl;
	}
	return 0;
}			
