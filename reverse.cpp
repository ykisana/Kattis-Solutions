#include <iostream>


using namespace std;



int main(){
    int length, temp;
    cin >> length;

    int numbers[length];
    for(int i = 0; i < length; i++){
        cin >> temp;
        numbers[i] = temp;
        }
    for(int i = length-1; i >= 0; i--){
        cout<< numbers[i] << ' ';
    }

}
