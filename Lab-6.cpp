#include <iostream>
#include <time.h>

using namespace std;
void fillrand(int[], size_t);
void fill(int[], size_t);

int main() {
	srand(time(NULL));
	int n, isrand;
	int* arr = {};
	size_t l=0;
	while (true) {
		cout << "Введите номер операции" << endl;
		cin >> n;  
		switch (n) {
		case 1: {		//Заполнение массива
			cout << "Введите длину массива" << endl;
			cin >> l;
			int *arr = new int[l];
			cout << "Заполнить массив случайными числами ?(1-Да, 2-Нет)" << endl;
			do {
				cin >> isrand;
			} while (isrand != 1 || isrand != 2);

			if (isrand == 1) { fillrand(arr, l); }
			else { fill(arr, l); }
			break;
		}
		case 2: {		//Вывод массива
			if (l == 0) {
				cout << "Вы еще не ввели массив" << endl;
				break;
			}
			else {
				for (int i = 0; i < l; ++i) {
					cout << arr[i] << ' ';
				}
			}
		}
		default:
			cout << "Вы явно ввели что-то не так, подумайте и попробуйте снова" << endl;
		}
	}
	delete [] arr;
	return 0;
}

void fillrand(int arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		arr[i] = rand() % 100;
	}
}

void fill(int arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		cin >> arr[i];
	}
}