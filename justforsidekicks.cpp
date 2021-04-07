//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  segment tree  geeks for geeks: https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
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

// SEGMENT TREE FROM GEEKS FOR GEEKS
// limit for array size
//const long long N = 200001;

long long n; // array size

// Max size of tree
long long tree[6][400001] = {0};
long long values[6];


// function to build the tree
void build(long long x, long long arr[])
{
    // insert leaf nodes in tree
    for (long long i=0; i<n; i++)
        tree[x][n+i] = arr[i];

    // build the tree by calculating parents
    for (long long i = n - 1; i > 0; --i)
        tree[x][i] = tree[x][i<<1] + tree[x][i<<1 | 1];
}

// function to update a tree node
void updateTreeNode(long long x, long long p, long long value)
{
    // set value at position p
    tree[x][p+n] = value;
    p = p+n;

    // move upward and update parents
    for (long long i=p; i > 1; i >>= 1)
        tree[x][i>>1] = tree[x][i] + tree[x][i^1];
}

// function to get sum on long longerval [l, r)
long long query(long long x, long long l, long long r)
{
    long long res = 0;

    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res += tree[x][l++];

        if (r&1)
            res += tree[x][--r];
    }

    return res;
}



int main(){
    //unordered_map<long long, vector<long long>> pos;
    unordered_map<long long, long long> pos;
    long long q;
    cin >> n >> q;

    for(long long i = 0; i < 6; i++){
        cin >> values[i];
        //build(i,blank);
    }

    char c;


    for(long long i = 0; i < n; i++){
        cin >> c;
        long long si = (long long)c - 48;
        updateTreeNode(si-1,i,1);
        pos[i] = si-1;
        //cout << i;
        //pos[values[si-1]].push_back(i);
    }

   // build(base);

   //cout << query(5,0,8);


    long long x,y,z;
    while(q--){
        cin >> x >> y >> z;
        //cout << "test";
        y = y-1;
        if (x == 1){
            long long p = 0;
            if(y < n) p = pos[y];

            updateTreeNode(z-1,y,1);
            updateTreeNode(p, y, 0);
            pos[y] = z-1;
            //cout << val2;

            //pos[val1].erase(remove(pos[val1].begin(),pos[val1].end(),y),pos[val1].end());
            //pos[val2].push_back(y);

        }

        else if (x==2){
            values[y] = z;
            //cout << val << '\n';


        }
        else if (x == 3){
            long long out = 0;
            for(long long i = 0; i < 6; i++){
                out += query(i,y,z) * values[i];
            }
            cout << out << '\n';
        }
    }


}