/*
    2x - y = 7
    -x + 2y - z = 1
    -y + 2z = 1
*/
#include<bits/stdc++.h>
#define f1(x, y, z) ((7 + y) / 2)
#define f2(x, y, z) ((1 + x + z) / 2)
#define f3(x, y, z) ((1 + y) / 2)
using namespace std;
int main() {
    double x, y, z, x0 = 0, y0 = 0, z0 = 0, e, e1, e2, e3, error;
    cout << "Enter error range: ";
    cin >> e;
    do {
        x = f1(x0, y0, z0);
        y = f2(x, y0, z0);
        z = f3(x, y, z0);
        e1 = abs(x0 - x);
        e2 = abs(y0 - y);
        e3 = abs(z0 - z);
        error = max({e1, e2, e3});
        x0 = x;
        y0 = y;
        z0 = z;
    }
    while(error > e);
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;
    return 0;
}