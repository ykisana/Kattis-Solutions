/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Modified Profs Implementation of Dijkstras for flowery trails:
  https://eclass.srv.ualberta.ca/pluginfile.php/6952706/mod_resource/content/1/flowerytrails.cpp

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

// operator< is overloaded in a funny way because c++ priority queues
// are max-heaps by default, and we want it to be like a min-heap
struct Edge {
    int u, v;
    double w;
    Edge (int uu = 0, int vv = 0, double ww = 1) : u(uu), v(vv), w(ww) {}
    bool operator<(const Edge& rhs) const { return w < rhs.w; }
};

vector<vector<Edge>> g;

// Dijkstra's algorithm
void search(int s, vector<double>& d) {
    priority_queue<Edge> pq;
    d.assign(g.size(), -1);
    pq.push(Edge(s, s, 1));


    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        if (d[curr.v] != -1) continue;

        // This is the first time curr.v came off of the priority queue,
        // so curr.w is the min-cost s-curr.v path length (and curr.u would be
        // the node before curr.v on this path, but we don't need to record it).
        d[curr.v] = curr.w;

        // enqueue all nodes v exiting u
        // NOTE, a node might be enqueued multiple times (up to once per
        // per incident edge) but we know the first time it is popped from the
        // queue, it was along a shortest path
        for (const auto& nxt : g[curr.v])
            pq.push(Edge(nxt.u, nxt.v, nxt.w * curr.w));
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        g.assign(n,vector<Edge>());

        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            g[u].push_back(Edge(u,v,w));
            g[v].push_back(Edge(v,u,w));
        }



        vector<double> ds;

        search(0, ds);  // shortest path from start node 0

        double out = 1.0;
        out = out * ds[n-1];


        cout << fixed;

        cout << setprecision(4) << out << '\n';

        cin >> n >> m;
    }

}