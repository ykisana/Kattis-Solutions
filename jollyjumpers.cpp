#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    int diff;
    int temp;
    while(scanf("%d", &n)!= EOF){
        bool jolly[n-1];
        for(int i = 0; i < n; i++){
            jolly[i] = false;
        }
        int sequence[n];
        bool isJolly = true;
        for(int i = 0; i < n; i++){
            cin >> sequence[i];
        }
        for(int i = 1; i < n; i++){
            diff = sequence[i] - sequence[i-1];
            diff = abs(diff);
            if(diff < n){
                jolly[diff] = true;
            }
        }
        for(int i = 1; i < n; i++){
            if(jolly[i] == false){
                isJolly = false;
                break;
            }
        }
        if (isJolly==true){
            cout << "Jolly" << '\n';
        }
        else{
            cout << "Not jolly" << '\n';
        }

    }
}