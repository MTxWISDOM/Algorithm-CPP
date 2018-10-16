#include"stdafx.h"
#include<iostream>

using namespace std;

int main() {
	int make, lose;
	while (cin >> make >> lose) {
		if (make >= 4 * lose) {
			cout << "Deficit" << endl;
			continue;
		}
		if (make < 4 * lose && 4 * make < lose) {
			if (10 * make - 2 * lose < 0) {
				cout << "Deficit" << endl;
			}
			else {
				cout << 10 * make - 2 * lose << endl;
			}
			continue;
		}
		if (make < 4 * lose && 3 * make < 2 * lose) {
			if (8 * make - 4 * lose < 0) {
				cout << "Deficit" << endl;
			}
			else {
				cout << 8 * make - 4 * lose << endl;
			}
			continue;
		}
		if (make < 4 * lose && 2 * make < 3 * lose) {
			if (6 * make - 6 * lose < 0) {
				cout << "Deficit" << endl;
			}
			else {
				cout << 6 * make - 6 * lose << endl;
			}
			continue;
		}
		if (make < 4 * lose && 2 * make >= 3 * lose) {
			if (3 * make - 9 * lose < 0) {
				cout << "Deficit" << endl;
			}
			else {
				cout << 3 * make - 9 * lose << endl;
			}
		}
	}
	return 0;
}