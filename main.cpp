#include<iostream>

using namespace std;

int a[100];
int n;

void quickSort(int left, int right)
{
    int tag = a[left];
    int i = left;
    int j = right;
    if(i >= j)
        return;
    while(i != j)
    {
        while(i < j && a[j] >= tag)
        {
            j--;
        }
        a[i] = a[j];
        while(i < j && a[i] < tag)
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = tag;
    quickSort(left, i);
    quickSort(i + 1,right);
}

int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        quickSort(0, n - 1);
        for(int i = 0 ;i < n; i++)
        {
            cout << a[i];
        }
        cout <<endl;
    }

}