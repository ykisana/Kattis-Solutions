/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Data Structures from CMPUT 403 Eclass  (Week 2 : Notes)
  Fast I/O from CPUT 403 Eclass (Common Problems)

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
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long input_len, output_len;
    cin >> input_len;

    unordered_map<string, vector<long long>> trips;
    unordered_map<string, bool> sorted;
    string country;
    long long year;

    for(long long i = 0; i < input_len; i++){
        cin >> country >> year;
        trips[country].push_back(year);

    }




    cin >> output_len;

    long long visit_num;

    for(long long i = 0; i < output_len; i++){
        cin >> country >> visit_num;
        if(sorted[country] == false){
            sort(trips[country].begin(), trips[country].end());
            sorted[country] = true;
        }
        cout << trips[country].at(visit_num-1) << endl;
    }

}