#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int main()
{
    int a[100] = {0};
    int n;
    int dp[100];
    while(cin >> n)
    {
        for( int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for( int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                dp[i] = 1;

            }
            else
            {
                if(a[i] - a[i - 1] <= 0)
                {
                    dp[i] = 1;

                }
                else
                {
                    dp[i] = dp[i - 1] + 1;

                }
            }
        }
        int mark = dp[0];
        for(int i = 0; i < n; i++)
        {
            if(dp[i] > mark)
            {
                mark = dp[i];
            }

        }
        if(mark == 1)
        {
            mark = 0;
        }
        cout << "最长上升子序列的长度为" << mark <<endl;


    }
    return 0;
}