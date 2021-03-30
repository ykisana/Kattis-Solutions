//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  N/A
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

unordered_map<char, bool> v;

bool checkValid(string s, int n){
    for(int i = 1; i < n; i++){

    }
}


int main(){

    v['A'] = true;
    v['E'] = true;
    v['I'] = true;
    v['O'] = true;
    v['U'] = true;

    char l = 'L';
    char con = 'J';
    string s;
    cin >> s;

    bool hasl = false;

    int size = s.size();

    int count = 0;
    int dash_c = 0;
    vector<int> dashes;
    for(int i = 0; i < size; i++){
        if (s[i] == '_'){
            s[i] = con;
            dash_c++;
            dashes.push_back(i);
        }
        else if (s[i] == 'L'){
            hasl = true;
        }
    }
    bool invalid = true;

    bool const3;
    bool vowel3;

    int index;

    while(invalid){
        for(int i = 0; i < dash_c; i++){
            index = dashes[i];
            if (v.count(s[index+1]) > 0 || v.count(s[index-1]) > 0){
                count += 21;
            }
            else if (v.count(s[i+1]) <= 0 || v.count(s[i-1]) <= 0){
                count +=5;
            }
        }
        invalid = false;
    }
    cout << count;

}