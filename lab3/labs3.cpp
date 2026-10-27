#include <iostream>
#include <iomanip>
#include <cmath>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
 
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    const double A = 0.1, B = 1.0;   // границы изменения x
    const int K = 10;                // число шагов по x
    const int N = 10;                // заданное n для суммы SN
    const double EPS = 1e-4;         // заданная точность для суммы SE
    const double H = (B - A) / K;    // шаг изменения x
 
    cout << "          Вычисление функции" << endl;
    cout << fixed << setprecision(6);
 
    for (int i = 0; i <= K; i++) {   // внешний цикл: изменение x
        double x = A + i * H;
        double x2 = x * x;
 
        // а) арифметический цикл: сумма для заданного n
        double a = 1.0;              // a0 = 1
        double sn = 1.0;             // сумма начинается с a0
        for (int j = 0; j < N; j++) {
            a = -a * x2 / ((2 * j + 1) * (2 * j + 2));   // a(j+1)
            sn += a;
        }
 
        // б) итерационный цикл: сумма для заданной точности
        a = 1.0;                     // заново a0 = 1
        double se = 0;               // сумма пока пуста
        int n = 0;
        while (fabs(a) >= EPS) {
            se += a;
            a = -a * x2 / ((2 * n + 1) * (2 * n + 2));   // a(n+1)
            n++;
        }
 
        double y = cos(x);           // точное значение функции
        cout << "X=" << x << "  SN=" << sn << "  SE=" << se
             << "  Y=" << y << endl;
    }
    return 0;
}