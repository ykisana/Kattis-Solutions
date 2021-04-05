//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  Properties of palindromes: https://en.wikipedia.org/wiki/Palindrome
//
//  List any classmate you discussed the problem with. Remember, you can only
//  have high-level verbal discussions. No code should be shared, developed,
//  or even looked at in these chats. No formulas or pseudocode should be
//  written or shared in these chats.
//
//  N/A
//
//  By submitting this code, you are agreeing that you have solved in accordance
//  with the collaboration policy in CMPUT 403.
//*/

#include <bits/stdc++.h>

using namespace std;

string swap(string s, int i, int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return s;

}

bool possible(string s){
    bool odd = true;
    if (s.size()%2 == 0){
        odd = false;
    }

    unordered_map<char, bool> chars;
    for(int i = 0; i < s.size(); i++){
        if(chars.count(s[i]) == 0){
            //cout << s[i];
            chars[s[i]] = true;
            int count = 0;
            for(int j = i; j < s.size(); j++){
                if(s[j] == s[i]){
                    count++;
                }
            }
            //cout << count << '\n';
            if (count %2 == 1 && odd){
                odd = false;
            }
            else if (count % 2 == 1 && !odd){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    string s;
    cin >> s;
    if(!possible(s)){
        cout << "Impossible" << '\n';
        return;
    }
    int size = s.size();
    int count = 0;
    int midpoint = size/2;

    int i, j, r, l, rr, ll;
    i = 0; j = size - 1;

    while(i < j) {
        r = j;
        l = i;
        while (s[i] != s[r]) r--;
        while (s[j] != s[l]) l++;
        rr = j - r;
        ll = l - i;
        if(ll < rr){
            int k = l -1;
            count += ll;
            while(k >= i){
                s = swap(s, k, k+1);
                k--;
            }
        }

        else{
            int k = r+1;
            count += rr;
            while (k <=  j) {
                s = swap(s, k, k-1);
                //count++;
                k++;
            }
        }


        i++;
        j--;

    }




    //cout << s << '\n';
    cout << count << '\n';

}

int main(){
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}