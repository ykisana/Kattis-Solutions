#include <iostream>

#include <queue>
#include <string>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    string code_str;
    cin >> code_str;

    queue<int> code;

    string line;

    int sum = 0;


    int board[y][x];

    for(int i = 0; i < y; i++){
        cin >> line;
        for(int j = 0; j <x; j++){
            //cout << line[j];

            board[i][j] = line[j] - '0';
        }
    }

    for(int i = 0; i < code_str.length();i++){
        code.push(code_str[i]);
    }

    int i = y-1, j = 0;

    sum = sum + board[i][j]

    while (i!=0 || j!=x-1){
        int skip = code.front();
        if(i > skip+1){
            if(board[i-1][j] < board[i][j+1] && board[i-1][j] < ){

            }
        }

    }

}