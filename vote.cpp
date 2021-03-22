#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, c_count, curr, total, highest, winner;
    bool nowinner;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> c_count;
        total = 0;
        highest = 0;
        nowinner = false;
        winner = 0;
        for(int j = 0; j < c_count; j++){
            cin >> curr;
            total = total + curr;
            if(curr >= highest){
                if(curr == highest){
                    nowinner = true;
                }
                else{
                    nowinner = false;
                    highest = curr;
                    winner = j+1;
                }

            }
        }
        if(nowinner){
            cout << "no winner" << "\n";
        }
        else if ((highest*2) > total){
            cout << "majority winner " << winner << "\n";
        }
        else{
            cout << "minority winner " << winner << "\n";
        }
    }
}
