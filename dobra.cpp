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
//  Ways of getting permutations with replacement discussed in ACP Discord
//  Students/Members Included, Brandon Fuller, Ian Dehaan, Grayden Price and Deepak.
//
//  By submitting this code, you are agreeing that you have solved in accordance
//  with the collaboration policy in CMPUT 403.
//*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, bool> v;

bool checkValid(string s){
    long long n = s.size();
    bool hasl = false;
    bool valid = true;
    for(long long i = 1; i < n-1; i++){
        if (v.count(s[i])==0){
            if(v.count(s[i-1])==0 && v.count(s[i+1])==0){
                valid = false;
                break;
            }
        }
        else if(v.count(s[i-1])>0 && v.count(s[i+1])>0){
            valid = false;
            break;
        }
        if(s[i] == 'L' || s[i-1] == 'L' || s[i+1] == 'L')hasl = true;


    }
    if(not hasl) valid = false;
    return valid;

}


int main(){

    v['A'] = true;
    v['E'] = true;
    v['I'] = true;
    v['O'] = true;
    v['U'] = true;

    char repl[3] = {'J', 'A', 'L'};
    string s;
    cin >> s;

    unordered_map<string, bool> counted;

    bool hasl = false;

    long long size = s.size();

    long long count = 0;
    long long dash_c = 0;
    vector<long long> dashes;
    for(long long i = 0; i < size; i++){
        if (s[i] == '_'){
            dash_c++;
            dashes.push_back(i);
        }
        if (s[i] == 'L') hasl = true;

    }
    if(s.size() == 0){
        cout << 0;
        return 0;
    }
    if(s == "L"){
        cout << 1;
        return 0;
    }
    else if(s == "_"){
        cout << 1;
        return 0;
    }
    else if (s.size() == 2){
        if(dashes.size()==2){
            cout << 26*2;
        }
        else if(dashes.size() == 1 && hasl){
            cout << 26;
        }
        else cout << 1;
        return 0;
    }

    if(dashes.size()== 0){
        if(hasl){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }

    }
    //cout << dashes.size();

    /*
    if (checkValid(s)){
        count += pow(21, dashes.size());
    }
     */
    long long var;
    //long long first = 0;


    long long total = pow(3, dashes.size());


    while (counted.size() < total){
        for (long long i = 0; i < dashes.size(); i++) {
            long long r = rand() % 3;
            s[dashes[i]] = repl[r];
        }
        if(counted.count(s) == 0) {
            counted[s] = true;
            if (checkValid(s)) {
                //cout << "valid:" << s << '\n';
                var = 1;
                for (long long l = 0; l < dashes.size(); l++) {
                    if (s[dashes[l]] == 'A') var *= 5;
                    else if (s[dashes[l]] == 'J') var *= 20;
                    else if (s[dashes[l]] == 'L') var *= 1;
                }
                count += var;
            }
        }
    }



    cout << count;

}