#include <iostream>

using namespace std;

int main(){
    int x,y, s;
    cin >> x >> y;


    if(x > y){
        s = x-y;
        if (s == 1){
            cout << "Dr. Chaz needs " << s  <<" more piece of chicken!";
        }
        else{
            cout << "Dr. Chaz needs " << s <<" more pieces of chicken!";
        }



    }

    else {
        s = y-x;
        if (s == 1){
            cout << "Dr. Chaz will have " << s << " piece of chicken left over!";;
        }
        else{
            cout << "Dr. Chaz will have " << s << " pieces of chicken left over!";
        }

    }

}

