#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void input_array(float[], size_t);//Ввод массива
void fillrand(float[], size_t);//заполнение массива рандомными значениями
void bubble_sort(float[], size_t);//пузырьковая сортировка
void print(float[], size_t); //вывод массива
void input_array_char(char[], size_t);//ввод массива либо заполнения его рандомами
void count_sort(char[], size_t);//сортировка подсчетом
void merge_sort(float[], float[], size_t, size_t);//сортировка слиянием
void input_array(float[], float[], size_t); //доп перегрузка для сортировки слиянием
void merge(float[], float[], size_t, size_t, size_t);//arr, aux, low, mid, high

int main() {
	srand(time(NULL));
	int n;
	cout << "Введите номер сортировки" << endl;
	cin >> n;
	switch (n)
	{
	case 1: {
		size_t l;
		float arr[1000]{};
		cout << "Вы выбрали сортировку пузырьком" << endl;
		cout << "Введите длину массива" << endl;
		cin >> l;
		input_array(arr, l);
		bubble_sort(arr, l);
		cout << '\n' << "Сортированный массив: ";
		print(arr, l);
	}
	case 2: {
		size_t l;
		char arr[1000]{};
		cout << "Вы выбрали сортировку подсчетом" << endl;
		cout << "Введите длину массива" << endl;
		cin >> l;
		//for (int i = 0; i <= 256; i++) { cout << i << ' ' << char(i) << '\n'; }
		//97-122
		input_array_char(arr, l);
		count_sort(arr, l);
		cout << endl;
		for (int i = 0; i < l; i++) {
			cout << arr[i] << ' ';
		}
	}
	case 3: {
		size_t l;
		float arr[1000]{}, aux[1000]{}; // arr - основной, aux - вспомогательный
		cout << "Вы выбрали сортировку слиянием" << endl;
		cout << "Введите длину массива" << endl;
		cin >> l;
		input_array(arr, aux, l);
		merge_sort(arr, aux, 0, l - 1);
		cout << '\n' << "Сортированный массив: ";
		print(arr, l);
	}
	default:
		break;
	}


	return 0;
}


void merge(float arr[], float aux[], size_t low, size_t mid, size_t high) {
	int k = low, i = low, j = mid + 1;

	while (i <= mid && j <= high) { //идем по 2 рядам
		if (arr[i] <= arr[j]) {
			aux[k] = arr[i];
			k++;
			i++;
		}
		else {
			aux[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) { //копируем что осталось
		aux[k++] = arr[i++];
	}

	//массив aux заполнен сортировано, теперь надо перенести это в arr
	for (int i = low; i <= high; i++) {
		arr[i] = aux[i];
	}
}

void merge_sort(float arr[], float aux[], size_t low, size_t high) {
	if (high <= low) { //поделили - время властвовать
		return;
	}

	size_t mid = (low + (high - low) / 2);

	merge_sort(arr, aux, low, mid);
	merge_sort(arr, aux, mid + 1, high);
	merge(arr, aux, low, mid, high);
}


void count_sort(char arr[], size_t l) {
	int c[26] = { 0 };//индексы 0-24
	for (int i = 0; i < l; i++) {
		c[int(arr[i]) - 97]++;
	}

	int k = 0;
	for (int i = 0; i < 26; i++) {
		while (c[i] != 0) {
			arr[k] = char(i + 97);
			++k;
			--c[i];
		}
	}

}

void input_array_char(char arr[], size_t l) {
	int isrand;
	cout << "Заполнить массив случайными символами(1-да, 2-нет)?" << endl;
	cin >> isrand;
	switch (isrand)
	{
	case 1:
		for (int i = 0; i < l; ++i) {
			arr[i] = char(97 + rand() % 26);
			cout << arr[i] << ' ';
		}
		break;
	case 2: {
		char m;
		for (int i = 0; i < l; i++) {
			cin >> m;
			arr[i] = m;
		}
		break;
	}
	default:
		cout << "Вы ввели неправильный номер" << endl;
		break;
	}
}

void input_array(float arr[], size_t l) {
	int isrand;
	cout << "Заполнить массив случайными значениями(1-да, 2-нет)?" << endl;
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
		cout << "Вы ввели неправильный номер" << endl;
		break;
	}
}

void input_array(float arr[], float aux[], size_t l) {
	int isrand;
	cout << "Заполнить массив случайными значениями(1-да, 2-нет)?" << endl;
	cin >> isrand;
	switch (isrand)
	{
	case 1:
		fillrand(arr, l);
		break;
	case 2: {
		float m;
		for (int i = 0; i != l; i++) {
			cin >> m;
			arr[i] = m;
		}
		break;
	}
	default:
		cout << "Вы ввели неправильный номер" << endl;
		break;
	}
	for (int i = 0; i != l; ++i) {
		aux[i] = arr[i];
	}
}

void fillrand(float arr[], size_t l) {
	cout << "Получился массив:" << endl;
	for (int i = 0; i < l; ++i) {
		arr[i] = rand() % 1000;
		cout << arr[i] << ' ';
	}
}

void bubble_sort(float arr[], size_t l) {
	for (int i = 0; i < l - 1; ++i) {
		for (int j = 0; j < l - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); }
		}
	}
}

void print(float arr[], size_t l) {
	for (int i = 0; i < l; ++i) {
		cout << arr[i] << ' ';
	}
}