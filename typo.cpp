//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  String hashing: https://cp-algorithms.com/string/string-hashing.html
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

const int p = 31;
const long long m = 9223372036854775783;

long long compute_hash(string const& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

vector<long long> letterremover(string s){
    vector<long long> hashes;
    long long hash_value = 0;
    long long p_pow = 1;
    long long powers[s.size()];
    powers[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        powers[i] = p_pow;
    }
    hashes.push_back(hash_value);

    for(int i = 0; i < (s.size()-1); i++){
        hash_value = (hash_value - (s[i+1] - 'a' + 1) * powers[i]) % m;
        hash_value = (hash_value + (s[i] - 'a' + 1) * powers[i]) % m;
        hashes.push_back(hash_value);
    }

    return hashes;

}




int main(){
    ios_base::sync_with_stdio(false); // this stops synchronizing I/O between iostream and stdio, avoiding some overhead
    cout.tie(NULL);
    cin.tie(NULL); // ordinarily cin is tied to cout, meaning cin will flush cout before reading
    int n;
    unordered_map<long long, bool> strings;
    cin >> n;
    string arr[n];
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        strings[compute_hash(s)] = true;
        arr[i] = s;
    }

    string curr;

    vector<long long> hashes;

    bool notypos = true;
    bool flag;

    set<string> out;


    for(int i = 0; i < n; i++){
       // cout << "curr: "  << arr[i] <<'\n';
       hashes = letterremover(arr[i]);
       for (long long l: hashes){
           //cout << l << '\n';
           if(strings.count(l)){
               cout << arr[i] << '\n';
               notypos = false;
               //goto end_outer_loop;
               break;
           }
       }
    }



    //cout << "test";

    if(notypos){
        cout << "NO TYPOS";
    }



    //cout << "test";




    //cout << compute_hash(s);

}