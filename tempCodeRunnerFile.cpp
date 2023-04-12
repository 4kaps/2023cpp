#include <iostream>
using namespace std;

int main(){
    int t, n, price;
    int highest = 2;
    cin >> t;
    int* count = new int[t];
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> price;
            if(j==0){
                highest = price;
            }else if(price > highest && j!=0){
                highest = price;
            }else if(price < highest && j!=n && j!=1 && j!=0){
                count[i]++;
                highest = price;
            }
        }
    }
    for(int i=0; i<t; i++){
        cout << count[i] << endl;
    }
    delete[] count;
}

