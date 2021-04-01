//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  N/A
//
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

struct point{
    long double x; long double y;
};

long double slope (long double x1, long double x2, long double y1, long double y2){
    if(x1 == x2){
        return 921.8372;
    }
    return (y2-y1)/(x2-x1);
}

long double yint (long double m, long double x, long double y){
    return (y - m*x);
}

point intersect(long double m1, long double m2, long double b1, long double b2){
    point inter;
    if(m1 == 921.8372){
        inter.x = 0;
        inter.y = m2*inter.x + b2;
        return inter;
    }
    else if (m2 == 921.8372){
        inter.x = 0;
        inter.y = m1*inter.x + b1;
        return inter;
    }
    inter.x = (b1 - b2)/(m2-m1);
    inter.y = m1*inter.x + b1;
    return inter;

}

long double dist(long double x1, long double x2, long double y1, long double y2){
    //cout << x2 << x1 << y2 << y1;
    //long double x = (x2-x1);
    //long double y = (y2-y1);
    //cout << "x" << x <<" y:" << y << "\n";
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
    int n;
    vector<point> intersections;
    vector<point> lines;
    unordered_map<string, bool> dupl;
    cin >> n;
    long double x1, y1, x2, y2, m, b;
    for(int i = 0; i < n; i++){
        point line;
        cin >> x1 >> y1 >> x2 >> y2;
        m = slope(x1, x2, y1, y2);
        b = yint(m,x1,y1);
        line.x = m;
        line.y = b;
        lines.push_back(line);
    }

    bool possible = false;

    double max = 0;

    for(int i = 0; i < n-2; i++){
        point line1 = lines[i];
        for(int j = i+1; j < n-1; j++){
            point line2 = lines[j];
            if (line1.x != line2.x){
                for(int k = j+1; k < n; k++)
                {
                    point line3 = lines[k];
                    if(line1.x != line3.x && line2.x != line3.x){
                        string s;
                        point inter1 = intersect(line1.x, line2.x, line1.y, line2.y);
                        s = to_string(inter1.x) + to_string(inter1.y);
                        dupl[s] = true;
                        point inter2 = intersect(line2.x, line3.x, line2.y, line3.y);
                        s = to_string(inter2.x) + to_string(inter2.y);
                        dupl[s] = true;
                        point inter3 = intersect(line1.x, line3.x, line1.y, line3.y);
                        s = to_string(inter3.x) + to_string(inter3.y);
                        dupl[s] = true;

                        //cout << s << '\n';
                        if (dupl.size()>2){
                            possible = true;
                            long double perimeter = 0;
                            perimeter += dist(inter1.x, inter2.x, inter1.y, inter2.y);
                            //cout << dist(p1.x, p2.x, p1.y, p2.y) << '\n';
                            perimeter += dist(inter2.x, inter3.x, inter2.y, inter3.y);
                            //cout << p3.x - p2.x << '\n';
                            perimeter += dist(inter1.x, inter3.x, inter1.y, inter3.y);
                            //cout << dist(p1.x, p2.x, p3.y, p3.y) << '\n';
                            if (perimeter > max){
                                max = perimeter;
                            }
                        }

                    }



                    //intersections.insert(intesect(line1.x, line2.x, line1.y, line2.y));
                }

            }


        }

    }
    if (possible){
        cout << max;
    }
    else{
        cout << "no triangle";
    }

    /*

    for (int i = 0; i < intersections.size(); ++i) {
        cout << intersections[i].x << " " << intersections[i].y << "\n";
    }
     */








}