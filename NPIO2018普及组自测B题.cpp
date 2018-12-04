
//NPIO2018普及组自测B题

/*题目描述
轩轩和凯凯正在玩一款叫《龙虎斗》的游戏，游戏的棋盘是一条线段，线段上有 nn 个兵营（自左至右编号 1 \sim n1∼n），相邻编号的兵营之间相隔 11 厘米，即棋盘为长度为 n-1n−1 厘米的线段。ii 号兵营里有 c_ic
i
​	 位工兵。 下面图 1 为 n=6n=6 的示例：



轩轩在左侧，代表“龙”；凯凯在右侧，代表“虎”。 他们以 mm 号兵营作为分界， 靠左的工兵属于龙势力，靠右的工兵属于虎势力，而第 mm 号兵营中的工兵很纠结，他们不属于任何一方。

一个兵营的气势为：该兵营中的工兵数 \times × 该兵营到 mm 号兵营的距离；参与游戏 一方的势力定义为：属于这一方所有兵营的气势之和。
下面图 2 为 n = 6,m = 4n=6,m=4 的示例，其中红色为龙方，黄色为虎方：



游戏过程中，某一刻天降神兵，共有 s_1s
1
​	  位工兵突然出现在了 p_1p
1
​	  号兵营。作为轩轩和凯凯的朋友，你知道如果龙虎双方气势差距太悬殊，轩轩和凯凯就不愿意继续玩下去了。为了让游戏继续，你需要选择一个兵营 p_2p
2
​	 ，并将你手里的 s_2s
2
​	  位工兵全部派往 兵营 p_2p
2
​	 ，使得双方气势差距尽可能小。

注意：你手中的工兵落在哪个兵营，就和该兵营中其他工兵有相同的势力归属（如果落在 mm 号兵营，则不属于任何势力）。


*/
#include<iostream>

using namespace std;

long long n;
long long c[10001];
long long m, p1, s1, s2;
long long D, L;
long long lever;
long long mark;

long long abs(long long a)
{
    if(a >= 0)
    {
        return a;
    }
    return -a;
}

void binaryCheck(long long left, long long right, long long more, long long le)
{
    for(int i = left; i <= right; i++)
    {
        long long r = abs((more + (c[i] + s2)) - le);
        cout << "r=" << r << endl;
        if(r < lever)
        {
            mark = i;
            lever = r;
        }
    }
}

int main()
{
    while(cin >> n)
    {
        D = L = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        cin >> m >> p1 >> s1 >> s2;
        for(int i = 1; i <= n; i++)
        {
            if(i < m)
            {
                if(i == p1)
                {
                    D += (c[i] + s1) * abs(m - i);
                    continue;
                }
                D += c[i] * abs(m - i);
            }
            else if(i == m)
            {
                continue;
            }
            else
            {
                if(i == p1)
                {
                    L += (c[i] + s1) * abs(m - i);
                    continue;
                }
                L += c[i] + abs(m - i);
            }
        }
        lever = abs(D - L);
        if(D == L)
        {
            cout << m << endl;
            continue;
        }
        else if(D < L)
        {
            binaryCheck(0, m - 1, D, L);
        }
        else
        {
            binaryCheck(m + 1, n, L, D);
        }
        cout << mark << endl;
    }
    return 0;
}
