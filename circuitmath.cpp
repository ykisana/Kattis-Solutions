/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Data Structures from CMPUT 403 Eclass  (Week 2 : Notes)

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

int main(){
    char letter [26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                        'U', 'V', 'W', 'X', 'Y', 'Z'};
    int vars;
    cin >> vars;
    unordered_map<char, bool> values;
    char temp;
    stack<bool> evaluate;

    bool check1;
    bool check2;

    for(int i = 0; i < vars; i++){
        cin >> temp;
        if(temp == 'T'){
            values[letter[i]] = true;
        }
        else{
            values[letter[i]] = false;
        }
    }

    int run = 1;


    while((cin >> temp)){
           if(temp == '+'){
               check1 = evaluate.top();
               evaluate.pop();
               check2 = evaluate.top();
               evaluate.pop();

               if (check1 || check2){
                   evaluate.push(true);
               }
               else{
                   evaluate.push(false);
               }

           }
           else if (temp == '*'){
               check1 = evaluate.top();
               evaluate.pop();
               check2 = evaluate.top();
               evaluate.pop();

               if (check1 && check2){
                   evaluate.push(true);
               }
               else{
                   evaluate.push(false);
               }

           }
           else if (temp == '-'){
               check1 = evaluate.top();
               evaluate.pop();
               check1 = not check1;
               evaluate.push(check1);
           }
           else{
               evaluate.push(values[temp]);
           }



    }
    if(evaluate.top() == true){
        cout << 'T';
    }
    else if(evaluate.top() == false){
        cout << 'F';
    }


}
