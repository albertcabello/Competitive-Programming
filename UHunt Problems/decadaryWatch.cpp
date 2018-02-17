#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
	double totCC = 8640000;
	long HH, MM, SS, CC;
	string line;
	while (cin >> line) {
		HH = stoi(line.substr(0,2));
		MM = stoi(line.substr(2,2));
		SS = stoi(line.substr(4,2));
		CC = stoi(line.substr(6,2));
		double ans = (((100*(HH*3600+MM*60+SS)+CC)/totCC)*100000000);
		line = to_string(ans);
		int loc = line.find('.');
		cout << fixed << setw(7) << setfill('0') << line.substr(0,loc-1) << endl;
	}
	return 0;
}
		
