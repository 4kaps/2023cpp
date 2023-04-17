#include <iostream>
using namespace std;

int getSpace(int a, int b, int c, int d, int e, int f, int g, int h);
int getLength(int a, int b, int c, int d, int e, int f, int g, int h);

int main(){
    int k;
    cin >> k;
    int a, b, c, d, e, f, g, h;
    while(k-->0){
        int tempe = 0;
        int tempf = 0;
        int tempg = 0;
        int temph = 0;
        cin >> a >> c >> b >> d;
        cin >> e >> g >> f >> h;
        if(a > e){
            tempe = e;
            tempf = f;
            tempg = g;
            temph = h;
            e = a;
            f = b;
            g = c;
            h = d;
            a = tempe;
            b = tempf;
            c = tempg;
            d = temph;
        }
        cout << getSpace(a, b, c, d, e, f, g, h) << ' ' << getLength(a, b, c, d, e, f, g, h) << endl;
    }
}


int getSpace(int a, int b, int c, int d, int e, int f, int g, int h){
    int result = 0;
    if(f > b && e > a && h > d && g > c){
        result = (b-a)*(d-c)+(f-e)*(h-g) - (b-e)*(d-g);
    }else if(b >= f && a <= e && d >= h && c <= g){
        result = (b-a)*(d-c);
    }else{
        result = (b-a)*(d-c)+(f-e)*(h-g);
    }
    if(result < 0){
        return (-1)*result;
    }else{
        return result;
    }
}

int getLength(int a, int b, int c, int d, int e, int f, int g, int h){
    int result = 0;
    if(f > b && e > a && h > d && g > c){
        result = 2*((f-e)+(h-g)+(b-a)+(d-c) - ((b-e)+(d-g)));
        if(e == b){
            result = 2*((f-e)+(h-g)+(b-a)+(d-c) - (d-g));
        }else if(g == d){
            result = 2*((f-e)+(h-g)+(b-a)+(d-c) - (b-e));
        }
    }else if(f > b && e > a && d > h && c > g){
        result = 2*((f-e)+(h-g)+(b-a)+(d-c) - ((b-e)+(h-c)));
        if(e == b){
            result = 2*((f-e)+(h-g)+(b-a)+(d-c) - (h-c));
        }else if(h == c){
            result = 2*((f-e)+(h-g)+(b-a)+(d-c) - (b-e));
        }
    }else if(b >= f && a <= e && d >= h && c <= g){
        result = 2*((b-a)+(d-c));
    }else{
        result = 2*((f-e)+(h-g)+(b-a)+(d-c));
    }
    if(result < 0){
        return (-1)*result;
    }else{
        return result;
    }
}