#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long x, y = 4, z = 0, i = 0;
    cin >> x;

    while(i < x){
        y = sqrt(y) + pow(2,z);
        y = pow(y,2);
        i++;
        z++;
    }
    cout << y;


}
