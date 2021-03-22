#include <iostream>
#include "tinyexpr.h"
#include <string>

using namespace std;

int main(){
    string expression = "4+4+4+4";
    int answer;

    answer = te_interp(expression);

    cout << answer;


}
