#include<iostream>

using namespace std;

int MAX(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}
int main()
{
    int num[100];
    int n;
    int dp[100];
    //int mark;
    int Max;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> num[i];
            //mark[i] = 0;
        }
        Max = -10000000;
        dp[0] = -10000000;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = MAX(num[i], dp[i - 1] + num[i]);
            if(Max < dp[i])
            {
                Max = dp[i];
            }
        }
        cout << Max <<endl;
    }
    return 0;
}
