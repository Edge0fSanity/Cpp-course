#include <iostream>
#include <math.h>
#include <string>
#include <vector>


using namespace std;

class Calculator {

public:
	float add(float x, float y) {
		return x + y;
	}

	float sub(float x, float y) {
		return x - y;
	}

	float multy(float x, float y) {
		return x * y;
	}

	float divide(float x, float y) {
		if (y != 0) { return x / y; }
		cout << "Division by zero" << endl;
		
	}

	float sin(float x) {
		return sin(x);
	}

	float cos(float x) {
		return cos(x);
	}

	float logten(float x) {
		return log10(x);
	}

	float logn(float x, float n) {
		return log(x) / log(n);
	}
	
	string conc(string x, string y) {
		return x + y;
	}

	vector<float> addarray(vector<float> x, vector<float> y) {
		return x + y;
	}
};


int main() {
	string op;

	cout << "Добро пожаловать в инженерный калькулятор" << endl;
	cout << "Выберите действие (+, -, *, /, sin, cos, log10, logn, conc, arr):";
	cin >> op;
	switch op{
	case "+": {
		float x, y;
		cout << "Введите по-очереди слагаемые" << endl;
		cin >> x;
		cin >> y;
		cout << "Сумма равна:" << Calculator.add(x, y) << endl;
		break;
	}
	case "-": {
		float x, y;
		cout << "Введите по-очереди уменьшаемое и вычитаемое" << endl;
		cin >> x;
		cin >> y;
		cout << "Разность равна: " << Calculator.sub(x, y) << endl;
		break;
	}
	case "*": {
		float x, y;
		cout << "Введите по-очереди множители" << endl;
		cin >> x;
		cin >> y;
		cout << "Произведение равно: " << Calculator.multy(x, y) << endl;
		break;
	}
	case "+": {
		float x, y;
		cout << "Введите по-очереди делимое и делитель" << endl;
		cin >> x;
		cin >> y;
		cout << "Частное равно: " << Calculator.divide(x, y) << endl;
		break;
	}
	case "sin":{
		float x;
		cout << "Введите х: ";
		cin >> x;
		cout << "sin(" << x << ") = " << Calculator.sin(x) << endl;
		break;
	}
	case "cos": {
		float x;
		cout << "Введите х: ";
		cin >> x;
		cout << "cos(" << x << ") = " << Calculator.cos(x) << endl;
		break;
	}
	case "log10": {
		float x;
		cout << "Введите х: ";
		cin >> x;
		cout << "log10 " << x << " = " << Calculator.logten(x) << endl;
		break;
	}
	case "logn": {
		float x, y;
		cout << "Введите сначала аргумент, а потом основание" << endl;
		cin >> x;
		cin >> y;
		cout << "Ответ: " << Calculator.logn(x, y) << endl;
		break;
	}

	case "conc": {
		string x, y;
		cout << "Введите по очереди строки, которые необходимо сложить" << endl;
		cin >> x;
		cin >> y;
		cout << "Результат:" << Calculator.conc(x, y) << endl;
		break;
	}

	case "arr": {
		vector<float> x, y, z;
		float a, b;
		cout << "Введите первый массив чисел через пробел" << endl;
		while (cin >> a) {
			x.push_back(a);
		}
		cout << "Введите второй массив чисел через пробел" << endl;
		while (cin >> b) {
			y.push_back(b);
		}
		cout << "Результат сложения: ";
		for (float i : Calculator.arr(x, y)) {
			cout << i << " "
		}
	}
	}


}