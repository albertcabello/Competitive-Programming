#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int maxWidth;
	cin >> maxWidth;
	while (maxWidth != 0) {
		int maxH, maxW, lineW, baseH, maxWidth, w, h;
		maxH = maxW = lineW = baseH = 0;
		cin >> w >> h;
		while (w != -1 && h != -1) {
			cout << w << " " << h << endl;
			if (lineW + w <= maxWidth) {
				lineW += w;
				maxW = max(maxW, lineW);
				if (h + baseH > maxH) {
					maxH = baseH + h;
				}
			}
			else {
				maxW = max(maxW, w);
				baseH = maxH;
				maxH += h;
				lineW = w;
			}
			cin >> w >> h;
		}
//		cout << maxW << " " << maxH << endl;
		cin >> maxWidth;
	}
		
	return 0;
}
