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
    long long n;
    cin >> n;

    while(n--) {
        long long t;
        cin >> t;

        unordered_map<long long, long long> package;
        long long longest = 0, curr = 0, index=0,i;
        for(int x = 1; x <= t; x++){
            cin >> i;
            if (package.count(i) > 0) {
                index = max(index, package[i]);
                curr = x - index;
                //package.erase(i);
            } else {
                curr++;
                //cout << curr;
            }
            //cout << curr;
            package[i] = x;
            longest = max(curr, longest);
        }
        longest = max(curr, longest);
        cout << longest << endl;
        package.clear();
    }
}