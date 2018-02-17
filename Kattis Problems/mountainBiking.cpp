#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	int N, g;
	scanf("%d %d", &N, &g);
	vector<long double> speeds;
	while (N--) {
		int d, ang;
		scanf("%d %d", &d, &ang);
		speeds.push_back(2 * g * cos(ang * M_PI/180.0L) * d);
	}
	for (int i = 0; i < speeds.size(); i++) {
		long double sum = 0.0L;
		for (int j = i; j < speeds.size(); j++) {
			sum = sqrt(sum*sum + speeds[j]);
		}
		printf("%.12Lf\n", sum);
	}
	return 0;
}
