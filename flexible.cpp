#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int space, parts;
    cin >> space >> parts;

    int parts_arr[parts+2] = {};
    set<int> possible;
    int temp;
    parts_arr[0] = 0;
    parts_arr[parts+1] = space;
    for(int i = 1; i <= parts; i++){
        cin >> temp;
        parts_arr[i] = temp;
    }

    for(int i = 0; i < (parts+2); i++){
        for(int j = i+1; j < (parts+2); j++ ){
            possible.insert(parts_arr[j] - parts_arr[i]);
            //possible.push_back(parts_arr[j] - parts_arr[i]);
        }
    }
    //sort(possible.begin(), possible.end());

    set<int>::iterator it = possible.begin();

    while(it != possible.end()){
        cout << (*it) << " ";
        it++;
    }



}