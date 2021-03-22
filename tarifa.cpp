#include <iostream>

using namespace std;

int main(){
    int x, n, p, i = 0;
    cin >> x >> n;
    int total = x;

    while(i < n){
        cin >> p;

        if (p>total){
            p = total;
        }
        total = total-p;
        total+=x;
        i++;
    }

    cout << total;


}
