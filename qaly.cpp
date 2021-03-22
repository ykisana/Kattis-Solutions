#include <iostream>


using namespace std;

int main(){
    int x, i =0;
    float y, z, total;
    cin >> x;

    while(i < x){
        cin >> y >> z;
        total += (y * z);

        i++;
    }

    printf("%.3f", total);


}
