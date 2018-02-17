#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
int main() {
	int N;
	cin >> N;
	cin.ignore(); cin.ignore();
	while (N--) {
		string tree;
		double total = 0;
		map<string, int> species;
		getline(cin, tree);
		while (tree != "") {
			total++;
			species[tree] += 1;
			getline(cin, tree);
		}
		for (auto it : species) {
			cout << fixed;
			double ans = (it.second)/total * 100;
			cout << setprecision(4) << it.first << " " << ans << endl;
		}
		if (N > 0) {
			cout << endl;
		}
	}
}
