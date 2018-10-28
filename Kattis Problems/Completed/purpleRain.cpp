#include<iostream>
#include<utility>
#include<climits>
#include<vector>
using namespace std;

vector<int> max_subarray(vector<int> a) { //First element is start, second is end index, third is sum
	int max_so_far = 0;
	int max_ending_here = 0;
	int max_start_index = 0;
	int startIndex = 0;
	int max_end_index = -1;

	for (int i = 0; i < a.size(); i++) {
		if (0 > max_ending_here + a[i]) {
			startIndex = i+1;
			max_ending_here = 0;
		}
		else {
			max_ending_here += a[i];
		}
		
		if (max_ending_here > max_so_far) {
			max_so_far = max_ending_here;
			max_start_index = startIndex;
			max_end_index = i;
		}
	}
	vector<int> ans;
	ans.push_back(max_start_index);
	ans.push_back(max_end_index);
	ans.push_back(max_so_far);
	return ans;
}



int main() {
	char t;
	vector<int> vec1; //B = -1
	vector<int> vec2; //B = 1
	while (cin >> t) {
		if (t == 'B') {
			vec1.push_back(-1);
			vec2.push_back(1);
		}
		else {
			vec1.push_back(1);
			vec2.push_back(-1);
		}
	}
	vector<int> vec1Res = max_subarray(vec1);
	vector<int> vec2Res = max_subarray(vec2);
	/*
	cout << vec1Res[0] << " " << vec1Res[1] << " " << vec1Res[2] << endl;
	cout << vec2Res[0] << " " << vec2Res[1] << " " << vec2Res[2] << endl;
	*/

	if (vec2Res[2] > vec1Res[2]) {
		cout << vec2Res[0] + 1 << " " << vec2Res[1] + 1 << endl;
		return 0;
	}
	else if (vec1Res[2] > vec2Res[2]) {
		cout << vec1Res[0] + 1 << " " << vec1Res[1] + 1<< endl;
		return 0;
	}
	else if (vec1Res[2] == vec2Res[2]) { //Tie, pick one with leftmost start
		if (vec1Res[0] < vec2Res[0]) {
			cout << vec1Res[0] + 1<< " " << vec1Res[1] + 1 << endl;
		}
		else if (vec2Res[0] < vec1Res[0]) {
			cout << vec2Res[0] + 1 << " " << vec2Res[1] + 1 << endl;
		}
		else if (vec1Res[0] == vec2Res[0]) {
			if (vec1Res[1] < vec2Res[1]) {
				cout << vec1Res[0] + 1 << " " << vec1Res[1] + 1 << endl;
			}
			else {
				cout << vec2Res[0] + 1 << " " << vec2Res[1] + 1 << endl;
			}
		}
	}

	return 0;
}
