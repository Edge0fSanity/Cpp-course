#include <iostream>
#include <string> 
#include <time.h>
#include <math.h>
#include <vector>
#define PI 3.14159
#define el m[i][j]

using namespace std;

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

string intput(string type) {
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
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}
//Конец проверки на дурака

// Обьем шара
float volume(float r) {
	return 4 / 3 * PI * pow(r, 3);
}

//Функция реверса для 7 задания
void reverse(int nums[], size_t n) {
	cout << "Развернутый массив" << endl;
	for (n;n > 0; n--){
		cout << nums[n-1] << ' ';
	}
}

int main() {
	srand(time(NULL));
	int i;
	cout << "Введите номер задания" << endl;
	i = intput(1);
	switch (i) {
	case 1: { // Первое задание
		cout << "Введите 3 числа" << endl;
		float x1 = 0, x2, x3;
		x1 = intput(x1);
		x2 = intput(x1);
		x3 = intput(x1);
		cout << "Ср. значение: " << (x1 + x2 + x3) / 3 << endl;
		break;
	}
	case 2: { // Второе задание
		cout << "Пока вы не введете 0, на экран будут выводиться кубы" << endl;
		float n=0;
		n = intput(n);
		while (n != 0) {
			cout << pow(n, 3) << endl;
			n = intput(n);
		}
		break;
	}
	case 3: {
		float r1=0, r2, r3;
		cout << "Введите радиусы 3 шаров" << endl;
		r1 = intput(r1);
		r2 = intput(r1);
		r3 = intput(r1);
		cout << "Обьем 1:" << volume(r1) << endl;
		cout << "Обьем 2:" << volume(r2) << endl;
		cout << "Обьем 3:" << volume(r3) << endl;
	}
	case 4: {
		int n = 0, m[12]{};
		for (int i = 1; i <= 12; i++) {
			if (i == 2) {
				m[i-1] = 28;
			}
			else {
				m[i-1] = 30 + (i + int(i / 8)) % 2;// формула вычисления месяца
			}
		}
		cout << "Введите номер месяца" << endl;
		n = intput(n);
		cout << m[n-1] << " дней в этом месяце" << endl;
		/* вывод массива
		for (i = 0; i < 12; i++) {
			cout << i+1 << " - " << m[i] << endl;
		}*/
		break;
	}
	case 5: {
		int m[5][4], min = 999, max = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				m[i][j] = 1 + rand() % 100; //Заполнение матрицы
			}
			}
		}
		cout << "Был сгенерирован массив 5х4 случайных чисел" << '\n' << endl;
		for (int i = 0; i < 5; i++) {
			min = 999;
			max = 0;
			for (int j = 0; j < 4; j++) {
				if (el < min) {
					min = el;
				}
				else if (el > max){
					max = el;
				}
			}
			cout << i + 1 << " Строка: max = " << max
				<< " min = " << min << endl; //Вывод max и min
		}
		break;
	}
	case 6: {
		srand(time(NULL));
		size_t n;
		cout << "Введите длину массива" << endl;
		n = intput(1);
		vector<int> arr(n);
		for (size_t i = 0; i < n; i++) {
			arr[i] = (rand() % 100);
		}
		cout << "Сгенерирован массив случайных чисел" << endl;
		for (size_t i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		
		for (size_t i = 0; i < n-1; i++) {
			for (size_t j = 0; j < n-1-i; j++) {
				if (arr[j] > arr[j + 1]){
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		cout << "Сортированный список: " << endl;
		for (size_t i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}

		break;
	}
	case 7: {
		srand(time(NULL));
		size_t n;
		cout << "Введите длину массива" << endl;
		n = intput(1);
		int arr[256];
		for (size_t i = 0; i < n; i++) {
			arr[i] = i+1;
		}
		arr[n] = 0;
		cout << "Сгенерирован массив" << endl;
		for (size_t i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		
		reverse(arr, n);
	}





	}
	return 0;
}