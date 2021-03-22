#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

static char board[8][8];

void getInput();
void print(bool x);
bool solve();

int main(int argc, char const *argv[]) {

	getInput();
	bool x = solve();
	print(x);
}

void getInput() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> board[i][j];
}

void print(bool x) {
	if (x == true) 	cout << "valid" << endl;
	else 			cout << "invalid" << endl;
}

bool solve() {
	// check horizontal
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8; j++) {

			if (board[i][j] == '*')
				count++;

			if (count > 1)
				return false;
		}
	}

	// check vertical
	for (int j = 0; j < 8; j++) {
		int count = 0;
		for (int i = 0; i < 8; i++) {

			if (board[i][j] == '*')
				count++;

			if (count > 1)
			return false;
		}
	}

	for(int i = 0; i < 8; i++){
	    int count = 0;
	    for(int j = 0; j < 8; j++){
	        if
	    }
	}

	// check diagonal (top half)
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int d = 0; d + i < 8; d++) {

			if (board[i+d][d] == '*')
				count++;

			if (count > 1)
				return false;
		}
	}

	// check diagonal (bottom half)
	for (int j = 1; j < 8; j++) {
		int count = 0;
		for (int d = 0; d + j < 8; d++) {

			if (board[d][j+d] == '*')
				count++;

			if (count > 1)
				return false;
		}
	}

	// check for 8 pieces
	int count = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == '*')
				count++;

	if (count != 8)
		return false;

	// return
	return true;
}
