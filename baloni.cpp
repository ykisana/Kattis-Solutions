#include <iostream>

using namespace std;

int main(){
    int bloons_count;
    cin >> bloons_count;
    int count = 1;
    int bloons[bloons_count];
    for (int i = 0; i< bloons_count; i++){
        cin >> bloons[i];
    }
    for (int i = 1; i < bloons_count; i++){
        if(bloons[i] > bloons[i-1]){
            count++;
        }
    }
    cout << count;


}