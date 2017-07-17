#include<iostream>
#include<set>
#include<utility>
#include<map>
#include<list>
using namespace std;
int main() {
	int c;
	cin >> c;
	while(c--) {
		int count;
		cin >> count;
		list<string> path;
		map<string, pair<string, string> > people;
		string name, blame, investigate;
		cin >> name >> blame >> investigate;
		people[name] = make_pair(blame, investigate); //Ignore blame here because it's James
		count--; //We're never going to see james;
		while (people.size() != count) {
			cin >> name >> blame >> investigate;
			people[name] = make_pair(blame, investigate);
		}
		path.push_back("Margarita");
		pair<string, string> curPerson = people["Margarita"];
		set<string> visited;
		visited.insert("Margarita");
		bool broke = 0;
		do {
			path.insert(path.end(), curPerson.second);
			curPerson = people[curPerson.second];
			if (visited.find(curPerson.second) == visited.end()) {
				visited.insert(curPerson.second);
			}
			else {
				broke = 1;
				break;
			}
		} while (curPerson.first != "James" && curPerson.second != "James");
		path.push_back("James");
		if (!broke) {
			cout << path.size()-2 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}


