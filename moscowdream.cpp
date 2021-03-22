#include <iostream>

using namespace std;

int main(){
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);

    if(a<1 || b<1 ||c<1 || n < 3 || a+b+c < n){
        cout << "NO";
        return 0;
    }
    cout << "YES";


}