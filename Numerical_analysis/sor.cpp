/*
    3x - y + z = -1
    -x + 3y - z = 7
    x - y + 3z = -7
*/
#include<bits/stdc++.h>
#define f1(x, y, z, omega) (1 - omega) * x + (omega / 3) * (-1 + y - z)
#define f2(x, y, z, omega) (1 - omega) * y + (omega / 3) * (7 + x + z)
#define f3(x, y, z, omega) (1 - omega) * z + (omega / 3) * (-7 - x + y)
using namespace std;
int main() {
    double omega;
    cout << "Enter value of omega: ";
    cin >> omega;
    double tolerance;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    double x, y, z, x0 = 0, y0 = 0, z0 = 0, e1, e2, e3, error;
    do {
        x = f1(x0, y0, z0, omega);
        y = f2(x, y0, z0, omega);
        z = f3(x, y, z0, omega);
        e1 = abs(x0 - x);
        e2 = abs(y0 - y);
        e3 = abs(z0 - z);
        error = max({e1, e2, e3});
        x0 = x;
        y0 = y;
        z0 = z;
    }
    while(error > tolerance);
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;
    return 0;
}