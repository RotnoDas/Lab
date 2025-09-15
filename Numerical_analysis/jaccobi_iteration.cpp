/*
    27x + 6y - z = 85
    6x + 15y + 2z = 72
    x + y + 54z = 110
*/
#include<bits/stdc++.h>
#define f1(x, y, z) ((85 - 6 * y + z) / 27)
#define f2(x, y, z) ((72 - 6 * x - 2 * z) / 15)
#define f3(x, y, z) ((110 - x - y) / 54)
using namespace std;
int main() {
    double e, x0 = 0, y0 = 0, z0 = 0, x, y, z, e1, e2, e3, error;
    cout << "Enter error range: ";
    cin >> e;
    do {
        x = f1(x0, y0, z0);
        y = f2(x0, y0, z0);
        z = f3(x0, y0, z0);
        e1 = fabs(x0 - x);
        e2 = fabs(y0 - y);
        e3 = fabs(z0 - z);
        x0 = x;
        y0 = y;
        z0 = z;
        error = max({e1, e2, e3});
    }
    while(error > e);
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;
    return 0;
}