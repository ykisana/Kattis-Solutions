//*
//  <Yahya Kisana>
//  <1556834>
//
//  List any resources you used below (eg. urls, name of the algorithm from our code archive).
//  Remember, you are permitted to get help with general concepts about algorithms
//  and problem solving, but you are not permitted to hunt down solutions to
//  these particular problems!
//
//  //  Formula for quadratic roots https://www.programiz.com/cpp-programming/examples/quadratic-roots//
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

const long double Epsilon = 1E-10;
long long pi = 3.1415926;

typedef complex<long double> Point;

long double dot(Point x, Point y){
    return ((x.imag() * y.imag() + x.real() * y.real()));
}

long double collision(Point x, Point y, Point v, long double r){
    y = y-x;
    //cout << y.real() <<" " <<  y.imag() << "\n";
    long double a = dot(v,v);
    long double b = dot(v, y);
    long double c = dot(y,y) - (4*r*r);
    // cout << a <<" " << b << " "<< c << "\n";
    long double discriminant = b*b - 4*a*c;
    y *= -2;
    //cout << discriminant << "\n";

    if (a < -Epsilon || discriminant < -Epsilon){
        return -1;
    }

    else if (discriminant == 0){
        long double out = (-b/(2*a));
        if(out >=0){
            return out;
        }
        else{
            return -1;
        }
    }
    else{
        long double out = (-b - sqrt(discriminant)) / (2*a);
        if(out >=0){
            return out;
        }
        else{
            return -1;
        }
    }


}

int main(){
    long double x1, y1, x2, y2, x3, y3, xv, yv, r;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xv >> yv >> r;

    r = r * pi/180;

    Point p1 = Point(x1, y2);
    Point p2 = Point(x2, y2);
    Point p3 = Point(x3, y3);
    Point v = Point(xv, yv);

    double onetwo = collision(p1,p2,v,r);
    double twothree = collision(p2,p3,v,r);
    double onethree = collision(p1, p3,v,r);
    double threetwo = collision(p3, p2,v,r);
    double temp;

    bool h1;
    bool h2;

    //cout << onetwo << " " << twothree << " "<< onethree << " " << threetwo<<"\n";
    if (onetwo == -1 && onethree == -1){
        cout << 5;
        return 0;
    }
    else if (onethree && threetwo){
        if(onetwo < onethree){
            h2 = false;
        }
        else{
            h2 = false;
        }


    }
    if(h2){
        if (twothree){
            cout << 1;
            return 0;
        }
        else{
            cout << 3;
            return 0;
        }
    }
    else{
        if(threetwo){
            cout << 2;
            return 0;
        }
        else{
            cout << 4;
        }
    }
}