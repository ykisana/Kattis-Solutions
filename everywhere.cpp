#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n;
    string curr;
    unordered_set<string> cities;
    for(int i = 0; i < n; i++){
        cin >> t;
        for(int j = 0; j < t; j++){
            cin >> curr;
            cities.insert(curr);
        }
        cout << cities.size() << "\n";
        cities.clear();
    }
}