#include <iostream>

using namespace std;

int main(){
    int n, x;
    int count = 0;
    cin >> n;
    while(n--){
        cin >> x;
        if (x < 0) count++;
    }
    cout << count;
}