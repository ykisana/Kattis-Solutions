//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  Geeks for Geeks Concat two integers: https://www.geeksforgeeks.org/how-to-concatenate-two-integer-values-into-one/
//  Geeks for Geeks Reduce Fractions:
//
//  List any classmate you discussed the problem with. Remember, you can only
//  have high-level verbal discussions. No code should be shared, developed,
//  or even looked at in these chats. No formulas or pseudocode should be
//  written or shared in these chats.
//
//  N/A
//
//  By submitting this code, you are agreeing that you have solved in accordance
//  with the collaboration policy in CMPUT 403.
//*/

#include <bits/stdc++.h>

using namespace std;

void reduceFraction(int x, int y)
{
    int d;
    d = __gcd(x, y);

    x = x / d;
    y = y / d;

    if (x == 0){
        cout << 0 << '\n';
    }
    else if (x == 1 && y == 1){
        cout << 1 << '\n';
    }

    else{
        cout << x << '/' << y << '\n';
    }


}

int concat(int a, int b)
{

    // Convert both the integers to string
    string s1 = to_string(a);
    string s2 = to_string(b);

    // Concatenate both strings
    string s = s1 + s2;

    // Convert the concatenated string
    // to integer
    int c = stoi(s);

    // return the formed integer
    return c;
}

int wins(int a, int b, int c, int d){
    if (a+b == 3){
        if(c + d == 3){
            return 0;
        } else return 1;
    }
    else if (c + d == 3){
        return 0;
    }
    else if(a == b){
        if (c == d){
            if(a+b > c+d){
                return 1;
            }
            else return 0;
        }
        else return 1;
    }
    else if (c==d){
        return 0;
    }
    else if(concat(max(a,b),min(a,b)) > concat(max(c,d),min(c,d))){
        return 1;
    }
    else return 0;

}

void ans(int a,int b,int c,int d){
    int count = 0;
    int total = 0;
    int i,j,k,l;
    int v,x,y,z;
    if (a == 0){
        i = 1;
        v = 6;
    }
    else{
        i = a;
        v = a;
    }

    while(i <=v){
        if (b == 0){
            j = 1;
            x = 6;
        }
        else{
            j = b;
            x = b;
        }
        while(j <= x){
            if (c == 0){
                k = 1;
                y = 6;
            }
            else{
                k = c;
                y = c;
            }
            while(k <= y){
                if (d == 0){
                    l = 1;
                    z = 6;
                }
                else{
                    l = d;
                    z = d;
                }
                while(l <=z){
                    count += wins(i,j,k,l);
                    total++;
                    l++;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    reduceFraction(count,total);

}

int main(){
    char given[4];

    int rolls[4];

    bool all;

    while(1){
        all = true;
        cin >> given[0] >> given[1] >> given[2] >> given [3];
        for(int i = 0; i < 4; i++){
            if (given[i] != '*'){
                rolls[i] = (int)given[i] - 48;
            }
            else{
                rolls[i] = 0;
                all = false;
            }
        }

        if (all && ((rolls[0] + rolls[1] + rolls[2] +rolls[3])==0)){
            break;
        }
        ans(rolls[0], rolls[1], rolls[2], rolls[3]);
         /*
        if((rolls[0] + rolls[1] + rolls[2] +rolls[3])==0){
            cout << "205/432" << '\n';
        }

        else if(rolls[0] + rolls[1] == 3){
            if (rolls[2] + rolls[3] == 3){
                cout << 0 << '\n';
            }
            else if(rolls[2] + rolls[3] == 0){
                cout << "17/18" << '\n';
            }
            else cout << 1 << '\n';
        }
        else if(rolls[2] + rolls[3] == 3){
            cout << 0 << '\n';
        }
        else if(rolls[0] == rolls[1] && rolls[0] > 0){
            if (rolls[2] == rolls[3] && rolls[3] > 0){
                if (rolls[0] > rolls[2]){
                    cout << 1 << '\n';
                }
                else{
                    cout << 0 << '\n';
                }
            }
        }
        else if(rolls[2] == rolls[3] && rolls[3] > 0){
            if (rolls[0] + rolls[1] == 2 || (rolls[0] + rolls[1] == 1)){
                if(rolls[0] != 0 && rolls[1] !=0){
                    cout << ""
                }
            }
        }
         */



    }
}