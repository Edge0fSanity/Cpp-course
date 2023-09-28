#include <iostream>
#include <math.h>

using namespace std;
int main() {
	int n;
	cout << "Номер задания ?" << endl;
	cin >> n;
	switch (n) {
	case 1:
		float a, b, c, d;
		cout << "Введите 4 действительных числа" << endl;
		cin >> a >> b >> c >> d;
		if ((a <= b) && (b <= c) && (c <= d)) {
			a = d;
			c = d;
			b = d;
		}
		else if (!((a > b) && (b > c) && (c > d))) {
			a *= a;
			b *= b;
			c *= c;
			d *= d;
		}
		cout << "Результат: ";
		cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << endl;
		break;
	case 2:
		for (int a = 1; a < 500; a++) {
			for (int b = 1; b < 500; b++) {
				for (int c = 1; c < 500; c++) {
					if (a * a + b * b == c * c) {
						cout << a << ' ' << b << ' ' << c << endl;
					}
				}
			}
		}
		break;
	case 3: {
		float s=0, y;
		cout << "Введите y (не 0)" << endl;
		cin >> y;
		if (y == 0) {
			cout << "Я СКАЗАЛ НЕ ВВОДИТЬ НОЛЬ !!?!?!?" << endl;
			return 0;
		}
		for (int i = 1; i <= 7; i++) {
			s += i / pow(y, i);
		}
		cout << "Результат: " << s << endl;
	}
	case 4: {
		int n, count=1;
		cout << "Number: ";
		cin >> n;
		while (n / 10 != 0) {
			count++;
			n /= 10;
		}
		cout << count << " digits" << endl;
	}
		
	}

	return 0;
}