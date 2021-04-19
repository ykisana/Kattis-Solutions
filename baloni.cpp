#include <iostream>
#define MAXN 1000100

using namespace std;

int main(){
    long long n, h, count = 0;
    long long bloons[MAXN] = {0};

    cin >> n;

    for (long long i = 0; i< n; i++) {
        cin >> h;
        if (bloons[h] > 0) {
            bloons[h]--;
        }
        bloons[h-1]++;
    }

    for(long long i = 0; i < MAXN; i++){
        count += bloons[i];
    }

    cout << count;

}