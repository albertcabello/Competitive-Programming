#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int z;
	cin >> z;
	while (z--) {
		double gates, cur;
		double dist = 0;
		cin >> gates >> cur;
		while (gates--) {
			double y1, y2;
			cin >> y1 >> y2;
			if (cur > min(y1,y2) && cur < max(y1,y2)) {
				dist++;
			}
			if (cur < min(y1,y2)) {
				dist += sqrt(min(y1,y2) * min(y1,y2) + 1);
			}
			if (cur > max(y1,y2)) {
				dist += sqrt(max(y1,y2) * max(y1,y2) + 1);
			}
		}
		cout << dist << endl;
	}
}
