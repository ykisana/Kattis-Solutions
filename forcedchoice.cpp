#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, P, S;

    int m, temp;
    bool keep;
    cin >> N >> P >> S;
    for(int i = 0; i<S;i++){
        keep = false;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> temp;
            if (temp == P){
                keep = true;
            }
        }
        if(keep){
            cout << "KEEP" << "\n";
        } else cout << "REMOVE" "\n";
    }
}
