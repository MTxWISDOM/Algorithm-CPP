// 0-1背包.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int n, c;
	int w[101];
	int v[101];
	int best;
	int m[101][101];
	while (cin >> n >> c)
	{
		best = 0;
		for (int i = 0; i <= n; i++)
		{
			w[i] = 0;
			v[i] = 0;
			for (int j = 0; j <= c; j++)
			{
				m[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (j < w[i])
				{
					m[i][j] = m[i - 1][j];
				}
				else
				{
					m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);
					if (m[i][j] > best)
					{
						best = m[i][j];
					}
				}
			}	
		}
		cout << "best = " << best << endl;
	}
    return 0;
}

