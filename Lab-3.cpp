#include <iostream>
#include <math.h>
#include <string>

using namespace std;

/*
auto input(string type) {
	string inp;
	cin >> inp;
	bool let = 0;
	bool num = 0;
	cout << bool(isgraph(inp[0])) << endl;
	for (int i = 0; i <= inp.size()-1; i++) {
		if (isgraph(inp[i]) != 0 && isdigit(inp[i]) == 0) {
			let = true;
			continue;
		}
		if (isdigit(inp[i]) != 0) {
			num = true;
			continue;
		}
		if (type == "str")) {
			if (let||num) {
				return inp;
			}
			else {
				
			}
		}
	}
}


int main() {
	cout << input("str") << endl;
	
	return 0;
}
*/
int intput(string type) {
	int i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin >> i;
	}
	return i;
}

int main() {
	setlocale(LC_ALL, "ru");
	for (int i = 0; i <= 256; i++) {
		cout << i << ' ' << char(i) << endl;
	}


	int n;
	cout << "Номер задания(От 1 до 4) ?" << endl;
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
			cout << "Вводи нормально !!? !? !? " << endl;
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
		break;
	}
	default:
		cout << "Введен неверный номер, подумайте";

		
	}
	return 0;
}