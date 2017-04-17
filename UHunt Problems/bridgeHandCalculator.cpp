#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
	string line;
	while(getline(cin, line)) {
		//Get rid of new line
		int points = 0;
		map<char, int> suiteCounts;
		suiteCounts['S'] = 0;
		suiteCounts['H'] = 0;
		suiteCounts['D'] = 0;
		suiteCounts['C'] = 0;
		map<char, bool> suiteStopped;
		suiteStopped['S'] = 0;
		suiteStopped['H'] = 0;
		suiteStopped['D'] = 0;
		suiteStopped['C'] = 0;
		vector<string> cards;
		for (int i = 0; i < line.length(); i+=3) {
			//Do the suite counting first
			string card;
			card = line.substr(i,i+2);
			cards.push_back(card);
			char type = card[0];
			char suite = card[1];
			switch (suite) {
				case 'S':
					suiteCounts['S'] += 1;
//					cout << "New Spade Count: " << suiteCounts['S'] << endl;
					break;
				case 'H':
					suiteCounts['H'] += 1;
//					cout << "New Heart Count: " << suiteCounts['H'] << endl;
					break;
				case 'D':
					suiteCounts['D'] += 1;
//					cout << "New Diamond Count: " << suiteCounts['D'] << endl;
					break;
				case 'C':
					suiteCounts['C'] += 1;
//					cout << "New Club Count: " << suiteCounts['C'] << endl;
					break;
				default:
					break;
			}
		}
		for (int i = 0; i < 13; i++) {
			string card = cards[i];
			char type = card[0];
			char suite = card[1];
			switch (type) {
				case 'A':
					points += 4;
					suiteStopped[suite] = 1;
					break;
				case 'K':
					points += 3;
					if (suiteCounts[suite] == 0) {
						points--;
					}
					else {
						suiteStopped[suite] = 1;
					}
					break;
				case 'Q': 
					points += 2;
					if (suiteCounts[suite] <= 2) {
//						cout << "Point subtracted" << endl;
						points--;
					}
					else {
						suiteStopped[suite] = 1;
					}
					break;
				case 'J':
					points += 1;
					if (suiteCounts[suite] <= 3) {
						points--;
					}
					break;
				default:
					break;
			}
		}
//		cout << "Points before sum: " << points << endl;
		if (points >= 16 && suiteStopped['S'] && suiteStopped['H'] && suiteStopped['D'] && suiteStopped['C']) {
			cout << "BID NO-TRUMP" << endl;
			continue;
		}
		else {
			for (auto it = suiteCounts.begin(); it != suiteCounts.end(); ++it) {
				if (it->second == 2) {
					points += 1;
				}
				if (it ->second <= 1) {
					points += 2;
				}
			}
		}
//		cout << "Points after sum: " << points << endl;
		if (points < 14) {
			cout << "PASS" << endl;
			continue;
		}
		else {
			char max = 'S';
			if (suiteCounts['H'] > suiteCounts[max]) {
				max = 'H';
			}
			if (suiteCounts['D'] > suiteCounts[max]) {
				max = 'D';
			}
			if (suiteCounts['C'] > suiteCounts[max]) {
				max = 'C';
			}
			cout << "BID " << max << endl;
		}
	}
	return 0;
}
