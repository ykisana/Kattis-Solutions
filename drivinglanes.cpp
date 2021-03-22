/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  knapsack problem: https://www.youtube.com/watch?v=nLmhmB6NzcM


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

int MAXV = 1000000;

int main(){
    int n, m, k ,r;
    cin >> n >> m >> k >> r;

    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = MAXV;
        }
    }
    dp[0][0]=0;
    int l[n];
    int s[n-1];
    int c[n-1];

    for(int i = 0; i < n; i++){
        cin >> l[i];
    }

    for(int i = 0; i < n-1; i++){
        cin >> s[i] >> c[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; i < m; j++){

        }
    }


}