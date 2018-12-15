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
    int mark[100];
    int k;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> num[i];
            dp[i] = num[i];
        }
        k = 0;
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = MAX(dp[i - 1], dp[i - 1] + num[i]);
            if(dp[i - 1] + num[i] > dp[i - 1])
            {
                mark[k++] = num[i];
            }
        }
        for(int i = 0; i < k; i++)
        {
            cout << mark[i] << " ";
        }
        cout << endl << dp[n - 1] << endl;
    }
    return 0;
}