#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


#define ll long long

using namespace std;

static int n;
static unordered_map<string,vector<string>> nameToLang;
static unordered_map<string,vector<string>> langToName;


void getInput();
int solve();
void addChildren(string name, unordered_set<string> &set);

int main(int argc, char const *argv[]) {

	getInput();

	for (auto p : m) {
		cout << p.first << ": ";
		for (string s : p.second) {
			cout << s << " ";
		}
		cout << endl;
	}

	int x = solve();
	cout << x << endl;
}

void getInput() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		while (cin.peek() != '\n') {
			string lang;
			cin >> lang;
			langToName[lang].push_back(name);
			nameToLang[name].push_back(lang);
		}
	}
}

int solve() {

	int result = n;
	for (auto p : nameToLang) {	// for every name-vector<lang> pair
		int size = 0;
		unordered_set<string> set;
		string name = p.first;
		addChildren(name, set);
		result = min(nameToLang.size() - set.size(), result)
	}

	return result;
}

void addChildren(string name, unordered_set<string> &set) {

	queue<string> q;
	q.push(name);
	prevSetSize = -1;

	while (set.size() != prevSetSize) {

	}

}
