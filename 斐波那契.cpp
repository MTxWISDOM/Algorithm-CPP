#include"stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;

int f[101];

int fin(int n) {
	cout << "n =" << n << endl;
	if (n == 0 || n == 1) {
		return 1;
	}
	return fin(n - 1) + fin(n - 2);
}
int main() {
	int n;
	cin >> n;
	int mark = fin(n);
	cout << mark << endl;
	system("pause");
}
