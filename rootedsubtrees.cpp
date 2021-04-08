//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  LCA Tree With Binary Lifting from: https://cp-algorithms.com/graph/lca_binary_lifting.html
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

#define N 200010
#define LG 18

int n = N, l=LG;
vector<int> adj[N];

int timer;
long long depth[N];
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p, int d)
{
    depth[v] = d;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, d+1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}

long long dist(long long a, long long b) {
    return depth[a] + depth[b] - 2*depth[lca(a, b)] + 1;
}


long long bincoeff(long long x){
    return x*(x-1)/2;
}


int main(){
    //ios_base::sync_with_stdio(false); // this stops synchronizing I/O between iostream and stdio, avoiding some overhead
    //cin.tie(NULL); // ordinarily cin is tied to cout, meaning cin will flush cout before reading

    long long n, q;
    cin >> n >> q;
    long long u, v;
    for(long long i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        //cout << u << v;
    }
    preprocess(1);

    long long r, p, temp;
    while (q--){
        cin >> r >> p;

        //long long x = 0;

        long long x = dist(r,p);
        //cout << x << "\n";
        long long y = bincoeff(x);


        cout << n + y << '\n';
    }

}