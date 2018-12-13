#include<iostream>

using namespace std;

int num[100];
int n;

void QuickSort(int left, int right)
{
    //cout << left << " " << right <<endl;
    int i = left;
    int j = right;
    int tag = num[left];
    // int temp;
    if(left >= right)
    {
        return;
    }
    while(i != j)
    {
        while(num[j] >= tag && i < j)
        {
            j--;
        }
        if(i < j)
        {
            int temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
        while(num[i] <= tag && i < j)
        {
            i++;
        }
        if(i < j)
        {
           int temp = num[j];
           num[j] = num[i];
           num[i] = temp;
        }
    }
    QuickSort(left, i - 1);
    QuickSort(i + 1, right);
}
int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        QuickSort(0, n - 1);
        for(int i = 0; i < n; i++)
        {
            cout << num[i] << " ";
        }
        cout <<endl;
    }
    return 0;
}
