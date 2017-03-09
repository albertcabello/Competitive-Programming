#include<iostream>
using namespace std;
int main() {
	//The formula:
	//The sum of updist(fac)^day - downdist from day=0 to end;
	int height, downdist, count;
	double updist, fac, currentPos, orig;
	cin >> height >> updist >> downdist >> fac;
	while (height > 0) {
		count = 0;
		fac /= 100;
		fac = (1-fac);
		orig = (updist*fac);
		//cout << orig << endl;
		orig = (updist-orig);
		//cout << orig << endl;
		double sum = 0;
		while (sum >= 0 && sum < height) {
			//Write this	
			double temp = (updist-(count*orig));
			count++;
			if (temp > 0) {
				//cout << "Temp: " << temp << endl;
				sum += temp;
			}
			//cout << "Sum before sub down: " << sum << endl;
			if (sum > height) {
			//	cout << "Final Sum: " << sum << endl;
				break;
			}
			else {
				sum -= downdist;
			//	cout << "Sum after sub down: " << sum << endl;
			}
			
		}
		if (sum < 0) {
			cout << "failure on day " << count << endl;
		}
		else {
			cout << "success on day " << count << endl;
		}
		cin >> height >> updist >> downdist >> fac;
	}
	return 0;
}
