//
// Created by Yahya on 2021-03-23.
//
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int x = 0, p, z, power;
    cin >> n;
    while(n--){
        cin >> p;
        z = p % 10;
        p /= 10;
        power = p;

        for(int i = 1; i < z; i++){
            power *= p;
        }

        if (z == 0) x +=1;
        else x += power;

    }
    cout << x;
}
