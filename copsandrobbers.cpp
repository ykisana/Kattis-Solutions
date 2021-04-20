/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Profs use of maxflow from openpitmining: https://eclass.srv.ualberta.ca/pluginfile.php/6659203/mod_resource/content/3/openpitmining.cpp

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

using ll = long long;
const ll INF = 100600000; // infinity

struct Edge {
    long long u, v;
    ll cap;
};

long long dx[4] = {-1, 0, 1, 0};
long long dy[4] = {0, 1, 0, -1};

vector<Edge> edges;
vector<vector<long long>> g; // g[v] will be the vector of indices long longo edges[] corresponding to edges exiting v

vector<long long> par; // for the BFS to find an augmenting path

// Find an s-t path in the residual graph and augment flow along this path.
// Return the amount of flow augmented. If there was no s-t path in the residual
// graph then the flow we have is a maximum flow already and 0 is returned.
ll augment(long long s, long long t) {
    for (long long& x : par) x = -1;
    queue<long long> q;
    q.push(s);

    // Run a BFS in the residual graph to find an augmenting s-t path.
    while (q.size() > 0 && par[t] == -1) {
        long long u = q.front();
        q.pop();

        for (long long i : g[u]) {
            long long v = edges[i].v;
            if (par[v] != -1 || edges[i].cap == 0) continue;
            par[v] = i;
            q.push(v);
        }
    }

    // now par[v] will be the index of the edge (u,v) in edges[] that was used
    // to reach v in search.

    if (par[t] == -1) return 0;

    // If we get here, there was an augmenting path. Find the least-capacity
    // edge on the s-t path found by the search.
    ll aug = INF;
    long long tmp = t;
    while (tmp != s) {
        long long i = par[tmp];
        aug = min(aug, edges[i].cap);
        tmp = edges[i].u;
    }

    // Now step back along the s-t path again, but this time augment the flow.
    tmp = t;
    while (tmp != s) {
        long long i = par[tmp];
        // Trick: the edges appear in pairs by how we inserted them.
        // So edge i and i^1 (i.e. flip the least-significant bit)
        // form the regular/residual pair of edges.
        edges[i].cap -= aug;
        edges[i^1].cap += aug;
        tmp = edges[i].u;
    }

    return aug;
}

// Edmonds-Karp algorithm for computing a maximum flow.
// Augment flow along shortest s-t paths.
ll maxflow(long long s, long long t) {
    par.resize(g.size());

    ll flow = 0;

    // Continue as long as we found an augmenting path.
    while (true && flow < INF) {
        ll aug = augment(s, t);
        if (!aug) return flow;
        flow += aug;
    }
    return -1;
}


// Add individual edge (u,v) with capacity c.
// DO NOT CALL THIS FUNCTION DIRECTLY to construct the graph.
// Call the function add_edge, it will add both the normal edge and the residual
// edge to the graph.
void push(long long u, long long v, ll c) {
    g[u].push_back(edges.size());
    edges.push_back({u, v, c});
}

// Add directed edge (u,v) with capacity c. This will also add the residual edge.
void add_edge(long long u, long long v, ll c) {
    push(u, v, c); // regular edge`
    push(v, u, 0); // residual edge

    // Uncomment if we are supposed to be adding an undirected edge (u,v).
    // push(v, u, c);
    // push(u, v, 0);
}

void init_graph(long long n) {
    edges.clear();
    g.assign(n, vector<long long>(0));
}

long long v1(long long x,long long y,long long n,long long m){
    return (x*n + y);
}
long long v2(long long x,long long y,long long n,long long m){
    return ((x*n) + (n*m) +y);
}

bool range(long long x, long long y, long long n, long long m){
    return (x >= 0 && y >= 0 && x < m && y < n);
}


int main(){
    long long n, m, c, a, b;
    cin >> n >> m >> c;
    long long t = n*m*2+1;
    init_graph(t);
    long long vals[c+1];
    char g1[31][31];
    long long bank;
    long long starti, startj;
    long long x1[4] = {1,-1,0,0};
    long long x2[4] = {0, 0, 1, -1};
    long long y1, y2;
    long long counter = 0;
    //cout << "t: "<< t << '\n';

    for(long long i = 0; i < m; i++){
        for(long long j = 0; j < n; j++){
            cin >> g1[i][j];
        }
    }
    //cout << "t: "<< t << '\n';
    for(long long i = 0; i < c; i++){
        cin >> vals[i];
    }
    //cout << "t: "<< t << '\n';

    bool checker = false;


    for(long long i = 0; i < m; i++){

        for(long long j = 0; j < n; j++){
            if (g1[i][j] == '.') {
                add_edge(v1(i,j,n,m),v2(i,j,n,m),INF);
                //cout << v1(i,j,n,m) <<" " << v2(i,j,n,m) << ": INF"<< '\n';
                //cout << "test";
            }

            else if (g1[i][j] == 'B'){
                //cout << "test";
                bank = v2(i,j,n,m);

                add_edge(bank,bank,INF);
                //cout << "test";
            }
            else{
                //cout << "test this:" << g1[i][j];
                //cout << counter << " ";
                //counter ++;

                add_edge(v1(i,j,n,m), v2(i,j,n,m), vals[g1[i][j] - 'a']);
                //cout << "here: "<< g1[i][j] << " "<<   vals[g1[i][j] - 'a'] << '\n';
                //cout << v1(i,j,n,m) <<" " << v2(i,j,n,m) << ": " << vals[g1[i][j] - 'a']<< '\n';
            }
            //cout << "pass:" <<i;
            long long counter2 = 0;
            for(long long k = 0; k < 4; k++){
                //cout << "\n";
                y1 = (i + x1[k]);
                y2 = (j + x2[k]);
                if (range(y1,y2,n,m)){
                    add_edge(v2(i,j,n,m), v1(y1,y2,n,m), INF);

                    //cout << v2(i,j,n,m) <<" " << v1(y1,y2,n,m) << ": INF"<< '\n';

                }
                else{
                    //cout << "test4";
                    //cout << v2(i,j,n,m) <<" " << t -1<< ": INF"<<'\n';
                    add_edge(v2(i,j,n,m), t-1, INF);

                }



            }



        }



    }


    //cout << "test123: "<< t;


    cout <<  maxflow(bank, t-1) << endl;

}



