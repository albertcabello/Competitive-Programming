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
		list<string> path;
		map<string, pair<string, string> > people;
		string name, blame, investigate;
		cin >> name >> blame >> investigate;
		people[name] = make_pair(blame, investigate); //Ignore blame here because it's James
		while (people.size() != count) {
			cin >> name >> blame >> investigate;
			people[name] = make_pair(blame, investigate);
			cout << "Loop" << endl;
		}
		auto begin = path.begin();
		*begin = "Margarita";
		auto end = path.end();
		*end = "James";
		auto pos = path.begin();
		pair<string, string> curPerson = people["Margarita"];
		set<string> visited;
		visited.insert("Margarita");
		while (curPerson.first != "James") {
			path.insert(pos, curPerson.first);
			if (visited.find(curPerson.second) != visited.end()) {
				curPerson = people[curPerson.second];
				visited.insert(curPerson.second);
			}
			else {
				cout << -1 << endl;
				break;
			}
			pos++;
		}
		for (auto it = path.begin(); it != path.end(); ++it) {
			cout << *it << " ";
		}
	}
	return 0;
}


