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
#include <vector>
#include <cmath>
#include <string>


using namespace std;

int main(){
    bool end = false;
    string first, second, third, fourth, fifth;
    vector<string> nutrition;
    double fat = 0, fat1 = 0, total = 0, total1 = 0, fatperc = 0, totalperc = 0;
    int convert[5] = {9, 4, 4, 4, 7};
    int temp;
    char suffix;



    while (end == false){
        cin >> first;
        if (first == "-"){
            end = true;
            break;
        }
        else{

            while (first != "-"){
                cin >> second >> third >> fourth >> fifth;
                nutrition.push_back(first);
                nutrition.push_back(second);
                nutrition.push_back(third);
                nutrition.push_back(fourth);
                nutrition.push_back(fifth);

                total1 = 0;
                fat1 = 0;
                fatperc = 0;
                totalperc = 0;

                for(int i = 0; i < 5; i++){
                    suffix = nutrition[i].back();
                    nutrition[i].pop_back();
                    temp = stoi(nutrition[i]);
                    if(suffix == 'g'){
                        total1 += temp * convert[i];
                        if(i == 0){
                            fat1 += temp * convert[i];
                        }

                    }
                    else if(suffix == 'C'){
                        total1 += temp;
                        if (i == 0){
                            fat1+= temp;
                        }
                    }
                    else if(suffix == '%'){
                        totalperc += temp;
                        if(i == 0){
                            fatperc += temp;
                        }
                    }

                }

                if (totalperc == 100){
                    total = 100;
                    fat = fatperc;
                }
                else{
                    total1 = (total1*100)/(100-totalperc);
                    total += total1;
                    fat+=fat1;
                }

                if (fatperc != 0){

                    fat1 += fatperc*total1/100;
                    fat+=fat1;


                }
                nutrition.clear();
                cin >> first;

            }
            if (total == 0){
                cout << "0%" << '\n';
            }
            else{
            cout << round((fat *100) /(total)) << '%' << '\n';
            }
            fat = 0, total = 0, fatperc = 0, totalperc = 0;

        }
    }


}

