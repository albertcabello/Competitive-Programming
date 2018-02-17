#include<iostream>
#include<map>
using namespace std;
int main() {
	string line;
	cin >> line;
	map<int, int> pMap, kMap, hMap, tMap;
	for (int i = 0; i < line.length(); i+=3) {
		char suit = line[i];
		char numFirst = line[i+1];
		char numSecond = line[i+2];
		int num = 0;
		if (numFirst == '1') {
			num += 10;
		}
		num += numSecond - '0';
		switch (suit) {
		case 'P':
			pMap[num] += 1;
			break;
		case 'K':
			kMap[num] += 1;
			break;
		case 'H':
			hMap[num] += 1;
			break;
		case 'T':
			tMap[num] += 1;
			break;
		}	
	}
	int pMiss, kMiss, hMiss, tMiss;
	pMiss = kMiss = hMiss = tMiss = 0;
	for (int i = 1; i <= 13; i++) {
		if (pMap[i] > 1) {
			cout << "GRESKA" << endl;
			return 0;
		}
		else if (!pMap[i]) {
			pMiss++;
		}
		if (kMap[i] > 1) {
			cout << "GRESKA" << endl;
			return 0;
		}
		else if (!kMap[i]) {
			kMiss++;
		}
		if (hMap[i] > 1) {
			cout << "GRESKA" << endl;
			return 0;
		}
		else if (!hMap[i]) {
			hMiss++;
		}
		if (tMap[i] > 1) {
			cout << "GRESKA" << endl;
			return 0;
		}
		else if (!tMap[i]) {
			tMiss++;
		}
	}
	cout << pMiss << " " << kMiss << " " << hMiss << " " << tMiss << endl;
	return 0;
}
