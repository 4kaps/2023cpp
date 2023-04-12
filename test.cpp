#include <iostream>

using namespace std;

int main()
{
    int i;
    cin >> i;
    int num;
    int prev = 0,curr;
    int cnt;
    bool a;
    while(i-->0)
    {
        a = false;
        cnt = 0;
        prev = 0;
        cin >> num;
        for(int j = 0; j < num ; j++)
        {
            cin >> curr;
            if(curr>prev)
            {
                prev = curr;
                if(j!=0)
                {
                    a = true;
                }
            }
            else if(prev > curr && a == true)
            {
                prev = curr;
                cnt++;
                a = false;
            }
            prev = curr;
        }
        cout << cnt << endl;
    }

    return 0;
}