#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string inp;
    char temp[6];
    double v=0, va=0, vb=0, vc=0;
    double control = 0, ca=0, cb=0, cc=0;
    double a=0, b=0, c=0;
    for(int i = 0; i<n; i++){
        cin >> temp;
        //strcpy(temp, inp.c_str());
        if (temp[0]=='Y'){
            v++;
            if (temp[1] == 'Y'){
                va++;
                a++;
            }
            if (temp[2] == 'Y'){
                vb++;
                b++;
            }
            if (temp[3] == 'Y'){
                vc++;
                c++;
            }
        }
        else if (temp[0]=='N'){
            control++;
            if (temp[1] == 'Y'){
                ca++;
                a++;
            }
            if (temp[2] == 'Y'){
                cb++;
                b++;
            }
            if (temp[3] == 'Y'){
                cc++;
                c++;
            }
        }

    }

    setprecision(6);
    double a_ef, b_ef, c_ef;
    a_ef = (((ca*100/control))-((va*100/v)))/(ca/control);
    b_ef = (((cb*100/control))-((vb*100/v)))/(cb/control);
    c_ef = ((cc*100/control)-(vc*100/v))/(cc/control);

    cout << fixed;

    if(a_ef <= 0){
        cout << "Not Effective" << "\n";
    }
    else{
        cout << a_ef<<"\n";
    }

    if(b_ef <= 0){
        cout << "Not Effective" << "\n";
    }
    else{
        cout << b_ef<<"\n";
    }
    if(c_ef <= 0){
        cout << "Not Effective" << "\n";
    }
    else{
        cout << c_ef<<"\n";
    }



}
