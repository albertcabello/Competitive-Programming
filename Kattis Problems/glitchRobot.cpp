#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void run(vector<string> coms, int x, int y, int dir) {
	for (string a : coms) {
		if (a == "Forward") {
			if (dir == 0) {
				x++;
			}
			if (dir == 90) {
				y++;
			}
			if (dir == 180) {
				x--;
			}
			if (dir == 270) {
				y--;
			}
		}
		if (a == "Right") {
			dir = (dir - 90) % 360;
		}
		if (a == "Left") {
			dir = (dir + 90) % 360;
		}
	}
}

int main() {
	int destX, destY, count;
	cin >> destX >> destY >> count;
	vector<string> commands;
	int curX, curY, dir;
	curX = curY = 0;
	dir = 90;
	while (count--) {
		string com;
		cin >> com;
		commands.push_back(com);
	}
	string poss[] = {"Forward", "Right", "Left"};
	for (int i = 0; i < count; i++) {
		string original = commands[i];
		int cCurX, cCurY, cDir;
		cCurX = curX;
		cCurY = curY;
		cDir = dir;
		for (int j = 0; j < 3; j++) {
			commands[i] = poss[j];
			if (poss[j] == original) {
				continue;
			}
			run(commands, cCurX, cCurY, cDir);
			if (cCurX == destX && cCurY == destY) {
				cout << i << " " << poss[j];
				return 0;
			}
		}
		commands[i] = original;
		if (original == "Forward") {
			if (dir == 0) {
				curX++;
			}
			if (dir == 90) {
				curY++;
			}
			if (dir == 180) {
				curX--;
			}
			if (dir == 270) {
				curY--;
			}
		}
		if (original == "Right") {
			dir = (dir - 90) % 360;
		}
		if (original == "Left") {
			dir = (dir + 90) % 360;
		}
	}
	return 0;
}
