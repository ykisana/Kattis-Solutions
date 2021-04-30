/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Leetcode Discussions Palindromic Subsequences(code not used):
  ttps://leetcode.com/problems/count-different-palindromic-subsequences/

  Palindromic Subsequence (code not used):
  https://medium.com/@shahareg98/finding-all-palindromic-subsequence-in-the-given-string-2317fb50a2d

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long dp[2005][2005];



long long pCount(string s){
    long long k;
    //long long dp[s.length()+1][s.length()+1] = {0};

    for(long long i = 0; i < s.length(); i++){
        dp[i][i] = 1;
    }

    for(long long i = 2; i <= s.length(); i++){
        for(long long j = 0; j <= s.length() - i; j++){
            k = i + j -1;
            if (s[j] == s[k]){
                dp[j][k] = ((dp[j+1][k] + dp[j][k-1] +1)+MOD) % MOD;
            }
            else dp[j][k] = ((dp[j+1][k] + dp[j][k-1] - dp[j+1][k-1])+MOD) % MOD;
        }
    }
    return ((dp[0][s.length()-1])+MOD)%MOD;


}


int main(){
    long long t;
    cin >> t;

    string curr;
    while (t--){
        //out = 0;
        cin >> curr;
        memset(dp, 0, sizeof(dp));
        cout << pCount(curr) << endl;
    }



}
