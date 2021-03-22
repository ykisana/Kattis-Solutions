//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  CP4 5.3, factovision problem
//  Lengendre's formula: https://www.geeksforgeeks.org/legendres-formula-highest-power-of-prime-number-that-divides-n/
//  Prime factorization: https://stackoverflow.com/questions/19031457/prlong
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

set<long long> primes;
unordered_map<long long, long long> pfactors;

bool isPrime(long long x){
    long long i;
    if( x <= 1 ) return false;
    if( x == 2 ) return true;
    if( x % 2 == 0) return false;

    for(i = 3; i*i <= x; i+=2)
        if( x % i == 0) return false;
    return true;
}

void generatePrimeFactors(long long n)
{
    if (isPrime(n)){
        pfactors[n] = 1;
        primes.insert(n);
    }
    else{
        // Print the number of 2s that divide n
        while (n % 2 == 0)
        {
            if (pfactors.count(2)){
                pfactors[2]++;

            }
            else{
                pfactors[2] = 1;
                primes.insert(2);
            }
            n = n/2;
        }

        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (long long i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                if (pfactors.count(i)){
                    pfactors[i]++;

                }
                else{
                    pfactors[i] = 1;
                    primes.insert(i);
                }
                n = n/i;
            }
        }

        // This condition is to handle the case when n
        // is a prime number greater than 2
        if (n > 2)
            if (pfactors.count(n)){
                pfactors[n]++;
            }
            else{
                pfactors[n] = 1;
                primes.insert(n);
            }
    }


}


long long lengendre(long long n, long long p){
    long long x = 0;
    while(n){
        n /= p;
        x += n;
    }
    return x;
}

int main(){

    long long x, y;
    while (cin >> x){
        cin >> y;
        bool possible = true;
        if (x==0 && (y!= 1)){
            possible = false;
        }
        else if(y == 0){
            possible = false;
        }
        else if(x%y==0 || y == 1){
            possible = true;
        }
        else{
            generatePrimeFactors(y);

            set<long long>::iterator it = primes.begin();
            while(it != primes.end()) {

                if (pfactors[*it] > lengendre(x, *it)) {
                    possible = false;
                    break;
                }

                it++;
            }
        }
        if (possible){
            //printf("%lld divides %lld!\n",y,x);
            cout << y << " divides " << x << "!" << "\n";
        }
        else{
            //printf("%lld does not divide %lld!\n",y,x);
            cout << y << " does not divide " << x << "!" << "\n";
        }
        pfactors.clear();
        primes.clear();

    }
}