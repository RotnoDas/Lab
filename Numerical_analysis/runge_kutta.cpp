#include<bits/stdc++.h>
#define f(x, y) (x + y * y)
using namespace std;
int main() {
    double x0, y0, interval, xn;
    cout << "Enter initial value of x and y: ";
    cin >> x0 >> y0;
    cout << "Enter final value of x: ";
    cin >> xn;
    cout << "Enter interval: ";
    cin >> interval;
    double h = (xn - x0) / interval;
    for(int i = 1; i <= interval; i++) {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * f(x0 + h, y0 + k3);
        double k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y0 = y0 + k;
        x0 = x0 + i * h;
    }
    cout << "Approximate solution at x = " << xn << " is y = " << y0 << endl;
    return 0;
}