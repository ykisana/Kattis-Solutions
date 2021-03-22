#include <iostream>
#include <string>

using namespace std;

int main(){
    char date[7];
    string halloween = "OCT 31";
    string christmas = "DEC 25";
    cin.getline(date,7);
    string date2 = date;

    if (halloween.compare(date2) == 0){
        cout << "yup";
    }
    else if (christmas.compare(date2) == 0){
        cout << "yup";
    }
    else{
        cout << "nope";
    }



}