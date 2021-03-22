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

#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;

public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, int> > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;

    /* Looping till all shortest distance are finalized
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int n, m;
    cin >> n >> m;

    int gridsize = (n*m)+10;
    int grid [n][m];

    Graph g(gridsize);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int curr;
    for(int i = 0; i < n; i++){
        curr = i * m;
        g.addEdge(0,curr+1,0);
        g.addEdge(curr+m,gridsize,grid[i][m-1]);
        //g[0].push_back(Edge(0,curr+1,0));
        //g[curr+m].push_back(Edge(curr+m,gridsize,grid[i][m-1]));
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            curr = (i * m) + j + 1;
            if(j == m-1 && i < n-1){

                g.addEdge(curr,curr+m,grid[i+1][j]);
                g.addEdge(curr+m,curr,grid[i+1][j]);
                //g[curr].push_back(Edge(curr,curr+m,grid[i+1][j]));
                //g[curr].push_back(Edge(curr,curr+m,grid[i+1][j]));
            }
            else if (i == n-1 && j < m-1){
                g.addEdge(curr,curr+1,grid[i][j]);
                g.addEdge(curr+1,curr,grid[i][j]);
                //g[curr].push_back(Edge(curr,curr+1,grid[i][j]));
                //g[curr+1].push_back(Edge(curr+1,curr,grid[i][j]));
            }
            else{
                g.addEdge(curr,curr+m,grid[i+1][j]);
                g.addEdge(curr+m,curr,grid[i+1][j]);

                g.addEdge(curr,curr+1,grid[i][j]);
                g.addEdge(curr+1,curr,grid[i][j]);


                //g[curr].push_back(Edge(curr,curr+1,grid[i][j]));
                //g[curr+1].push_back(Edge(curr+1,curr,grid[i][j]));

                //g[curr].push_back(Edge(curr,curr+m,grid[i+1][j]));
                //g[curr+m].push_back(Edge(curr+m,curr,grid[i+1][j]));

            }

        }
    }
    //g.shortestPath(0);
    cout << "test";



}