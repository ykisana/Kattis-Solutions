//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  isPrime function from  UAPSPC / Code-Archive
//  euclidian distance function: https://www.cplusplus.com/forum/beginner/178293/
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


long double eucDist(long double x1, long double y1, long double x2,long double y2){

    long double x = x1 - x2; //calculating number to square in next step
    long double y = y1 - y2;
    long double dist;

    dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
    dist = sqrt(dist);

    return dist;
}

bool isPrime(long long x){
    long long i;
    if( x <= 1 ) return false;
    if( x == 2 ) return true;
    if( x % 2 == 0) return false;

    for(i = 3; i*i <= x; i+=2)
        if( x % i == 0) return false;
    return true;
}

int main(){
    long long t;
    long long n; long double d;
    long long x,y, x1, y1;
    long double curr;
    long long max, count;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> d;
        max = 0; curr = 0; count = 0; x1 = 0; y1 = 0;
        for(int j = 0; j < n; j++){
            cin >> x >> y;
            curr = curr + eucDist(x1, y1, x, y);
            if (curr <= d) {
                count++;
                if (isPrime(count)) {
                    max = count;
                }
            }

            x1 = x; y1 = y;
        }
        cout << max << "\n";
    }
}
