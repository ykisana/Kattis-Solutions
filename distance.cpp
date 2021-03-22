#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int distance[n];

    int x,y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        distance[i] = x+y;
    }
    sort(distance, distance+n);
    int out = 0;
    out = out + distance[n-1] - distance[0];

    out = out * (n-1);
    cout << out;


}