/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Implementation of graphs and dijkstras from Geeks for Geeks:
  https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/

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

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;
    list< pair<int, double> > *adj;

public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, double w);

    // prints shortest path from s
    void longestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, double> >[V];
}

void Graph::addEdge(int u, int v, double w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::longestPath(int src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, double> > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<double> dist(V, -1);

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(1, src));
    dist[src] = 1;

    /* Looping till all shortest distance are finalized
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, double> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, double> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[u] * weight > dist[v])
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */

                if (dist[v] != -1)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] * weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        cout << i << " " << dist[i] << '\n';
    double out = 1.0;
    cout << out * dist[V-1];
}



int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        Graph g(n);

        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            g.addEdge(u,v,w);
        }
        g.longestPath(0);

        //vector<double> distances;
        //search(0, distances);
        //search(graph.size(), distances);








        cin >> n >> m;
    }

}

