#include <iostream>
using namespace std;

int main(){
    int t, n, num1, num2, num3, temp, first_num;
    bool first_continue = false;
    cin >> t;
    int count = 0;
    for(int i=0; i<t; i++){
        cin >> n >> num1 >> num2;
        for(int j=0; j<n-2; j++){
            cin >> temp;
            num3 = temp;
            if(j==0){
                first_num = num1;
            }
            if((num1 <= num2) && (num3 < num2)){
                count+=1;
            }
            if((first_num == num1 == num2 == num3) || ((num1 == num2) && (j==0))){
                first_continue = true;
            }
            if((num1 == num2) && (num3 < num2) && (num1 == first_num) && (first_continue)){
                count-=1;
                first_continue = false;
            }
            num1 = num2;
            num2 = num3;
        }
        cout << count << endl;
        count = 0;
        first_continue = false;
    }
}
/*
first_num : 첫 세 수를 비교할때, num1 값
first_continue : 첫 값이 이어지는 5 5 5 / 5 5 3(j=0) -> true
*/


