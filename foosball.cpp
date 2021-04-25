/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  N/A

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

int main(){
    int n;
    queue<string> players;
    string temp;
    string results;
    string wD, wO, bD, bO;
    vector<string> dynasties;
    int max = 0, currW = 0, currB = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        players.push(temp);
    }
    wO = players.front();
    players.pop();
    bO = players.front();
    players.pop();
    wD = players.front();
    players.pop();
    bD =players.front();
    players.pop();
    string wArrive = wO + " " + wD;
    string bArrive = bO + " " + bD;


    //cout << wO << bO << wD << bD;

    cin >> results;
    for(int i = 0; i < results.size(); i++){
        //cout << "W:"  << wO  << " " << wD << " B:" << bO <<" " <<bD << '\n';
        if (results[i] == 'W'){
            //cout << "W: "<<wO << " " << wD << '\n' << '\n';
            currW++;
            currB = 0;
            //cout << players.front() << '\n';
            players.push(bD);
            bD =  bO;
            bO = players.front();
            //cout << bO << " " << players.front() << '\n';
            bArrive = bD + " " + bO;
            players.pop();
            //cout << players.front() << '\n';
            if (currW > max){
                max = currW;
                dynasties.clear();
                dynasties.push_back(wArrive);
            }
            else if(currW == max){
                dynasties.push_back(wArrive);
            }
            swap(wO, wD);

        }
        else if (results[i] == 'B'){
            //cout << "B: "<<bO << " " << bD << '\n' <<'\n';
            currB++;
            currW = 0;
            players.push(wD);
            wD =  wO;
            wO = players.front();
            players.pop();
            wArrive = wD + " " + wO;
            if (currB > max){
                max = currB;
                dynasties.clear();
                dynasties.push_back(bArrive);
            }
            else if(currB == max){
                dynasties.push_back(bArrive);
            }
            swap(bO, bD);

        }
    }
    for (int i = 0; i < dynasties.size(); i++){
        cout << dynasties[i] << '\n';
    }


}