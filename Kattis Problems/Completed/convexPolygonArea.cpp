#include<iostream>
#include<vector>
using namespace std;
int main() {
	int Z;
	cin >> Z;
	while (Z--) {
		int n;
		cin >> n;
		vector<int> xCoords, yCoords;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			xCoords.push_back(x);
			yCoords.push_back(y);
		}
		double sum = 0;
		for (int i = 0; i < n-1; i++) {
//			cout << i << " pair: X sub " << i << " times Y sub " << i+1 << " minus Y sub " << i << " times X sub " << i + 1 << endl;
			sum += ((xCoords[i] * yCoords[i+1]) - (yCoords[i] * xCoords[i+1]));
		}
		sum += ((xCoords[n-1] * yCoords[0]) - (yCoords[n-1] * xCoords[0]));
		sum /= 2;
		if (sum < 0) {
			cout << sum*-1 << endl;
		}
		else {
			cout << sum << endl;
		}
	}
	return 0;
}
