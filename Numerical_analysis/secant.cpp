#include<bits/stdc++.h>
#define f(x) x * x * x - 3 * x - 5
using namespace std;
int main() {
    double a, b, neg, pos;
    bool flag = false;
    while(true) {
        cout << "Enter the value of a and b: ";
        cin >> a >> b;
        if(f(a) < 0 && f(b) > 0) {
            neg = a;
            pos = b;
            flag = true;
        }
        else if(f(a) > 0 && f(b) < 0) {
            neg = b;
            pos = a;
            flag = true;
        }
        if(flag == true) {
            break;
        }
        cout << "No root between these values. Enter again." << endl;
    }
    double x0, x1, f0, f1, tolerance, error, x2;
    x0 = neg;
    x1 = pos;
    f0 = f(x0);
    f1 = f(x1);
    cout << "Enter tolerance: ";
    cin >> tolerance;
    do {
        x2 = x1 - ((x1 - x0) / (f1 - f0)) * f1;
        error = fabs(fabs(x2) - fabs(x1));
        x0 = x1;
        x1 = x2;
        f0 = f1;
        f1 = f(x2);
    } while(error > tolerance);
    cout << "Root is: " << x2 << endl;
    return 0;
}