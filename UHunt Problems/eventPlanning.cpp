#include<iostream>
using namespace std;
int main() {
	int people, budget, hotels, weeks, cost, smallest;
	while (cin >> people) {
		cin >> budget >> hotels >> weeks;
		smallest = budget + 1;
		//Do the hotels;
		for (int i = 0; i < hotels; i++) {
			//Get the cost of the hotel
			cin >> cost;
			//Do the weeks 
			for (int j = 0; j < weeks; j++) {
				int open;
				cin >> open;
				if (open >= people) {
					int temp = (people * cost);
					if (temp < smallest) {
						smallest = temp;
					}
				}
			}
		}
		if (smallest > budget) {
			cout << "stay home" << endl;
		}
		else {
			cout << smallest << endl;
		}
	}
	return 0;
}
