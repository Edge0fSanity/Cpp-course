#include <iostream>
#include <ctime>

using namespace std;

void input_array(float[], size_t);//ввод массива
void fillrand(float[], size_t);//заполнение массива рандомными числами
void bubble_sort(float[], size_t);//сортировка пузырьком
void print(float[], size_t); //вывод списка на экран

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Введите номер задания" << endl;
	cin >> n;
	switch (n)
	{
	case 1: {
		size_t l;
		float arr[1000]{};
		cout << "Вы выбрали отсортировать массив пузырьком" << endl;
		cout << "Введите длинну массива" << endl;
		cin >> l;
		input_array(arr, l);
		bubble_sort(arr, l);
		cout << '\n' << "Сортированный массив : ";
		print(arr, l);
	}
	default:
		break;
	}


	return 0;
}


void input_array(float arr[], size_t l) {
	int isrand;
	cout << "Задать массив случано ?(1 - да, 2 - нет)" << endl;
	cin >> isrand;
	switch (isrand)
	{
	case 1:
		fillrand(arr, l);
		break;
	case 2: {
		float m;
		for (int i = 0; arr[i] != l; i++) {
			cin >> m;
			arr[i] = m;
		}
		break;
	}
	default:
		cout << "Вы ввели не то число" << endl;
		break;
	}
}

void fillrand(float arr[], size_t l) {
	for (int i = 0 ; arr[i] != l; i++) {
		arr[i] = rand() % 1001;
	}
}

void bubble_sort(float arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < l - i; ++j) {
			if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); }
		}
	}
}

void print(float arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		cout << arr[i] << ' ';
	}
}