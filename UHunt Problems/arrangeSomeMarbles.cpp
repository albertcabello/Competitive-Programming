#include<algorithm>
#include<iostream>
using namespace std;

bool valid(const string in) {
	int lastGroupSize = 0;
	int curGroupSize = 0;
	int firstGroupSize = 0;
	int endGroupSize = 1;
	char curGroup = in[0];
	char firstGroup = curGroup;
	char lastGroup = in[in.length()-1];
	if (lastGroup == in[in.length()-2]) {
		endGroupSize++;
	}
	if (lastGroup == in[in.length()-3] && in[in.length()-2] == in[in.length()-3]) {
		endGroupSize++;
	}
	if (firstGroup == lastGroup) {
		return false;
	}
	for (char a : in) {
		if (a == curGroup) {
			curGroupSize++;
		}
		else {
			if (!lastGroupSize) {
				firstGroupSize = curGroupSize;
				if (firstGroupSize == endGroupSize) {
					return false;
				}
			}
			if (curGroupSize == lastGroupSize) {
				return false;
			}
			lastGroupSize = curGroupSize;
			curGroupSize = 1;
			curGroup = a;
		}
		if (curGroupSize > 3) {
			return false;
		}
	}
	return lastGroupSize != curGroupSize;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();
	char colors[] = { 'B', 'G', 'R', 'Y'};
	while (N--) {
		int count = 0;
		//cout << line << endl;
		int numColors;
		cin >> numColors;
		string test;
		for (int i = 0; i < numColors; i++) {
			int numOfColor;
			cin >> numOfColor;
			while (numOfColor--) {
				test += colors[i];
			}
		}
		do {
			if (valid(test)) {
				count++;
			}
		} while (next_permutation(test.begin(), test.end()));
		if (valid(test)) {
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
