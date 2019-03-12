#include<iostream>
#include<algorithm>

using namespace std;

struct apple
{
    int appleHeight;
    int applePower;
};

bool cmp(apple a1, apple a2)
{
    return a1.applePower < a2.applePower;
}
int main()
{
    apple A[5001];
    int n, s;
    int chairHeight, handHeight;
    int cau = 0;
    cin >> n >> s >> chairHeight >> handHeight;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i].appleHeight >> A[i].applePower;
    }
    sort(A, A + n, cmp);
    int index = 0;
    while(s >= 0 && index < n)
    {
        if(A[index].appleHeight <= chairHeight + handHeight && A[index].applePower <= s)
        {
            cau++;
            s -= A[index].applePower;
        }
        index++;
    }
    cout << cau <<endl;
    return 0;
}
