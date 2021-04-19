#include <bits/stdc++.h>
double E = exp(1);
double PI = M_PI;

using namespace std;


    bool wordBreak(string s, vector<string>& wordDict) {
        int dictsize = wordDict.size();
        unordered_map<string, bool> dict;
        for(int i = 0; i < dictsize; i++){
            dict[wordDict[i]] = true;
        }
        string curr = "";
        for(int i = 0; i < s.size(); i++){
            curr += s[i];
            if(dict.count(curr) > 0){
                curr = "";
            }
        }
        cout << curr;
        if(curr.size() != 0){
            return false;
        }
        else return true;

    }



int main() {
    string s, temp;
    cin >> s;
    int n;
    cin >> n;
    vector<string> dict;
    while(n--){
        cin >> temp;
        dict.push_back(temp);
    }

    cout << wordBreak(s, dict);


}