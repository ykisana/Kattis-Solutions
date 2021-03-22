/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Top-Sort/Graph Class/Cycle Check using DFS from Geeks for Geeks:
  https://www.geeksforgeeks.org/topological-sorting/
  https://www.geeksforgeeks.org/detect-cycle-in-a-graph/



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


class Graph {

    int V;

    list<int>* adj;

    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:

    Graph(int V);

    void addEdge(int v, int w);


    void topologicalSort();
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{

    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{

    visited[v] = true;


    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);


    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;


    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;


    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);


    while (Stack.empty() == false) {
        cout << Stack.top()+1 << "\n";
        Stack.pop();
    }
}
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}
int main(){
    int n, m;
    cin >> n >> m;


    Graph G(n);
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        G.addEdge(u-1,v-1);
    }
    if(G.isCyclic()){
        cout << "IMPOSSIBLE";
    }
    else {
        G.topologicalSort();
    }


}