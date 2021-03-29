//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  collidingtraffic solution by prof: https://eclass.srv.ualberta.ca/pluginfile.php/7035236/mod_resource/content/1/collidingtraffic.cpp
//  Collision of spheres: https://studiofreya.com/3d-math-and-physics/little-more-advanced-collision-detection-spheres/
//  For above only formulas looked at, not code
//  Formula for quadratic roots https://www.programiz.com/cpp-programming/examples/quadratic-roots//
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

# include <bits/stdc++.h>

using namespace std;

struct spaceObject{
    long double x, y, z, r, vx, vy, vz;
};

long double dot(long double x1, long double y1, long double z1, long double x2, long double y2,long double  z2){
    return x1*x2 + y1*y2 + z1*z2;
}

void solve(){
    spaceObject sc;
    spaceObject sj;
    cin >> sc.x >> sc.y >> sc.z >> sc.r >> sc.vx >> sc.vy >> sc.vz;
    cin >> sj.x >> sj.y >> sj.z >> sj.r >> sj.vx >> sj.vy >> sj.vz;

    spaceObject diff;
    diff.x = sc.x-sj.x; diff.y = sc.y-sj.y; diff.z = sc.z-sj.z;
    diff.vx = sc.vx-sj.vx; diff.vy = sc.vy-sj.vy; diff.vz = sc.vz-sj.vz;
    diff.r = (sc.r + sj.r)*(sc.r + sj.r);

    long double dist = dot(diff.x,diff.y, diff.z, diff.x, diff.y, diff.z);
    //cout << '\n';
    //cout << diff.x<< " "<< diff.y<< " "<< diff.z << " "<<diff.vx << " "<< diff.vy<< " "<< diff.vz<< " "<< '\n';

    long double b = dot(diff.vx,diff.vy, diff.vz, diff.x, diff.y, diff.z);
    long double a = dot(diff.vx,diff.vy, diff.vz, diff.vx, diff.vy, diff.vz);
    long double d = b*b - a*dist;
    //cout <<b << " "<< a << " " << dist <<" " << d << '\n';

    long double c = dist - diff.r;
    b = b*2;
    long double discriminant = b*b - 4*a*c;

    cout << setprecision(3);
    cout << fixed;

    if (a == 0 || b>=0){
        cout << "No collision" << '\n';
    }

    else if (discriminant > 0) {
        long double out = (-b - sqrt(discriminant)) / (2*a);
        long double out2 = (-b + sqrt(discriminant)) / (2*a);

        if (out >= 0){
            cout << out << '\n';
        }
        else if (out2 > 0){
            cout << out2 << "\n";
        }
        else{
            cout << "No collision" << '\n';
        }
    }
    else if (discriminant == 0){
        long double out = (-b/(2*a));
        cout << out << '\n';
    }
    else{
        cout << "No collision" << '\n';
    }





}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}