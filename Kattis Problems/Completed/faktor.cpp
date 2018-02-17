#include<iostream>
#include<math.h>
using namespace std;
int main() {
	float a, b;
	cin >> a >> b;
//	cout << (b-.99) << endl;
	cout << ceil((b-.99)*a) << endl;
	return 0;
}
