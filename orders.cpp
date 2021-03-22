/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  knapsack problem: https://www.youtube.com/watch?v=nLmhmB6NzcM


  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <bits/stdc++.h>

using namespace std;

/*

int MAXP = 30000;

vector<int> out;

int sol(int order, int menu[], int orders[]){
    if (order == 0){
        return 0;
    }
    else{
        out.push_back(orders[order]);
        sol(order - menu[orders[order]], menu, orders);
    }
    return 0;
}
 */


int main(){
    int n, m;

    cin >> n;

    int menu[n];
    for(int i = 0; i < n; i++){
        cin >> menu[i];
    }
    cin >> m;

    int costs[m];
    for(int i = 0; i < m; i++){
        cin >> costs[i];
    }


    int largest = *max_element(costs, costs + m) + 1;

    int orders[largest];
    fill_n(orders, largest, -1);
    orders[0] = 0;


    //int p = m;


    for(int i = 0; i < n; i++){
        for(int j = 0; j + menu[i] < largest; j++){
            if(orders[j] != -1){
                if(orders[j+menu[i]] == -1){
                    orders[j+menu[i]] = i;
                }
                else{
                    orders[j+menu[i]] = -2;
                }

            }
            if(orders[j] == -2){
                orders[j+menu[i]] = -2;
            }

        }
    }

    for(int i = 0; i < m; i++){
        if(orders[costs[i]] == -1){
            cout << "Impossible" << '\n';
        }
        else if (orders[costs[i]] == -2){
            cout << "Ambiguous" << '\n';
        }
        else{
            int x = 0;
            int c = costs[i];
            int output[largest];

            //out.clear();

            while (c > 0){
                output[x] = orders[c] + 1;
                c = c - menu[orders[c]];
                x++;
            }

            sort(output, output + x);

            for(int j = 0; j < x; j++){
                cout << output[j] << " ";
            }

            /*

            int outsize = out.size();

            for(int j = x-1; j >= 0; j--){
                cout << output[j] << " ";
            }
             */
            cout << "\n";

        }
    }


}