#include <iostream>
using namespace std;

void your_grade(int score, int *A, int *B, int *C, int *D, int *F, int i);

int main(){
    int t, n, score;
    cin >> t;
    int *A = new int[t];
    int *B = new int[t];
    int *C = new int[t];
    int *D = new int[t];
    int *F = new int[t];
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> score;
            your_grade(score, A, B, C, D, F, i);
        }
    }
    for(int i=0; i<t; i++){
        cout << A[i] << " " << B[i] << " " << C[i] << " " << D[i] << " " << F[i] << endl;
    }
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] F;
}

void your_grade(int score, int *A, int *B, int *C, int *D, int *F, int i){
    if(score >= 90){
        A[i]++;
    }else if(score >= 80){
        B[i]++;
    }else if(score >= 70){
        C[i]++;
    }else if(score >= 60){
        D[i]++;
    }else{
        F[i]++;
    }
}