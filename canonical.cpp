/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Bottom up DP: https://www.youtube.com/watch?v=NFJ3m9a1oJQ
  Also used Fibonacci  style DP, as in Week 4 DP Notes on UAlberta Eclass


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


int MAXVAL = 2000100;



vector<int> dp(MAXVAL, MAXVAL);
vector<int> gd(MAXVAL, MAXVAL);
int coins[100];

/*
int dp[9999] = {MAXVAL};
int coins[100];
 */
int length;


int dynamic(long long val){
    if (val == 0){
        return 0;
    }

    for(int i = 0; i < length; i++){
        if(val >= coins[i]){
            dp[val] = min(dp[val], 1+dp[val - coins[i]]);
        }

    }
    return dp[val];

}


int greedy(long long val, int index){


    if(gd[val] < MAXVAL){
        return gd[val];
    }
    else if (val <=0){
        return gd[val] = 0;
    }
    else if (val >= coins[index]){
        return gd[val] = 1 + greedy(val - coins[index], index);
        //return gd[val];
    }
    else{
        return gd[val] = greedy(val, index-1);

    }
}

int main(){
    gd[0] = 0;
    dp[0] = 0;

    bool canonical = true;

    cin >> length;
    for(int i = 0; i < length; i++){
        cin >> coins[i];
    }
    int maxsum = coins[length-1] + coins[length-2] + 1;
    for(int i = 0; i < maxsum; i++){
        //gd[i] = greedy(i, length-1);
        if (greedy(i,length-1) > dynamic(i)){
            canonical = false;
            break;
        }
    }

   if (canonical){
       cout << "canonical";
   }
   else{
       cout << "non-canonical";
   }


}
