/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  I/O Speedup from CMPUT 403 Eclass (Common Problems)
  Datasets (Deque) from CMPUT 403 Eclass (Week 2: Notes)

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/



#include <iostream>
#include <string>
#include <deque>


using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long inputs;
    cin >> inputs;


    long long i = 0, val;
    deque<long long> teque_right;
    deque<long long> teque_left;

    string cmd;

    while(i < inputs){
        cin >> cmd >> val;


        if(cmd.compare("push_back") == 0){
            teque_right.push_back(val);

            if(teque_right.size()> (teque_left.size())){
                teque_left.push_back(teque_right.front());
                teque_right.pop_front();
            }

        }

        else if(cmd.compare("push_front") == 0){
            teque_left.push_front(val);

            if(teque_left.size() > (teque_right.size()+1)){
                teque_right.push_front(teque_left.back());
                teque_left.pop_back();
            }

        }

        else if(cmd.compare("push_middle") == 0){

            if(teque_left.size()> (teque_right.size()+1)){
                teque_right.push_front(teque_left.back());
                teque_left.pop_back();

            }
            teque_left.push_back(val);



        }

        else if(cmd.compare("get") == 0){
            if (val < teque_left.size()){
                cout << teque_left[val] << '\n';
            }
            else{
                cout << teque_right[val - teque_left.size()] << '\n';
            }

        }

        i++;
    }

}
