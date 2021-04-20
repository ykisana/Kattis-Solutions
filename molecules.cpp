/*
  <Yahya Kisana>
  <1556834>

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Profs solution to equationsolverplus for rref and general refrence: https://eclass.srv.ualberta.ca/pluginfile.php/6659206/mod_resource/content/1/equationsolverplus.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  Discussed solving equations with prof

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/


#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 200;
const long double EPS = 1e-8;
using vd = vector<long double>;
using vvd = vector<vd>;

// Reduces m to RREF
// Assumes all rows have the same length.
void rref(vvd& m) {
    long long nr = m.size(), nc = m[0].size();

    for (int r = 0, c = 0; c < nc; ++c) {
        // F
        // ind a row to pivot on, choose the one with smallest absolute value for the pivot entry
        long long p = -1;
        for (int i = r; i < nr; ++i)
            if (fabs(m[i][c]) > EPS && (p == -1 || fabs(m[i][c]) > fabs(m[p][c])))
                p = i;

        if (p == -1) continue; // no pivot for this column

        // swap the pivot row into row r
        swap(m[p], m[r]);

        // normalize pivot row (now at row r) so the leading coefficient is 1
        for (int tc = nc-1; tc >= c; --tc) m[r][tc] /= m[r][c];

        // use row operations to clear all remaining nonzeros in this column
        for (int tr = 0; tr < nr; ++tr) {
            if (tr == r || fabs(m[tr][c]) < EPS) continue; // don't bother if it is already 0
            for (int tc = nc-1; tc >= c; --tc)
                m[tr][tc] -= m[r][tc]*m[tr][c];
        }

        ++r;
    }
}


template <typename T>
void print_2d_vector(const vector< vector<T> > & matrix)
{
    for(auto row_obj : matrix)
    {
        for (auto elem: row_obj)
        {
            cout<<elem<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main() {
    int n, m;
    int u, v;
    long double p1, p2;
    cin >> n >> m;
    bool fix[n][n];
    bool unknown[n];
    long double x[n];
    long double y[n];
    long long ff[n] = {0};
    vd temp(n);
    vvd grid(n, temp);
    vvd xmat(n, temp);
    vvd ymat(n, temp);
    vd empt(n, 0);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        unknown[i] = false;
        if(x[i] == -1){
            unknown[i] = true;
        }
        for(int j = 0; j < n; j++){
            fix[i][j] = false;
        }
    }


    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--;
        v--;
        ff[u] += 1;
        ff[v] += 1;
        fix[u][v] = true;
        fix[v][u] = true;
    }

    for(int i = 0; i < n; i++){
        p1 = 0;
        p2 = 0;

        if (!unknown[i]){
            vd vdx(n+1,0.0);
            vdx[i] = 1.0;
            vdx[n] = x[i];
            vd vdy(n+1,0.0);
            vdy[i] = 1.0;
            vdy[n] = y[i];
            xmat[i] = vdx;
            ymat[i] = vdy;


        }
        else{
            vd vdx;
            vd vdy;
            for(int j = 0; j < n; j++){
                if (fix[i][j]){
                    //cout << i << " " << j << "\n";
                    if (!unknown[j]){
                        vdx.push_back(0.0);
                        vdy.push_back(0.0);
                        p1 += x[j];
                        p2 += y[j];
                    }
                    else{
                        vdx.push_back(-1);
                        vdy.push_back(-1);

                    }
                }
                else if (i == j){
                    vdx.push_back(ff[i]);
                    vdy.push_back(ff[i]);
                }
                else{
                    vdx.push_back(0);
                    vdy.push_back(0);
                }

            }
            vdx.push_back(p1);
            vdy.push_back(p2);
            xmat[i] = vdx;
            ymat[i] = vdy;
        }
    }

    //print_2d_vector(xmat);

    //cout << '\n';
    //print_2d_vector(ymat);

    //cout << '\n';


    rref(xmat);

    //print_2d_vector(xmat);
    //cout << '\n';
    rref(ymat);
    //print_2d_vector(ymat);

    for(int i = 0; i < n;i++){
        cout << xmat[i][n] << " " << ymat[i][n] << '\n';
    }




    //cout << "test";



}