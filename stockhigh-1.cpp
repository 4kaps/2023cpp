#include <iostream>
using namespace std;

int main(){
    int t, n, count, num1, num2;
    bool canCount;
    cin >> t;
    for(int i=0; i<t; i++){
        canCount = false;
        count = 0;
        num1 = 0;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> num2;
            if(num2 > num1){
                num1 = num2;
                if(j!=0){
                    canCount = true;
                }
            }else if(num1 > num2 && canCount){
                num1 = num2;
                count++;
                canCount = false;
            }
            num1 = num2;
        }
        cout << count << endl;
    }
}

