#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stdio.h>

using namespace std;


int main()
{
    int value[100];
    int weight[100];
    int L;
    queue<int> leave;
    int n;
    int presentw;//当前扩展结点所处的层
    int k; //搜索中的下标
    int c; //第一艘船的载重量
    int bestw; //最优载重量
    while(scanf("%d%d", &n, &c) != EOF)
    {
        L = 0;
        presentw = 0;
        bestw = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &value[i], &weight[i]);
            L += value[i];
        }
        leave.push(-1);
        k = 0;
        while(true)
        {
            //先检查左儿子结点
            int LeftSonW = presentw + weight[k]; //左儿子结点的重量
            if(LeftSonW <= c) //判断是否为可行结点
            {
                if(LeftSonW > bestw) //可行结点并且为更优结点，更新bestw值
                {
                    bestw = LeftSonW;
                }
                if(k < n) //加入到活结点队列
                {
                    leave.push(LeftSonW);
                }
            }

            //检查右儿子结点
            if(presentw + L > bestw && k < n)
            {
                leave.push(presentw);
            }
            presentw = leave.front();
            leave.pop();
            if(presentw == -1)
            {
                if(leave.empty())
                {
                    printf("%d\n", bestw);
                    break;
                }
                leave.push(-1);
                presentw = leave.front();
                k++;
                L -= weight[k];
            }
        }
    }
    return 0;
}
