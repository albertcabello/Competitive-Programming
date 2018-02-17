#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	int count;
	cin >> count;
	int rec = 0;
	while(count--) {
		vector<string> names;
		vector<pair<double, double> > nameM;
		string main;
		pair<double, double> mainWeight;
		rec++;
		cout << "Recipe # " << rec << endl;
		int r, p, d;
		cin >> r >> p >> d;
		for (int i = 0; i < r; i++) {
			string ing;
			double w, percentage;
			cin >> ing >> w >> percentage;
			if (percentage == 100.0) {
				main = ing;
				mainWeight = make_pair(w, percentage);
			}
			names.push_back(ing);
			nameM.push_back(make_pair(w, percentage));
		}
		double sf = (double)d/(double)p;
		double mainw = mainWeight.first;
		mainw *= sf;
		for (int i = 0; i < names.size(); i++) {
			double p;
			string name = names[i];
			p = nameM[i].second;
			cout << fixed << setprecision(1) << name << " " << (p/100.0)*mainw << endl;
		}
		for (int i = 0; i < 40; i++) {
			cout << "-";
		}
		cout << endl;

	}
}
