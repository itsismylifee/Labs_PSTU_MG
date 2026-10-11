#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Вычисление через float
void calcFloat() {
    float a = 1000;
    float b = 0.0001;
    float c1 = pow(a - b, 3);
    float c2 = pow(a, 3);
    float c3 = pow(b, 3);
    float c4 = 3 * a * pow(b, 2);
    float c5 = 3 * b * pow(a, 2);

    cout << "float:  " << ((c1 - c2) / (c3 - c4 - c5)) << endl;
}

// Вычисление через double
void calcDouble() {
    double a = 1000;
    double b = 0.0001;
    double c1 = pow(a - b, 3);
    double c2 = pow(a, 3);
    double c3 = pow(b, 3);
    double c4 = 3 * a * pow(b, 2);
    double c5 = 3 * b * pow(a, 2);

    cout << "double: " << ((c1 - c2) / (c3 - c4 - c5)) << endl;
}
void task2() {
    int m, n;

    // 1) m+--n
    m = 3; n = 5;
    int r1 = m+--n;
    cout << r1 << endl;

    // 2) m++<++n
    m = 3; n = 5;
    bool r2 = m++<++n;
    cout << r2 << endl;

    // 3) n--< --m
    m = 3; n = 5;
    bool r3 = n--< --m;
    cout << r3 << endl;
}

int main() {
    cout << setprecision(10);
    

    calcFloat();
    calcDouble();
    task2();

    return 0;
}

