#include <iostream>
using namespace std;

int kthnum(int num);

int main(){
    int t, num;
    cin >> t;
    while(t-->0){
        cin >> num;
        cout << kthnum(num) << endl;
    }
    return 0;
}

int kthnum(int num){
    int *temp = new int[7];
    int result;
    int a = 0;
    if(0 <= num && num < 10){
        result = num;
    }else if(10 <= num && num < 190){
        a = (num - 10)/2 + 10;
        temp[0] = a/10;
        a = a % 10;
        temp[1] = a;
        result = temp[(num-10)%2];
    }else if(190 <= num && num < 2890){
        a = (num - 190)/3 + 100;
        temp[0] = a/100;
        a = a % 100;
        temp[1] = a /10;
        a= a % 10 ;
        temp[2] = a;
        result = temp[(num-190)%3];
    }else if(2890 <= num && num < 38890){
        a = (num - 2890)/4 + 1000;
        temp[0] = a/1000;
        a = a % 1000;
        temp[1] = a/100;
        a = a % 100;
        temp[2] = a/10;
        a = a % 10;
        temp[3] = a;
        result = temp[(num-2890)%4];
    }else if(38890 <= num && num < 488890){
        a = (num - 38890)/5 + 10000;
        temp[0] = a/10000;
        a = a % 10000;
        temp[1] = a/1000;
        a = a % 1000;
        temp[2] = a/100;
        a = a % 100;
        temp[3] = a/10;
        a = a % 10;
        temp[4] = a;
        result = temp[(num-38890)%5];
    }else if(488890 <= num && num < 1000001){
        a = (num - 488890)/6 + 100000;
        temp[0] = a/100000;
        a = a % 100000;
        temp[1] = a/10000;
        a = a % 10000;
        temp[2] = a/1000;
        a = a % 1000;
        temp[3] = a/100;
        a = a % 100;
        temp[4] = a/10;
        a = a % 10;
        temp[5] = a;
        result = temp[(num-488890)%6];
    }
    delete[] temp;
    return result;
}