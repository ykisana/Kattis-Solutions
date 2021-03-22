#include <iostream>


using namespace std;

int main(){
    long long x, y;
    while(scanf("%lld %lld", &x, &y) != EOF){
        cout << abs(x-y) << '\n';
    }
}
