#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float x;
    cin >> x;
    int result;

    float conversion = 1000 *  (5280.0/4854.0);

    result= round(x * conversion);

    printf("%d", result);





}
