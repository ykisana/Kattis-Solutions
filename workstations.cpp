/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  I/O Speedup from CMPUT 403 Eclass (Common Problems)
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
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long researchers, timeout;
    cin >> researchers >> timeout;

    priority_queue<long long, vector<long long>, greater<long long>> arrivals_pq;
    priority_queue<long long, vector<long long>, greater<long long>> stays_pq;

    long long arrival, stay, count = 0;

    long long i = 0;
    while (i < researchers){
        cin >> arrival >> stay;
        arrivals_pq.push(arrival);
        stays_pq.push(arrival+stay);

        i++;
    }

    while(arrivals_pq.size() > 0){
        while((arrivals_pq.top() - stays_pq.top()) > timeout){
            stays_pq.pop();
        }
        if(arrivals_pq.top() >= stays_pq.top()){
            stays_pq.pop();
            count++;
        }
        arrivals_pq.pop();

    }

    cout << count;

}
