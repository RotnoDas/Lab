#include<bits/stdc++.h>
#define f(x) x * x * x - 2 * x - 5
using namespace std;
int main() {
    double a, b, neg, pos;
    bool flag = false;
    while(true) {
        cout << "Enter the value of a and b: ";
        cin >> a >> b;
        if(f(a) < 0 && f(b) > 0) {
            neg = f(a);
            pos = f(b);
            flag = true;
        }
        else {
            neg = f(b);
            pos = f(a);
            flag = true;
        }
        if(flag == true) {
            break;
        }
    }
    /*cout << "Enter error range: ";
    double t, m, error;
    cin >> t;
    do {
        m = (a + b) / 2;
        double f3 = f(m);
        if (f1 * f3 < 0) {
            b = m;
        }
        else {
            a = m;
        }
        error = fabs(b - a);
    }
    while(error < t);
    cout << "Root is: " << m << endl;
    return 0;*/
}