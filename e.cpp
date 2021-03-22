#include <iostream>
#include <list>
#include <iterator>
#include <vector>

#define ll long long

using namespace std;

static int n;
static int v;

void print(list<int> l) {
	for (int x : l)
		cout << x << " ";
	cout << endl;
}

int main(int argc, char const *argv[]) {

	// get input
	list<int> line;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		line.push_back(v);
	}

	vector<list<int>> removedList;
	int linePrev;					// size of the line on the last iteration
	do {
		linePrev = line.size();

		int behind = 0;				// the person behind the current person
		auto person = line.begin();	// iterator to the current person
		list<int> removed;			// list of people removed this minute

		// check middle and first values
		for (int i = 0; i < linePrev - 1; i++) {	// iterate over all but the last
			if (behind > *person || *next(person) > *person) {
				removed.push_back(*person);		// add person to the removed list for this minute
				behind = *person;				// set behind for the next person
				person = line.erase(person);	// remove the person from the line
			} else {
				behind = *person;
				person++;
			}
		}

		// check last value
		if (*person < behind) {
			removed.push_back(*person);
			line.erase(person);
		}

		removedList.push_back(removed);

	} while (linePrev != line.size());

	// remove the empty list
	removedList.pop_back();

	// print M
	cout << removedList.size() << endl;

	// print people who left
	for (auto v : removedList)
	 	print(v);

	// print final line
	print(line);


	return 0;
}
