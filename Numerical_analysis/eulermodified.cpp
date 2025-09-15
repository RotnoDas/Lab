#include<bits/stdc++.h>
#define f(x, y) ((y - x) / (y + x))
using namespace std;
int main() {
    double x0, y0, interval, xn, h, y_prediction;
    cout << "Enter initial value of x and y: ";
    cin >> x0 >> y0;
    cout << "Enter interval: ";
    cin >> interval;
    cout << "Enter final value of x: ";
    cin >> xn;
    cout << fixed << setprecision(6);
    double x = x0;
    double y = y0;
    h = (xn - x0) / interval;
    while(x < xn) {
        y_prediction = y + h * f(x, y);
        y = y + (h / 2) * (f(x, y) + f(x + h, y_prediction));
        x = x + h;
    }
    cout << "Approximate solution at x = " << xn << " is y = " << y << endl;
    return 0;
}