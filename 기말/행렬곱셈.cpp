#include <iostream>
using namespace std;

int main(){
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        int r, s, t;
        cin >> r >> s >> t;

        int **A = new int *[r];
        for(int j=0; j<r; j++){
            A[j] = new int [s]();
            for(int l=0; l<s; l++){
                cin >> A[j][l];
            }
        }
        int **B = new int *[s];
        for(int j=0; j<s; j++){
            B[j] = new int [t]();
            for(int l=0; l<t; l++){
                cin >> B[j][l];
            }
        }
        int **C = new int *[r];
        for(int j=0; j<r; j++){
            C[j] = new int [t]();
        }

        for(int j=0; j<s; j++){
            for(int n=0; n<r; n++){
                for(int m=0; m<t; m++){
                    C[n][m] += A[n][j] * B[j][m];
                }
            }
        }
        
        for(int j=0; j<r; j++){
            for(int l=0; l<t; l++){
                cout << C[j][l] << ' ';
            }
            cout << endl;
        }

        for(int j=0; j<r; j++){
            delete[] A[j];
        }
        delete[] A;

        for(int j=0; j<s; j++){
            delete[] B[j];
        }
        delete[] B;

        for(int j=0; j<r; j++){
            delete[] C[j];
        }
        delete[] C;
    }
}
