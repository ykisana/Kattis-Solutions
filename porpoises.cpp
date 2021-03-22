//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  CP4 5.8 Matrix Power
//  Geeks for Geeks Implementaion of Matrix Power: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
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

unordered_map<long long, long long> fibs;

long long modbase = 1000000000;

long long mod(long long a){
    long long ans = ((a%modbase) + modbase) % modbase;
    return ans;
}

long long fib(long long n){
    if (fibs.count(n)>0){
        return fibs[n];
    }
    else{
        long long k = (n & 1)? (n+1)/2 : n/2;
        if(n%2 == 1){}
        fibs[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
                      : (2*fib(k-1) + fib(k))*fib(k);
        fibs[n] = mod(fibs[n]);
        return fibs[n];
    }
}


int main(){
    long long p, k, y;
    fibs[0] = 0;
    fibs[1] = 1;
    fibs[2] = 1;
    fibs[3] = 2;
    cin >> p;
    while(p--){
        cin >> k >> y;
        cout << k << " " << fib(y) << '\n';
    }
}
