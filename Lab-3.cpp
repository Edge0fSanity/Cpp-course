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

// Проверка на дурака
int intput(int type) {
	int i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}

string intput(string type){
	string i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}

float intput(float type) {
	float i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}
//Конец проверки на дурака

int main() {
	while (true) {

		int n;
		cout << "Номер задания(От 1 до 4) ?" << endl;
		n = intput(1);
		switch (n) {
		case 1:
			float a, b, c, d;
			cout << "Введите 4 действительных числа" << endl;
			a = intput(float(1.1));
			b = intput(float(1.1));
			c = intput(float(1.1));
			d = intput(float(1.1));

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
			float s = 0, y;
			cout << "Введите y (не 0)" << endl;
			y = intput(1);
			if (y == 0) {
				cout << "Ноль вводить нельзя" << endl;
				return 0;
			}
			for (int i = 1; i <= 7; i++) {
				s += i / pow(y, i);
			}
			cout << "Результат: " << s << endl;
		}
		case 4: {
			int n, count = 1;
			cout << "Number: ";
			n = intput(1);
			while (n / 10 != 0) {
				count++;
				n /= 10;
			}
			cout << count << " digits" << endl;
			break;
		}
		default:
			cout << "Введен неверный номер, пожалуйста подумайте";
			cin.clear();
			cin.sync();

		}
	}
	return 0;
}