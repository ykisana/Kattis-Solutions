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
#include <vector>

using namespace std;

int main(){
    int length, temp;
    vector<int> cards;
    vector<int> changed;

    cin >> length;
    for(int i = 0; i < length; i++){
        cin >> temp;
        cards.push_back(temp);
    }
    int sum;




    int i = 0;

    while (i < length - 1) {

        sum = cards[i] + cards[i + 1];
        if (sum % 2 == 0) {
            cards.erase(cards.begin() + i, cards.begin() + i + 2);
            length -= 2;
            if(i>0){
                i = i-1;
            }
        } else {
            i += 1;
        }

    }


    cout << length;
}