#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Номер задания ?" << endl;
    cin >> n;
    switch(n) {
        case 1:
        cout << "Введите 2 числа" << endl;
        float a;
        float b;
        cin >> a >> b;
        cout << "Сумма " << a+b << endl;
        cout << "Разность " << a-b << endl;
        cout << "Произведение " << a*b << endl;
        cout << "Частное " << a/b << endl;
        cout << "Ср. арифметическое " << (a+b)/2 << endl;
        break;
    }
    return 0;
}
