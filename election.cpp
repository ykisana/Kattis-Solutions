//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  CP4 Book 5.4 Combinatorics for hint on problem
//  "fill" function is from UAPSPC/Code-Archive (binomial.c)
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

#define MAXN 100
using namespace std;

long double binomial[MAXN+1][MAXN+1];

void fill(){
    int i, k;

    for(k = 0; k <= MAXN; k++){
        binomial[k][0] = binomial[k][k] = 1;
        for(i = 1; i < k; i++)
            binomial[k][i] = binomial[k-1][i-1]+binomial[k-1][i];
    }
}



int main(){
    fill();
    long long t;
    cin >> t;

    //cout << binomial[0][0] <<' ' <<  binomial[5][2] << ' '<< binomial[6][1];

    double n, v1, v2, w;

    long long c;
    long long count;

    while(t--){
        count = 0;
        cin >> n >> v1 >> v2 >> w;
        c = round(n-v1-v2);
        for(long long i = 0; i <= c; i++){
            //cout << c << '\n';
            if((v1 + i) > (v2+c-i)){
                count += binomial[c][i];
                //cout << binomial[c][i] << "\n";
            }
        }
        //cout << count << '\n';
        //cout <<pow(2,c);
        if(v2/n  >= 0.5){
            cout << "RECOUNT!" << '\n';
        }
        else if (v1/n > 0.5){
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << '\n';
        }

        else if ((100*count) > (pow(2,c)*w)){
            //cout << (100*count) << " " << (pow(2,c)*w) << "\n";
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << '\n';
        }
        else{
            cout << "PATIENCE, EVERYONE!" << '\n';
        }

    }
}