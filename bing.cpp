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
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    bool end;
    unordered_map<char, TrieNode*> ch;
    int count;

    TrieNode() : end(false), count(0) {}
    ~TrieNode() { for (auto p : ch) delete p.second; }
};

void addWord(const string& str, TrieNode* node) {
    // ok: indicates no string already stored is a prefix of the new string s
    bool ok = !(node->end);

    for (char c : str) {
        if (node->ch.find(c) == node->ch.end())
            node->ch[c] = new TrieNode;

        node->count = node->count + 1;
        node = node->ch[c];
        if (node->end) ok = false;
    }

    // this node ends the string str
    node->end = true;

    // finally, also check that this is a leaf node (i.e. no children)
    cout << node->count - 1;
}

void solve(){
    TrieNode root;
    string s;
    cin >> s;
    addWord(s, &root);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}