#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;
void fill_rand(int[], size_t);
void fill(int[], size_t);
int sum_ev(int);
int cin_err();
/*
void sum_sort(int[], size_t);
void Qsort(int[], size_t, size_t);
*/

int main() {
	srand(time(NULL));
	int n, isrand;
	int *arr = new int[0];
	size_t l=0;
	while (true) {
		cout << "Введите номер операции" << endl;
		cin >> n;  
		switch (n) {
		case 1: {		//Заполнение массива
			cout << "Введите длину массива" << endl;
			do {
				cin >> l;
			} while (cin_err());
			
			int *a = new int[l];
			arr = a;
			delete[] a;
			cout << "Заполнить массив случайными числами ?(1-Да, 2-Нет)" << endl;
			do {
				cin >> isrand;
			} while (not(isrand == 1 || isrand == 2) && cin_err());

			if (isrand == 1) { fill_rand(arr, l); }
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
				cout << endl;
			}
			break;
		}
		case 3: {
			if (l == 0) {
				cout << "Вы еще не ввели массив" << endl;
				break;
			}
			else {
				sum_sort(arr, l);
				cout << "Массив отсортирован по сумме цифр на четных местах" << endl;
			}
			break;
		}
		/*
		case 4: {
			if (l == 0) {
				cout << "Вы еще не ввели массив" << endl;
				break;
			}
			else {
				Qsort(arr, 0, l);
				cout << "Массив отсортирован по возрастанию последней цифры" << endl;
			}
		}
		*/
		case 5:
			return 0;

			  
		default:
			cin_err();
			break;
			
		}
		cin_err();
	}
	delete [] arr;        
	return 0;
}

/*
int compare(int a, int b) {
	if (a%10 > b%10){ return a; }
	if (a%10 < b%10) { return b; }
	if (a < b) { return b; }
	else { return a; }

}
void Qsort(int arr[], size_t start, size_t end) {
	int l = start, r = end-1;
	int piv = arr[(l+r)/2];
	while (l < r) {
		while (compare(arr[l], piv) == piv && arr[l] != piv)
			l++;
		while (compare(arr[r], piv) == arr[r] && arr[r] != piv)
			r--;
		if (l <= r) {
			swap(arr[l], arr[r]);
		}
	}
	if (start < r)
		Qsort(arr, start, r);
	if (end > 1)
		Qsort(arr, 1, end);
}
*/
void sum_sort(int arr[], size_t l) {
	for (size_t i = 0; i < l; ++i) {
		for (size_t j = 0; j < l - i-1; ++j) {
			if (sum_ev(arr[j]) > sum_ev(arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int cin_err() {
	if (cin.fail())
	{
		cout << "Вы ввели неверное значение" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		return 1;
	}
	return 0;
}

void fill_rand(int arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		arr[i] = 100 + rand() % 1000;
	}
}

void fill(int arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		cin >> arr[i];
	}
}

int sum_ev(int n) {
	int s=0;
	for (int i = 2; i < 11; ++++i) {
		s += n % int(pow(10, i)) / int(pow(10, i - 1));
	}
	return s;
}