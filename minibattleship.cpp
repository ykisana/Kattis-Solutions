/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Kattis problem solution: paintings, Eclass Week 3
  Used paintings solution to model recursive pruning strategy

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board;
vector<int> ships;


int count_possible(int size, int ship_size){
    int count = 0;
    bool fit = true;
    for (int i = 0; i < size - ship_size; i++) {
        for (int j = 0; j < size - ship_size; j++) {
            if(board[i][j] != 'X'){
                for(int k = 0; k < ship_size; k++){
                    if(board[i+k][j] == 'X'){
                        fit == false;
                        break;
                    }
                }
                if(fit = true){
                    count++;
                }
                else{
                    fit = true;
                }
                for(int k = 0; k < ship_size; k++){
                    if(board[i][j+k] == 'X'){
                        fit == false;
                        break;
                    }
                }
                if(fit = true){
                    count++;
                }
                else{
                    fit = true;
                }
            }

        }
    }
    return count;
}


int brute_force(int at, int size, int ship_count){
    int count = 0;


    if (at > size){
        return 0;
    }

    for(int i = 0; i < ship_count; i++) {
        count += count_possible(size, ships[i]);
    }
    return count;
}


int main(){
    int size, ship_count;
    cin >> size >> ship_count;

    vector<char> rows;
    char temp;

    int count = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> temp;
            rows[j] = temp;
        }
        board[i] = rows;
        rows.clear();
    }

    for(int i = 0; i < ship_count; i++){
        cin >> ships[i];
    }

    count += brute_force(0, size, ship_count);
    cout << count;

};