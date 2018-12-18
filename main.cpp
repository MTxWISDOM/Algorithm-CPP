#include<iostream>
using namespace std;

int main()
{
    char line1[100];
    char line2[100];
    int dp[100][100];
    char tag[100];
    int isGet[100];
    int len1, len2;
    while(cin >> len1 >> len2)
    {
        for(int i = 1; i <= len1; i++)
        {
            cin >> line1[i];
            dp[i][0] = 0;
        }
        for(int i = 1; i <= len2; i++)
        {
            cin >> line2[i];
            dp[0][i] = 0;
            isGet[i] = 1;
        }
        int k = 0;
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(line1[i] == line2[j] && isGet[j] == 1)
                {
                    cout << line1[i] << " " << line2[j] <<endl;
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    tag[k++] = line1[i];
                    isGet[j] = 0;
                }
                else if(dp[i - 1][j] >= dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    //tag[i][j] = 2;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    //tag[i][j] = 3;
                }
            }
        }
        cout << dp[len1][len2] << " ";
        for(int i = 0; i < k; i++)
        {
            cout << tag[i];
        }
        cout << endl;
    }
    return 0;
}