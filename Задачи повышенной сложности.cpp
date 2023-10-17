#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU.utf8");
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
		int li, mj=0;
		float n, mc=-9999, ml=-9999;
		float arr[100][100] = { 0 };
		cout << "Вводите эл-ты массива, 0 - конец строки" << endl;
		cin >> n;
		for (int i=0; n != 0; i++) {
			for (int j=0; n != 0; j++) {
				arr[i][j] = n;
				cin >> n;
				li = i;
				if (j > mj) { mj = j; }
			}
			cin >> n;
		}
		cout << "Вы ввели массив:" << endl;
		for (int i = 0; i != li+1; i++) {// Вывод всего массива на экран
			for (int j = 0; arr[i][j] != 0; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << "\n";
		}
		float c = 0, l = 0;
		//поиск максимальных
		for (int i = 0; i <= li; i++) {
			for (int j = 0; j <= mj; j++) {
				l += arr[i][j];
			}
			if (l > ml) { ml = l;}
			l = 0;
		}
		cout << "Максимальная строка: " << ml << endl;
		for (int j = 0; j <= mj; j++) {
			for (int i = 0; i <= li; i++) {
				c += arr[i][j];
			}
			if (c > mc) { mc = c; }
			c = 0;
		}
		cout << "Максимальный столбец: " << mc << endl;
		
		break;
	}
	}
	
	return 0;
}