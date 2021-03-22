//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  SuffixArray from GeeksforGeeks: https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
//  Burrows Wheeler Transform Explanation: https://www.youtube.com/watch?v=4n7NPk5lwbI
//  Further Burrows Wheeler Explanation/Optimization: https://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform
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

// Structure to store information of a suffix
struct suffix
{
    int index;
    char *suff;
};

// A comparison function used by sort() to compare two suffixes
int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
int *buildSuffixArray(char *txt, int n)
{
    // A structure to store suffixes and their indexes
    struct suffix suffixes[n];

    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabetically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }

    // Sort the suffixes using the comparison function
    // defined above.
    sort(suffixes, suffixes+n, cmp);

    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    // Return the suffix array
    return  suffixArr;
}



int main(){
    //ios_base::sync_with_stdio(false); // this stops synchronizing I/O between iostream and stdio, avoiding some overhead
    //cin.tie(NULL); // ordinarily cin is tied to cout, meaning cin will flush cout before reading
    string s;
    char chars[210000];
    while(cin.getline(chars,210000)) {
        int size = strlen(chars);
        //cout << size;
        //char chars2[size];
        //strcpy(chars2,s.c_str());
        //s = s + s;
        //strcpy(chars,s.c_str());
        //strcat(chars,chars);
        for (int i = size; i < size*2; ++i) {
            chars[i] = chars[i-size];
        }
        //cout << chars;

        int *suffixArr = buildSuffixArray(chars,  size);

        for (int i = 0; i < size; i++) {
            if (suffixArr[i] > 0){
                cout << chars[suffixArr[i]-1];

            }
            else{
                cout << chars[size-1];

            }
        }
        //cout << 't';
        cout << endl;
        //cout << "test";


    }
}
