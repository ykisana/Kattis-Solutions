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

long long n, k, c;

void solve(){
    long long x, y;
    cin >> x >> y;
    long long xcount = 0; long long ycount = 0;
    while (x!=y){
        if (x > y){
            x = (x+c)/k;
            xcount++;
        }
        else{
            y = (y+c)/k;
            xcount++;
        }
    }
    cout <<  xcount + ycount  << '\n';

}

int main(){
    long long q;
    cin >> n >> k >> q;
    c = (k -2);
    while (q--){
        solve();
    }
}