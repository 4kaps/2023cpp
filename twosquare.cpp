#include <iostream>
#include <algorithm>
using namespace std;

int getSpace(int a, int b, int c, int d, int e, int f, int g, int h, bool gup, int gupa, int gupb, int gupc, int gupd);
int getLength(int a, int b, int c, int d, int e, int f, int g, int h, bool gup, int gupa, int gupb, int gupc, int gupd);

int main(){
    int k;
    cin >> k;
    int a, b, c, d, e, f, g, h;
    while(k-->0){
        int gupa = 0;
        int gupb = 0;
        int gupc = 0;
        int gupd = 0;
        bool gup;
        cin >> a >> c >> b >> d;
        cin >> e >> g >> f >> h;
        gupa = max(a, e);
        gupb = min(b, f);
        gupc = max(g, c);
        gupd = min(d, h);
        if(gupb > gupa && gupd > gupc){
            gup = true;
        }else{
            gup = false;
        }
        cout << getSpace(a, b, c, d, e, f, g, h, gup, gupa, gupb, gupc, gupd) << ' ' << getLength(a, b, c, d, e, f, g, h, gup, gupa, gupb, gupc, gupd) << endl;
    }
}


int getSpace(int a, int b, int c, int d, int e, int f, int g, int h, bool gup, int gupa, int gupb, int gupc, int gupd){
    int result = 0;
    int Space1 = (b-a)*(d-c);
    int Space2 = (f-e)*(h-g);
    int gupSpace = (gupb-gupa)*(gupd-gupc);
    if(!gup){
        result = Space1 + Space2;
    }
    if(gup){
        if(min(Space1, Space2) == gupSpace){
            result = max(Space1, Space2);
        }else{
            result = Space1 + Space2 - gupSpace;
        }
    }
    return result;
}

int getLength(int a, int b, int c, int d, int e, int f, int g, int h, bool gup, int gupa, int gupb, int gupc, int gupd){
    int result = 0;
    int Len1 = b-a;
    int Len2 = d-c;
    int Len3 = f-e;
    int Len4 = h-g;
    int gupLen1 = gupb-gupa;
    int gupLen2 = gupd-gupc;
    if(!gup){
        result = 2*(Len1 + Len2 + Len3 + Len4);
    }
    if(gup){
        if(Len1 == gupLen1 && Len2 == gupLen2){
            result = 2*(Len3 + Len4);
        }else if(Len3 == gupLen1 && Len4 == gupLen2){
            result = 2*(Len1 + Len2);
        }else{
            result = 2*(Len1 + Len2 + Len3 + Len4) - 2*(gupLen1 + gupLen2);
        }
    }
    return result;
}