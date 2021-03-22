#include <iostream>

using namespace std;

int main(){
    int x,y;
    cin >> x >> y;


    if(x==0 & y==0){
        cout << "Not a moose";
    }

    else if(x==y){
        cout << "Even " << 2*x;
    }
    else{
        cout << "Odd " << max(x,y) * 2;
    }



}
