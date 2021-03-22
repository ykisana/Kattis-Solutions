/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  N/A

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
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long factorial(long long x){
    if (x == 1 || x == 0){
        return 1;
    }
    else {
        return x*factorial(x-1);
    }
}

int main(){
    vector<string> students;
    unordered_map<string, vector<string>> bad;

    long long count, count1;

    string student, left, right, temp;

    long long total;


    while (scanf("%lld",&count)!=EOF){
        bool possible = false;
        bool possible1 = true;
        total = factorial(count);
        for(int i = 0; i < count; i++){
            cin >> student;
            //students[i] = student;
            students.push_back(student);
        }
        cin >> count1;

        for(int i = 0; i < count1; i++){
            cin >> left >> right;
            bad[left].push_back(right);
            bad[right].push_back(left);
        }
        sort(students.begin(), students.end());

        for(int i = 0; i < count; i++){
            if(bad[students[i]].size()>=(count-1)){
                possible1 = false;
            }
        }

        long long j = 0;
        while (j < (total/2) && possible == false && possible1 == true){
            possible = true;

            int k = 0;
            while(k < count){

                if(find(bad[students[k]].begin(), bad[students[k]].end(), students[k+1])!= bad[students[k]].end()){
                    next_permutation(students.begin(), students.end());

                    possible = false;
                    break;

                }
                k++;
            }
            j++;
        }

        if(possible == true){
            for(int i = 0; i < students.size(); i++){
                cout << students[i] << ' ';
            }
        }
        else{
            cout << "You all need therapy.";
        }
        students.clear();
        bad.clear();

        cout << '\n';

    }
}