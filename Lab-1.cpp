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
        case 2:
        int bread = 0;
        int colbasa = 0;
        int cheese = 0;
        int kefir = 0;
        float price_bread = 10.10;
        float price_colbasa = 20.20;
        float price_cheese = 30.30;
        float price_kefir = 40.40;
        cout << "Брат, все есть, смотри, нэдорога. Хлэб " << price_bread << "рублэй";
        cout << "Колбасы" << price_colbasa << "рублэй";
        cout << "Сыра" << price_cheese << "рублэй";
        cout << "Кефира" << price_kefir << "рублэй";
        cout << "Хлеб сколько нада ?";
        cin >> bread;
        cout << "Колбасы сколько нада ?";
        cin >> colbasa;
        cout << "Сыра сколько нада ?";
        cin >> cheese;
        cout << "Кефира сколько нада ?";
        cin >> kefir;
        
    }
    return 0;
}
