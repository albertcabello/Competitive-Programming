#include<iostream>
#include<math.h>
using namespace std;
int main() {
//	string num;
//	cin >> num;
//	string query = "echo \"obase=16;ibase=8; " + num + "\"|bc";
//	FILE *in;
//	char buff[512];
//	in = popen(query.c_str(), "r");
//	string ans = "";
//	while(fgets(buff, sizeof(buff), in)!=NULL) {
//		ans += buff;
//	}
//	cout << ans;
//	pclose(in);
//	cout << "Hi";
	string num;
	cin >> num;
	//Convert to base 10
	long long base10 = 0;
	for (int i = 0; i < num.length(); i++) {
		long long temp = (num[i] - 48) * pow(8, num.length() - 1 - i);
		base10 += temp;
	}
	long long result = base10;
	long long remainder = 0;
	string base16 = "";
	while (result != 0) {
		remainder = result % 16;
		switch (remainder) {
		case 10:
			base16 = "A" + base16;
			break;
		case 11:
			base16 = "B" + base16;
			break;
		case 12:
			base16 = "C" + base16;
			break;
		case 13:
			base16 = "D" + base16;
			break;
		case 14:
			base16 = "E" + base16;
			break;
		case 15:
			base16 = "F" + base16;
			break;
		default:
			base16 = to_string(remainder) + base16;
		}
		result /= 16;
	}
	cout << base16 << endl;
	return 0;
}
