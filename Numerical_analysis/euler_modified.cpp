#include<bits/stdc++.h>
#define f(x, y) ((y - x) / (y + x))
using namespace std;
int main() {
    double x0, y0, h, xn, interval, e, error, y_correct;
    cout << "Enter initial value of x and y: ";
    cin >> x0 >> y0;
    cout << "Enter interval: ";
    cin >> interval;
    cout << "Enter final value of x: ";
    cin >> xn;
    cout << "Enter error range: ";
    cin >> e;
    cout << fixed << setprecision(4);
    double x = x0;
    double y = y0;
    h = (xn - x0) / interval;
    double y_prediction;
    while(x < xn) {
        y_prediction = y + h * f(x, y);
        int itr = 0;
        do {
            y_correct = y + (h / 2) * (f(x, y) + f(x + h, y_prediction));
            error = fabs(y_correct - y_prediction);
            y_prediction = y_correct;
            itr++;
        }
        while(error > e && itr <= 100);
        y = y_correct;
        x = x + h;
    }
    cout << "Approximate solution at x = " << xn << " is y = " << y << endl;
    return 0;
}