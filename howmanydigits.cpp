//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  Facorial_dig from UAPSPC Code Archive
//  Kamenetsky Algorithm: https://dev.to/remonhasan/kamenetsky-s-algorithm-3gj9
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

double E = exp(1);
double PI = M_PI;


long long fac_digit(int n) {
    if(n <=1){
        return 1;
    }
    long long d = (n * log10(n/E) + log10(2*PI*n)/2);
    return floor(d) +1;
}

int main() {
    long long x;
    long long y;
    while (scanf("%ld", &x)!=EOF){
        y = fac_digit(x);
        cout << y << "\n";
    }

}