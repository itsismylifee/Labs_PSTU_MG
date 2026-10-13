#include <iostream>
#include <cmath>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>   
#endif
using namespace std;
void task2() {
    int m, n;

    // 1) m++ - n
    m = 3;
    n = 5;

    cout << "=== 1) m++ - n ===" << endl;
    cout << "До: m = " << m << ", n = " << n << endl;

    int r1 = m++ - n;

    cout << "Результат: r1 = " << r1 << endl;
    cout << "После: m = " << m << ", n = " << n << endl;
    cout << endl;


    // 2) m++ < ++n (результат true)
    m = 3;
    n = 3;

    cout << "=== 2) m++ < ++n ===" << endl;
    cout << "До: m = " << m << ", n = " << n << endl;

    bool r2 = m++ < ++n;

    cout << "Результат: r2 = " << boolalpha << r2 << endl;
    cout << "После: m = " << m << ", n = " << n << endl;
    cout << endl;


    // 3) m++ < ++n (результат false)
    m = 5;
    n = 3;

    cout << "=== 3) m++ < ++n ===" << endl;
    cout << "До: m = " << m << ", n = " << n << endl;

    bool r3 = m++ < ++n;

    cout << "Результат: r3 = " << boolalpha << r3 << endl;
    cout << "После: m = " << m << ", n = " << n << endl;
    cout << endl;


    // 4) n-- < --m (результат false)
    m = 4;
    n = 3;

    cout << "=== 4) n-- < --m ===" << endl;
    cout << "До: m = " << m << ", n = " << n << endl;

    bool r4 = n-- < --m;

    cout << "Результат: r4 = " << boolalpha << r4 << endl;
    cout << "После: m = " << m << ", n = " << n << endl;
    cout << endl;


    // 5) n-- < --m (результат false)
    m = 3;
    n = 3;

    cout << "=== 5) n-- < --m ===" << endl;
    cout << "До: m = " << m << ", n = " << n << endl;

    bool r5 = n-- < --m;

    cout << "Результат: r5 = " << boolalpha << r5 << endl;
    cout << "После: m = " << m << ", n = " << n << endl;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   
#endif
    cout << setprecision(12);

    // ---------- float ----------
    float  fa = 1000;
    float  fb = 0.0001;
    float  fd = fa - fb;                 // a - b
    float  f1 = pow(fa - fb, 3);         // (a-b)^3   <-- здесь у float теряется точность
    float  f2 = pow(fa, 3);              // a^3
    float  f3 = pow(fb, 3);              // b^3
    float  f4 = 3 * fa * pow(fb, 2);     // 3ab^2
    float  f5 = 3 * fb * pow(fa, 2);     // 3a^2b
    float  fnum = f1 - f2;               // числитель  <-- вычитание близких больших чисел
    float  fden = f3 - f4 - f5;          // знаменатель

    // ---------- double ----------
    double da = 1000;
    double db = 0.0001;
    double dd = da - db;
    double d1 = pow(da - db, 3);
    double d2 = pow(da, 3);
    double d3 = pow(db, 3);
    double d4 = 3 * da * pow(db, 2);
    double d5 = 3 * db * pow(da, 2);
    double dnum = d1 - d2;
    double dden = d3 - d4 - d5;

    // Подписи без setw: setw считает байты, и русские буквы сбивают выравнивание
    cout << "Величина            float  |  double\n";
    cout << "b                   " << fb << "  |  " << db << "\n";
    cout << "a-b                 " << fd << "  |  " << dd << "\n";
    cout << "c1=(a-b)^3          " << f1 << "  |  " << d1 << "\n";
    cout << "c2=a^3              " << f2 << "  |  " << d2 << "\n";
    cout << "c3=b^3              " << f3 << "  |  " << d3 << "\n";
    cout << "c4=3ab^2            " << f4 << "  |  " << d4 << "\n";
    cout << "c5=3a^2b            " << f5 << "  |  " << d5 << "\n";
    cout << "Числитель c1-c2     " << fnum << "  |  " << dnum << "\n";
    cout << "Знаменатель         " << fden << "  |  " << dden << "\n";
    cout << "РЕЗУЛЬТАТ           " << fnum / fden << "  |  " << dnum / dden << "\n";
    task2();

    
    return 0;
}