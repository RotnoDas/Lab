#include<bits/stdc++.h>
#define f(x) x * x * x - 2 * x - 5
using namespace std;
int main() {
    double a, b, neg, pos, m;
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
    double tolerance, error;
    cout << "Enter Tolerance: ";
    cin >> tolerance;
    double f1 = f(neg);
    double f2 = f(pos);
    do {
        m = (neg * f2 - pos * f1) / (f2 - f1);
        double function_value = f(m);
        if(function_value < 0) {
            neg = m;
            f1 = function_value;
        }
        else if(function_value > 0) {
            pos = m;
            f2 = function_value;
        }
        error = fabs(abs(function_value) - 0);
    } while(error > tolerance);
    cout << "Root is: " << m << endl;
    return 0;
}