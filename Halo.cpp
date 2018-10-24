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
			cout << "x�������У��±�Ϊ�� " << mark << endl;
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
			cout << "С��x�����Ԫ���±��ǣ� " << less << endl;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] < x) {
			bigger = i + 1;
			cout << "����x����СԪ���±��ǣ� " << bigger << endl;
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
		cout << "����õ����飺" << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		cin >> x;
		if (x > a[n - 1]){
			cout << "�����ڱ�x�����" << endl;
			cout << "��xС�����Ԫ�ص��±��ǣ�" << n - 1 << endl;
			cout << endl;
			continue;
		}
		else if (x < a[0]){
			cout << "�����ڱ�xС����" << endl;
			cout << "��x�����СԪ�ص��±��ǣ�0" << endl;
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