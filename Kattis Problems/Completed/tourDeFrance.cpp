#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int f, r;
	while(cin >> f, f) {
		cin >> r;
		vector<double> ratios;
		vector<int> front;
		vector<int> rear;
		for (int i = 0; i < f; i++) {
			int g;
			cin >> g;
			front.push_back(g);
		}

		for (int j = 0; j < r; j++) {
			int g;
			cin >> g;
			rear.push_back(g);
		}

		for (int i = 0; i < f; i++) {
			for (int j = 0; j < r; j++) {
				ratios.push_back(1.0 * rear[j] / front[i]);
			}
		}

//		for (auto a : ratios) {
//			cout << a << endl;
//		}

		sort(ratios.begin(), ratios.end());
		//cout << ((ratios[ratios.size()-1]/ratios[ratios.size()-2])*100)/100 << endl;
		double soFar = 0;
		for (int i = 1; i < ratios.size(); i++) {
			soFar = max(soFar, ratios[i]/ratios[i-1]);
		}
		printf("%.2f\n", soFar);
	}
	return 0;
}
				
				
