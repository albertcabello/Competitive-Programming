#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > grid;
int main() {
	int height, width;
	cin >> height >> width;
	while (height != 0 || width != 0) {
		for (int i = 0; i < height; i++) {
			string line;
			cin >> line;
			vector<int> row;
			for (int j = 0; j < width; j++) {
				int num = stoi(string(1,line[j]));
				if (num == 1) { num = 9; }
				row.push_back(num);
			}
			grid.push_back(row);
		}
		int j = 0;
		int i = height-1;
		int dir = 0; //0 is right, 1 is up, 2 is left, 3 is down 
		int count = 0;
		do {
			while (dir == 0 && j < width - 1 && grid[i][j+1] != 9) { //For right direction
				//Check if you can turn right, down in this case, if so do it
				if (i < height - 1 && grid[i+1][j] != 9) {
					dir = 3;
				}
				else {
					cout << "Right ";
					grid[i][j+1] += 1;
					j++;
				}
				cout << "Current coords: (" << j << ", " << i << ") Dir: " << dir << endl;
//				grid[i][j+1] += 1;
//				j++;
			}
			while (dir == 1 && i > 0 && grid[i-1][j] != 9) { //Up direction
				if (j < width -1 && grid[i][j+1] != 9) { //Check if can turn right, if so go right
					dir = 0;
				}
				else {
					cout << "Up ";
					grid[i-1][j] += 1;
					i--;
				}
				cout << "Current coords: (" << j << ", " << i << ") Dir: " << dir << endl;
//				grid[i-1][j] += 1;
//				i--;
			}
			while (dir == 2 && j > 0 && grid[i][j-1] != 9) { //Left Direction
				if (i > 1 && grid[i-1][j] != 9) {
					dir = 1;
				}
				else {
					cout << "Left ";
					grid[i][j-1] += 1;
					j--;
				}
				cout << "Current coords: (" << j << ", " << i << ") Dir: " << dir << endl;
//				grid[i][j-1] += 1;
//				j--;
			}
			while(dir == 3 && i < height -1 && grid[i+1][j] != 9) {//Down direction
				if (j > 1 && grid[i][j-1] != 9) {
					dir = 2;
				}
				else {
					cout << "Down ";
					grid[i+1][j] += 1;
					i++;
				}
				cout << "Current coords: (" << j << ", " << i << ") Dir: " << dir << endl;
//				grid[i+1][j] += 1;
//				i++;
			}
			//When we get here, our direction doesn't allow us to go, so add 1
			dir++;
			dir %= 4;
			cout << "Current coords: (" << j << ", " << i << ") Dir: " << dir << endl;
			count++;
		} while ((j != 0 || i != 0) && count < 30);


		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
		cin >> height >> width;
	}
	return 0;
}
