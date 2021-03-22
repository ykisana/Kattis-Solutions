#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int total = 0;
    int x,y;
    if(n % 2 == 0){
        for(int i = 0; i < n/2; i++){
            cin >> x >> y;
            total = total + (y-x);
        }
        cout << total;
    }
    else{
        for(int i = 0; i < n; i++){
            cin >> x;
        }
        cout << "still running";
    }
}