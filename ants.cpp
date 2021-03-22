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
#include <algorithm>
#include <vector>

int main(){
    int trials, length, count, temp;
    std::cin >> trials;

    int max, min, mid, low, high;
    float half;
    while (trials > 0){
        std::cin >> length >> count;

        std::vector<int> ants;
        while (count > 0){
            std::cin >> temp;
            ants.push_back(temp);

            count--;
        }

        max = *std::max_element(ants.begin(), ants.end());
        min = *std::min_element(ants.begin(), ants.end());
        if (max > length-min){
            high = max;
        }
        else{
            high = length-min;
        }

        low = 0;
        half = (float)length/2;

        for (auto i : ants){
            if(i < half){
                if(i > low){
                    low = i;
                }
            }
            else{
                if(length-i > low){
                    low = length-i;
                }
            }
        }

        std::cout << low << ' ' << high << '\n';


        trials--;
    }


    return 0;
}