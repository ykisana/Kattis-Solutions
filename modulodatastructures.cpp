//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  CP4 Book, modulodatastructures solution/hint on page 489
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
long long MAXN = 200000;
long long mds[200001] = {0};
long long bucket[448][448] = {0};

void increase(long long a, long long b, long long c, long long n, double sn){
    //long long start = a % b;
    if(b <= sn){
        bucket[b][a] += c;
    }
    else {
        for (long long i = a; i <= n; i += b) {
            mds[i] += c;
        }
    }


}
void get(long long d, double sn){
    long long sum = mds[d];
    //cout << "test";
    for(long long i = 1; i <= sn; i++){

        sum += bucket[i][d%i];

    }
    cout << sum << '\n';
}


int main(){
    long long n, q;
    cin >> n >> q;
    double sn = sqrt(n);

    //long long mds[n];
    long long t,a,b,c,d;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> a >> b >> c;
            increase(a,b,c,n,sn);
        }
        else{
            cin >> d;
            get(d, sn);
        }
    }
}