/*
 * Algorithm to turn an implicit graph (2D Graph) from stdin 
 * to a linear array.  Useful to determine connected components
 * with a union find class
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int r, c;
	cin >> r >> c;
	vector<char> nums (r*c, 'Z');
	for (int i = 0; i < r*c; i++) {
                char num;
                cin >> num;
                nums[i] = (num);
                //Do the join operations now
		if ((i % c) != 0) {
			cout << nums[i] << " is next to " << nums[i-1] << " ";
		}
		if ((i-c) >= 0) {
			cout << nums[i] << " is below " << nums[i-c] << " ";
		}
		cout << endl;
        }
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
	return 0;
}
