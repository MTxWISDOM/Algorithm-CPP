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
    int presentw;//��ǰ��չ��������Ĳ�
    int k; //�����е��±�
    int c; //��һ�Ҵ���������
    int bestw; //����������
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
            //�ȼ������ӽ��
            int LeftSonW = presentw + weight[k]; //����ӽ�������
            if(LeftSonW <= c) //�ж��Ƿ�Ϊ���н��
            {
                if(LeftSonW > bestw) //���н�㲢��Ϊ���Ž�㣬����bestwֵ
                {
                    bestw = LeftSonW;
                }
                if(k < n) //���뵽�������
                {
                    leave.push(LeftSonW);
                }
            }

            //����Ҷ��ӽ��
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
