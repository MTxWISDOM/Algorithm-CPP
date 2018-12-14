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
        for(int i = 0; i < n; i++)
        {
            cin >> num[i];
            mark[i] = 0;
            //r[i] = 0;
        }
        tag = 1;
        mark[0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(num[i] > num[i - 1])
            {
                tag = 1;
            }
            else
            {
                tag = -1;
            }
            mark[i] = MAX(mark[i - 1] + tag, mark[i - 1]);
        }
        cout << mark[n - 1] <<endl;
    }
    return 0;
}
