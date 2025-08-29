#include <bits/stdc++.h>
#define f(x) x *x *x - 2 * x - 5
#define df(x) 3 * x * x - 2
using namespace std;
int main() {
    double a, b, neg, pos;
    bool flag = false;
    while (true) {
        cout << "Enter the value of a and b: ";
        cin >> a >> b;
        if (f(a) < 0 && f(b) > 0) {
            neg = a;
            pos = b;
            flag = true;
        }
        else if (f(a) > 0 && f(b) < 0) {
            neg = b;
            pos = a;
            flag = true;
        }
        if (flag == true) {
            break;
        }
        cout << "No root between these values. Enter again." << endl;
    }
    double difference1 = fabs(fabs(f(a)) - 0);
    double difference2 = fabs(fabs(f(b)) - 0);
    double x0;
    if (difference1 < difference2) {
        x0 = a;
    }
    else {
        x0 = b;
    }
    double tolerance, f, df, x, error;
    cout << "Enter the tolerance: ";
    cin >> tolerance;
    f = f(x0);
    df = df(x0);
    do {
        x = x0 - (f / df);
        x0 = x;
        f = f(x);
        df = df(x);
        error = fabs(f);
    } while(error > tolerance);
    cout << "Root is: " << x << endl;
    return 0;
}