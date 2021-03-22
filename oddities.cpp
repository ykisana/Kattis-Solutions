#include <iostream>

using namespace std;

int main(){
    int n, x, i = 0;
    cin >> n;

    while (i < n){
        cin >> x;
        if(x % 2 == 0){
            cout << x << " is even" << endl;
        }
        else{
            cout << x << " is odd" << endl;
        }
        i++;

    }


}