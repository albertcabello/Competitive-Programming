#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main() {
	int count;
	cin >> count;
	for (int z = 0; z < count; z++) {
		vector< vector<int> > grid;
		vector<int> rowSums;
		vector<int> colSums;
		int width, height;
		cin >> width >> height;
		int rowSum = 0;
		int colSum = 0;
		for (int j = 0; j < height; j++) {
			vector<int> row;
			int curRowSum = 0;
			int curColSum = 0;
			for (int k = 0; k < width; k++) {
				int num;
				cin >> num;
//				cout << num << " ";
				curRowSum += num;
				rowSum += num;
				row.push_back(num);
			}
			rowSums.push_back(curRowSum);
			grid.push_back(row);
		}
		for (int j = 0; j < width; j++) {
			int curColSum = 0;
			for (int i = 0; i < height; i++) {
				int num = grid[i][j];
				curColSum += num;
			}
			colSum += curColSum;
			colSums.push_back(curColSum);
		}
		rowSum /= 2;
		colSum /= 2;
		int optCol = 0;
		int colSumSoFar = 0;
		while (colSumSoFar < colSum && optCol < colSums.size()) {
			colSumSoFar += colSums[optCol];
			optCol++;
		}
		optCol--;
		int optRow = 0;
		int rowSumSoFar = 0;
		while (rowSumSoFar < rowSum && optRow < rowSums.size()) {
			rowSumSoFar += rowSums[optRow];
			optRow++;
		}
		optRow--;
//		cout << "OptRow: " << optRow << " OptCol: " << optCol << " Value: " << grid[optRow][optCol] << endl;
		int totalBlockCount = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				int num = grid[i][j];
				int dist = abs(optRow-i) + abs(optCol-j);
//				cout << "Dist: " << dist << " Block: " << num << endl;
				totalBlockCount += num*dist;
			}
		}
		cout << totalBlockCount << " blocks" <<  endl;
	}
	return 0;
}

