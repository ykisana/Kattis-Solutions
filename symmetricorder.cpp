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

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int length, count, set, n, j;
    string temp;
    set = 1;
    while(1){

        cin >> length;
        count = length;
        if (length == 0){
            break;
        }
        vector<string> names;
        for(int i=0; i < length; i++){
            cin >> temp;
            names.push_back(temp);
        }

        cout<< "SET "<<set <<'\n';
        set++;
        j = 0;
        while (j < length){
            cout << names[j] << '\n';
            j+=2;
        }
        if (length%2==1){
            j = j-3;
        }
        else{
            j--;
        }


        while (j >= 0){
            cout << names[j] << '\n';
            j-=2;
        }


    }
}

