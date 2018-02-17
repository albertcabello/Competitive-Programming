#include<iostream>
using namespace std;
int main() {
	int kings, queens, rooks, bishops, knights, pawns;
	int kingsN, queensN, rooksN, bishopsN, knightsN, pawnsN;
	cin >> kings >> queens >> rooks >> bishops >> knights >> pawns;
	kingsN = 1 - kings;
	queensN = 1 - queens;
	rooksN = 2 - rooks;
	bishopsN = 2 - bishops;
	knightsN = 2 - knights;
	pawnsN = 8 - pawns;
	cout << kingsN << " " << queensN << " " << rooksN << " " << bishopsN << " " << knightsN << " " << pawnsN << endl;
}


