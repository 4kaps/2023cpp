#include <iostream>
using namespace std;

void fill(int &a, int &b, int **arr, int &cnt, int n){
    while(a >= 0 && b < n && arr[a][b] == 0){
        arr[a][b] = cnt;
        a--; b++; cnt++; 
    }
}

int main(){
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int n;
        cin >> n;
        int** arr = new int *[n];
        
        for(int j=0; j<n; j++){
            arr[j] = new int[n]();
        }
        
        int center = n/2;
        arr[0][center] = 1;
        int cnt = 2;
        int a = n - 1;
        int b = center + 1;
        
        fill(a, b, arr, cnt, n);
        while(cnt < n*n){
            if(a == -1 && b == n){
                a+=2; b--;
                fill(a, b, arr, cnt, n);
            }
            if(b == n){
                b = 0; 
                fill(a, b, arr, cnt, n);
            }
            if(a == -1){
                a = n - 1;
                fill(a, b, arr, cnt, n);
            }
            else if(arr[a][b] != 0){
                a+=2; b--;
                fill(a, b, arr, cnt, n);
            }
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
        for(int j=0; j<n; j++){
            delete[] arr[j];
        }
        delete[] arr;
    }
}
