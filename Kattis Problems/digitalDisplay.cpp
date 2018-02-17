#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<string> > params) {
	vector<string> firstParam = params[0];
	vector<string> secondParam = params[1];
	vector<string> third = params[2];
	vector<string> fourth = params[3];
	vector<string> fifth = params[4];
	for (int i = 0; i < 7; i++) {
		cout << firstParam[i] << "  " << secondParam[i] << "  " << third[i] << "  " << fourth[i] << "  " << fifth[i] << endl;
	}	
	cout << endl;
	cout << endl;
}

int main() {
	vector<string> one = {"    +", "    |", "    |", "    +", "    |", "    |", "    +"};
	vector<string> two = {"+---+", "    |", "    |", "+---+", "|    ", "|    ", "+---+"};
	vector<string> three={"+---+", "    |", "    |", "+---+", "    |", "    |", "+---+"};
	vector<string> four ={"+   +", "|   |", "|   |", "+---+", "    |", "    |", "    +"};
	vector<string> five ={"+---+", "|    ", "|    ", "+---+", "    |", "    |", "+---+"};
	vector<string> six = {"+---+", "|    ", "|    ", "+---+", "|   |", "|   |", "+---+"};
	vector<string> seven = {"+---+", "    |", "    |", "    +", "    |", "    |", "    +"};
	vector<string> eight = {"+---+", "|   |", "|   |", "+---+", "|   |", "|   |", "+---+"};
	vector<string> nine = {"+---+", "|   |", "|   |", "+---+", "    |", "    |", "+---+"};
	vector<string> zero = {"+---+", "|   |", "|   |", "+   +", "|   |", "|   |", "+---+"};
	vector<string> colon = {" ", " ", "o", " ", "o", " ", " "};

	string input;
	while (cin >> input, input != "end") {
		vector<vector<string> > params;
		for (auto a : input) {
			if (a == '1')
				params.push_back(one);
			if (a == '2') 
				params.push_back(two);
			if (a == '3') 
				params.push_back(three);
			if (a == '4') params.push_back(four);
			if (a == '5') params.push_back(five);
			if (a == '6') params.push_back(six);
			if (a == '7') params.push_back(seven);
			if (a == '8') params.push_back(eight);
			if (a == '9') params.push_back(nine);
			if (a == '0') params.push_back(zero);
			if (a == ':') params.push_back(colon);
		}
		print(params);
	}
	cout << "end" << endl;
	return 0;
}
