#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
 
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    const double eps = 1e-4;   // заданная точность
    int n = 1;                 // номер текущего члена ряда
    double a = 1.0 / ((3 * n - 2) * (3 * n + 1));   // a1 = 1/4
    double s = 0;              // сумма ряда
 
    // цикл с предусловием: пока очередной член не меньше eps
    while (a >= eps) {
        s += a;                              // добавляем текущий член
        a = a * (3 * n - 2) / (3 * n + 4);   // рекуррентная формула a(n+1)
        n++;                                 // переходим к следующему номеру
    }
 
    cout << setprecision(10);
    cout << "Точность eps = " << eps << endl;
    cout << "Сложено членов ряда: " << n - 1 << endl;
    cout << "Первый член, меньший eps: a" << n << " = " << a << endl;
    cout << "Сумма ряда S = " << s << endl;
    cout << "Точное значение 1/3 = " << 1.0 / 3 << endl;
    cout << "Разность 1/3 - S = " << 1.0 / 3 - s << endl;
    return 0;
}