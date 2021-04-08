//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  more info on farey numbers (no code looked at): https://www.maths.ed.ac.uk/~v1ranick/fareyproject.pdf
//  Euler's totient function: https://www.geeksforgeeks.org/eulers-totient-function/
//
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

unordered_map<int, int> fareys;

int phi(int n)
{

    // Initialize result as n
    float result = n;

    // Consider all prime factors of n
    // and for every prime factor p,
    // multiply result with (1 - 1/p)
    for(int p = 2; p * p <= n; ++p)
    {

        // Check if p is a prime factor.
        if (n % p == 0)
        {

            // If yes, then update n and result
            while (n % p == 0)
                n /= p;

            result *= (1.0 - (1.0 / (float)p));
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result *= (1.0 - (1.0 / (float)n));

    return (int)result;
}

int calc(int x){
    if (fareys.count(x) !=0){
        return fareys[x];
    }
    else{
        fareys[x] = calc(x-1) + phi(x);
        return fareys[x];
    }

}


int main(){
    fareys[1] = 2;

    int p;
    cin >> p;
    int k, n;
    while(p--){
        cin >> k >> n;
        cout << k << " " << calc(n) << '\n';

    }
}