/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Iterating over map in C++:
  https://thispointer.com/how-to-iterate-over-a-map-in-c/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <map>


using namespace std;


int main(){
    long length, temp, divisor, divided;
    cin >> length >> divisor;
    map<long, long> counts;

    if (divisor == 0){
        cout << 0;
        return 0;
    }

    long count = 0;


    int i = 0;
    while (i < length){
        cin >> temp;
        divided = temp / divisor;
        if (counts.find(divided) == counts.end()){
            counts[divided] = 1;
        }
        else{
            counts[divided] = counts[divided]+1;
        }
        i++;
    }

    for (pair<long, long> element : counts) {

        if (element.second >=2){

            count += (element.second*(element.second-1))/2;
        }
    }

    cout << count;
}

