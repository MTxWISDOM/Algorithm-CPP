#include<iostream>

using namespace std;

int num[100];
int n;
int mark[100];

void Merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right)
    {
        if(num[i] <= num[j])
        {
            mark[k++] = num[i++];
        }
        else
        {
            mark[k++] = num[j++];
        }
    }
    while(i <= mid)
    {
        mark[k++] = num[i++];
    }
    while(j <= right)
    {
        mark[k++] = num[j++];
    }
    k = 0;
	while (left <= right)
	{
		//cout << left << " " << right << endl;
		num[left++] = mark[k++];
	}
}

void depart(int left, int right)
{

    if(left < right)
    {
        int mid = (left + right) / 2;
        depart(left, mid);
        depart(mid + 1, right);
        Merge(left, mid, right);
    }
}
int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        depart(0, n - 1);
        for(int i = 0; i < n; i++)
        {
            cout << num[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}
