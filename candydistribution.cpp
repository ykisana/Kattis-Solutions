//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  5.3.10 Modular Multiplicative Inverse from CP4 Book
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

int extEuclid(long long a, long long b, long long &x, long long  &y){
    long long xx = y = 0;
    long long yy = x = 1;
    while(b){
        long long q = a/b;
        long long t = b;
        b = a%b;
        a = t;
        t = xx;
        xx = x-q*xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

int mod(long long a, long long m){
    return((a % m) +m) %m;
}

int modInverse(long long b, long long m){
    long long x, y;
    long long d = extEuclid(b, m, x ,y);
    if(d!=1) return -1;
    return(mod(x,m));
}

int main(){
    long long n;
    cin >> n;
    long long x,y;
    bool found;
    long long a;
    for(long long i = 0; i < n; i++){
        found = true;
        cin >> x >> y;
        if(y%x == 0){
            found = false;
        }

        a = modInverse(y,x);

        if(x == 1 && y > 1){
            cout << 1 << "\n";
        }
        else if(x == 1 && y == 1){
            cout << 2 << "\n";
        }
        else if(y == 1){
            cout << x+1 << '\n';
        }

        else if(a == -1){
            cout << "IMPOSSIBLE" << '\n';
        }
        else{
            cout << a << "\n";
        }

    }
}