#include"stdafx.h"
#include<iostream>
#include<algorithm>

using namespace std;

int a[101];
int flag = 0;
int re;
int n;
int x;

void f(int x, int s, int e) {
	int left = s;
	int right = e;
	int mark;
	while (left <= right) {
		mark = (left + right) / 2;
		if (a[mark] == x) {
			cout << "x在数组中，下标为： " << mark << endl;
			return;
		}
		if (a[mark] > x) {
			right = mark - 1;
		}
		else if (a[mark] < x) {
			left = mark + 1;
		}
	}
	int less;
	int bigger;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			less = i - 1;
			cout << "小于x的最大元素下标是： " << less << endl;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] < x) {
			bigger = i + 1;
			cout << "大于x的最小元素下标是： " << bigger << endl;
			break;
		}
	}
}

int main() {
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		cout << "排序好的数组：" << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		cin >> x;
		if (x > a[n - 1]){
			cout << "不存在比x大的数" << endl;
			cout << "比x小的最大元素的下标是：" << n - 1 << endl;
			cout << endl;
			continue;
		}
		else if (x < a[0]){
			cout << "不存在比x小的数" << endl;
			cout << "比x大的最小元素的下标是：0" << endl;
			cout << endl;
			continue;
		}
		else {
			f(x, 0, n - 1);
		}
		cout << endl;
	}
	return 0;
}