#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Введите номер задания" << endl;
	cin >> n;
	switch (n) {
	case 1: { // тема циклы номер 1
		int l;
		cout << "Введите высоту пирамиды" << endl;
		cin >> l;
		for (int i = 0; i < l;i++) {
			for (int j = 1; j <= l * 2 - 1; j++) {
				if (j == l || (j >= l - i && j <= l + i)) {
					cout << '^';
				}
				else {
					cout << ' ';
				}}
				cout << '\n';
			} 
		break;
	}
	case 2: {
		float n;
		float arr[100][100];
		cout << "Вводите эл-ты массива, 0 - конец строки" << endl;
		cin >> n;
		for (int i=0; n != 0; i++) {
			for (int j=0; n != 0; j++) {
				arr[i][j] = n;
				cin >> n;
			}
			cin >> n;
		}
		for (int i = 0; arr[i] != 0; i++) {
			for (int j = 0; arr[i][j] != 0; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << "\n";
		}
		break;
	}
	}
	
	return 0;
}