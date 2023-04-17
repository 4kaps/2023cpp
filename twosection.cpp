#include <iostream>
using namespace std;

int Alen(int a, int b, int c, int d);
int Blen(int a, int b, int c, int d);

int main(){
    int t, a, b, c, d;
    int tempc, tempd;
    cin >> t;
    while(t-->0){
        cin >> a >> b >> c >> d;
        if(a > c){
            tempc = c;
            tempd = d;
            c = a;
            d = b;
            a = tempc;
            b = tempd;
            tempc = 0;
            tempd = 0;
        }
        cout << Alen(a, b, c, d) << ' ' << Blen(a, b, c, d) << endl;
    }
}

int Alen(int a, int b, int c, int d){
    if(c >= a && b >= d){
        return d - c;
    }else if(b - c <= 0){
        return 0;
    }else{
        return b - c;
    }
}

int Blen(int a, int b, int c, int d){
    if(c >= a && b >= d){
        return b - a;
    }else if(b - c <= 0){
        return (d - a) - (c - b);
    }else{
        return d - a;
    }
}
