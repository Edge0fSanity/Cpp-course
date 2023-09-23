#include<iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    while (true) {
        int n;
        cout << "Номер задания ?" << endl;
        cin >> n;
        switch (n)
        {
        case 1: {
            cout << "Введите 2 числа" << endl;
            float a;
            float b;
            cin >> a >> b;
            cout << "Сумма " << a + b << endl;
            cout << "Разность " << a - b << endl;
            cout << "Произведение " << a * b << endl;
            cout << "Частное " << a / b << endl;
            cout << "Ср. арифметическое " << (a + b) / 2 << endl;
            break; }
        case 2: {
            int bread = 0;
            int colbasa = 0;
            int cheese = 0;
            int kefir = 0;
            float price_bread = 10.10;
            float price_colbasa = 20.20;
            float price_cheese = 30.30;
            float price_kefir = 40.40;
            cout << "Брат, все есть, смотри, нэдорога.\n Хлэб " << price_bread << " рублэй\n" <<
                " Колбасы " << price_colbasa << " рублэй\n" <<
                " Сыра " << price_cheese << " рублэй\n" <<
                " Кефира " << price_kefir << " рублэй\n";
            cout << "Хлеб сколько нада ?\n";
            cin >> bread;
            cout << "Колбасы сколько нада ?\n";
            cin >> colbasa;
            cout << "Сыра сколько нада ?\n";
            cin >> cheese;
            cout << "Кефира сколько нада ?\n";
            cin >> kefir;
            cout << bread * price_bread + colbasa * price_colbasa + cheese * price_cheese + kefir * price_kefir
                << "\nСтолька денег с тебя, брат";
            break; }

        case 3: {
            float x;
            cout << "Введите сторону куба.\n";
            cin >> x;
            cout << "Площадь поверхности равна " << x * x * 6 << endl;
            cout << "Обьем равен " << x * x * x << endl;
            break; }
        case 4: {
            int a, b, ans;
            cout << "Введите 2 числа" << endl;
            cin >> a >> b;
            cout << "И каково же их произведение ?" << endl;
            cin >> ans;
            if (ans == a * b) {
                cout << "Верно, молодец" << endl;
            }
            else {
                cout << "Неправильно, правильный ответ - " << a * b;
            }
            break;
        }
        case 5: {
            int x, g = 16;
            while (g != 0) {
                cout << "Сколько груш загрузить в фуру ?" << endl;
                cin >> x;
                g -= x;
                if (g < 0) {
                    g = 0;
                    cout << "вы допустили потерю дорогостоящего оборудования, ИДИОТ !" << endl;
                }
                else if (g == 0) {
                    cout << "Все ящики загружены, хорошая работа";
                }

            }

            break;
        }
        case 6: {
            srand(time(NULL));
            int i, x = 1, m;
            int a[50]{};

            for (i = 0; i <= 49; i++) {
                x = 1;
                while (x != 0) {
                    m = 1 + rand() % 99;
                    if (m % 2 != 0) {
                        a[i] = m;
                        x = 0;
                    }
                }
            }
            for (int n : a) {
                cout << n << endl;
            }
            break;
        }
        case 7: {
            int i;
            char a[][28] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "с15", "16", "17", "18", "19", "20", "с21", "с22", "23", "с24", "с25", "с26", "с27", "с28" };
            cout << "Day ?" << endl;
            cin >> i;
            cout << a[i - 1];
            break;
        }
        case 8: {
            srand(time(NULL));
            int i = 10, r = 0, a, b, ans;
            while (i != 0) {
                a = 1 + rand() % 10;
                b = 1 + rand() % 10;
                cout << a << "*" << b << "= ?";
                cin >> ans;
                if (ans == a * b) {
                    r++;
                }
                i--;
            }
            if (r == 10) {
                cout << "Отлично";
            }
            else if (r == 9 or r == 8) {
                cout << "Хорошо";
            }
            else if (r == 7 or r == 6) {
                cout << "Удовлетворительно";
            }
            else if (r < 6) {
                cout << "Плохо";
            }

        }



        }

    }
    return 0;
}
