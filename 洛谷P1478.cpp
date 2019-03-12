/*
题目描述
又是一年秋季时，陶陶家的苹果树结了n个果子。陶陶又跑去摘苹果，这次她有一个a公分的椅子。当他手够不着时，他会站到椅子上再试试。

这次与NOIp2005普及组第一题不同的是：陶陶之前搬凳子，力气只剩下s了。当然，每次摘苹果时都要用一定的力气。陶陶想知道在s<0之前最多能摘到多少个苹果。

现在已知n个苹果到达地上的高度xi，椅子的高度a，陶陶手伸直的最大长度b，陶陶所剩的力气s，陶陶摘一个苹果需要的力气yi，求陶陶最多能摘到多少个苹果。

输入输出格式
输入格式：
第1行：两个数 苹果数n，力气s。

第2行：两个数 椅子的高度a，陶陶手伸直的最大长度b。

第3行~第3+n-1行：每行两个数 苹果高度xi，摘这个苹果需要的力气yi。

输出格式：
只有一个整数，表示陶陶最多能摘到的苹果数。
*/


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
