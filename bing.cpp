//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  Prof's implementation of Tries (from Phonelist solution)
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

struct TrieNode {
    bool end;
    map<char, TrieNode*> ch;
    int count;

    TrieNode() : end(false), count(0) {}
    ~TrieNode() { for (auto p : ch) delete p.second; }
};

void addWord(const string& str, TrieNode* node) {
    // iterates through string, adding to count each time child is visited
    for (char c : str) {
        if (node->ch.find(c) == node->ch.end())
            node->ch[c] = new TrieNode;

        //test count at each node
        //cout << node->count;

        //increases count then goes to next node

        node = node->ch[c];
        node->count++;
    }

    // this node ends the string str
    node->end = true;

    // outputs count at end, minus 1 to not count current word.
    cout << node->count -1<< '\n';
}

void solve(TrieNode root){
    string s;
    cin >> s;
    addWord(s, &root);
}

int main(){
    TrieNode root;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        addWord(s, &root);
    }
}