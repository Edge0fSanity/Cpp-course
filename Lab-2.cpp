#include <iostream>
#include <string> 
#include <time.h>
#include <math.h>
#include <iomanip>


using namespace std;



int intput(int type) {
	int i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(255, '\n');
		cin >> i;
	}
	return i;
}

string intput(string type) {
	string i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(255, '\n');
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
		cin.ignore(255, '\n');
		cin >> i;
	}
	return i;
}

double intput(double type) {
	double i;
	cin >> i;
	while (cin.fail() == 1) {
		cout << "Введите снова" << endl;
		cin.clear();
		cin.sync();
		cin.ignore(255, '\n');
		cin >> i;
	}
	return i;
}

int check(string s) {
	s = s + " ";
	int i, count=0, mcount = 1;
	for (i = 0; i <= s.length(); i++) {
		if (isalpha(s[i])) {
			count++;
		}
		else {
			if (count > mcount) {
				mcount = count;
			}
			count = 0;
		}
	}
	return mcount;
}

int def() {
	int res=0;
	string text = {};
	while (true) {
		int p;
		cout << "Выберите пункт" << endl;
		cout << "1.Ввести текст(латиницей)" << endl;
		cout << "2.Проверить текст" << endl;
		cout << "3.Вывод результата" << endl;
		cout << "4.Выход" << endl;
		p = intput(1);
		switch (p) {
		case 1:
			getline(cin, text);
			getline(cin, text);
			break;
		case 2:
			if (text != "") {
				res = check(text);
			}
			else {
				cout << "Для начала введите текст" << endl;
			}
			break;
		case 3:
			if (res > 0) {
				cout << res << endl;;
			}
			else{
				cout << "Выводить нечего" << endl;;
			}
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "Введите верный номер пункта" << endl;
			break;
		}
	}
}

double f(double x, double y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

double dist(double x1, double y1, double x2, double y2) {
	if ((x1 == x2) && (y1 == y2)) {
		return 0;
	}
	else {
		return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}
}






int main() {
	int n;
	while (true) {
		cout << "Номер задания ?" << endl;
		n = intput(1);
		switch (n)
		{
		case 1: {
			float y=0, x;
			cout << "Введите х" << endl;
			x = intput(y);
			y = -2.7 * x * x * x + 0.23 * x * x - 1.4;
			cout << y << endl;
			break;
		}
		case 2: {
			float r1, r2;
			cout << "Введите сопротивления 1 и 2 элементов\n";
			cin >> r1 >> r2;
			cout << "Сопротивление цепи равно: " << r1 + r2 << endl;
			break;
		}
		case 3:
			def();
			break;
		case 4: {
			const double PI = 3.141592653589793;
			float r, h=0;
			cout << "Введите высоту и радиус цилиндра соответственно" << endl;
			r = intput(h);
			h = intput(h);
			if ((h <= 0) || (r <= 0)) {
				cout << "Радиус и высота должны быть натуральными" << endl;
				return 0;
			}
			long double V = PI * r * r * h;
			cout << fixed << setprecision(15) << V << endl;
			break;
		}
		case 5: {
			srand(time(NULL));
			double x, y;
			do {
				x = 1 + rand() % 5;
				y = 1 + rand() % 5;
				cout << x << endl;
			} while (true);
			cout << f(x, y) << endl;
			break;
		}
		case 6: {
			double x1=0, y1, x2, y2;
			cout << "Введите x1, y1, x2, y2" << endl;
			x1 = intput(x1);
			y1 = intput(x1);
			x2 = intput(x1);
			y2 = intput(x1);
			cout << dist(x1, y1, x2, y2) << " - расстояние между точками" << endl;
		}

		default:
			break;
		}
	}
	return 0;
}