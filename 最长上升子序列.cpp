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
    int mark[100];
    //int r[100];
    int tag;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> num[i];
            mark[i] = 1;
            //r[i] = 0;
        }
        tag = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(num[j + 1] > num[j])
                {
                    mark[i] = MAX(mark[i - 1], mark[j] + 1);
                }
            }
        }
        cout << mark[n - 1] <<endl;
    }
    return 0;
}
