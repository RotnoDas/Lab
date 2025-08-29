#include<bits/stdc++.h>
#define f(x) x * x * x - 2 * x - 5
using namespace std;
int main() {
    double a, b, neg, pos, m, temp;
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
    }
    double tolerance, error;
    cout << "Enter Tolerance: ";
    cin >> tolerance;
    do {
        m = (neg + pos) / 2;
        double function_value = f(m);
        if(function_value < 0) {
            neg = m;
        }
        else if(function_value > 0) {
            pos = m;
        }
        error = fabs(abs(pos) - abs(neg));
    } while(error > tolerance);
    cout << "Root is: " << m << endl;
    return 0;
}