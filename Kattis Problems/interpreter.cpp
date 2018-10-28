#include<iostream>
#include<string>
#include<vector>
using namespace std;

string prependFunc(string a) {
	while (a.length() < 3) {
		a.insert(0, "0");
	}
	return a;
}

int main() {
	vector<string> registers(10, "000");
	vector<string> ram(1000, "000");

	string inst;
	int i = 0;
	while (cin >> inst) {
		ram[i] = inst;
		i++;
	}

	i = 0;
	int count = 0;
	while (ram[i][0] != '1') {
		inst = ram[i];
		cout << inst << endl;
		switch (inst[0]) {
		case '2':
			count++; registers[inst[1] - '0' ] = inst[2]; break;
		case '3':
			count++; 
			registers[inst[1] - '0'] = prependFunc(to_string(((stoi(registers[inst[1] - '0']) + (inst[2] - '0')) % 1000 )));
			break;
		case '4':
			count++;
			registers[inst[1] - '0'] = prependFunc(to_string(((stoi(registers[inst[1] - '0']) * (inst[2] - '0')) % 1000 )));
			break;
		case '5':
			count++;
			registers[inst[1] - '0'] = registers[inst[2] - '0'];
			break;
		case '6':
			count++;
			registers[inst[1] - '0'] = prependFunc(to_string(((stoi(registers[inst[1] - '0']) + stoi(registers[inst[1] - '0'])) % 1000 )));
			break;
		case '7':
			count++;
			registers[inst[1] - '0'] = prependFunc(to_string(((stoi(registers[inst[1] - '0']) * stoi(registers[inst[1] - '0'])) % 1000 )));
			break;
		case '8':
			count++;
			registers[inst[1] - '0'] = ram[stoi(registers[inst[2] - '0'])];
			break;
		case '9': 
			count++;
			ram[stoi(registers[inst[2] - '0'])] = registers[inst[1] - '0'];
			break;
		case '0':
			break;
		}
		i++;
	}
	cout << count+1 << endl;
	cout << "REGISTERS" << endl;
	i = 0;
	for (auto a : registers) {
		cout << i << " " << a << endl;
		i++;
	}
	return 0;
}
