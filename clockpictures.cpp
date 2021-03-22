//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  KMP Algorithm Code: https://www.codespeedy.com/knuth-morris-pratt-kmp-algorithm-in-c/
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

int R = 360000;
string toString(vector<int> vi){
    string s = "";
    for(int i = 0; i < vi.size(); i++){
        s = s + to_string(vi[i]);
    }

    return s;
}

void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{
            if(len==0){
                Lps[i] = 0;
                i++;
                continue;
            }
            else{
                len = Lps[len-1];
                continue;
            }
        }
    }
}

bool KMP(string pattern,string text){
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);

    lps_func(pattern,Lps); // This function constructs the Lps array.

    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} // If there is a match continue.
        if (j == m) {
            return true;    // if j==m it is confirmed that we have found the pattern and we output the index
            // and update j as Lps of last matched character.
            j = Lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {  // If there is a mismatch
            if (j == 0)          // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1];  //Update j as Lps of last matched character
        }


    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); // this stops synchronizing I/O between iostream and stdio, avoiding some overhead
    cin.tie(NULL); // ordinarily cin is tied to cout, meaning cin will flush cout before reading

    int a;
    int temp;

    vector<int> d1;
    vector<int> d2;
    cin >> a;
    int c1[a];
    int c2[a];
    for (int i = 0; i < a; i++){
        cin >> c1[i];

    }

    for (int i = 0; i < a; i++){
        cin >> c2[i];

    }
    sort(c1, c1+a);
    sort(c2, c2+a);
    for(int i = 0; i < a; i++){
        //cout << c1[i];
    }
    //cout << "\n";

    for (int i = 0; i < a; i++){
        d1.push_back((c1[(i + 1)%a] - c1[i] + R)%R);
    }
    for (int i = 0; i < a; i++){
        d2.push_back((c2[(i + 1)%a] - c2[i] + R)%R);
    }

    string s1(d1.begin(), d1.end());
    //cout << s1 << " ";
    s1 = s1+s1;
    string s2(d2.begin(), d2.end());
    //cout << s2 << "\n";

    if (KMP(s2,s1)){
        cout << "possible";
    }
    else{
        cout << "impossible";
    }


}