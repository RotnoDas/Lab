#include<bits/stdc++.h>
using namespace std;
int main() {
    double x[20], y[20], search, p = 1;
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;
    cout << "Enter the values of x and y: ";
    for(int i = 0; i < terms; i++) {
        cin >> x[i] >> y[i];
    }
    cout << "Enter searching point: ";
    cin >> search;
    double h = x[1] - x[0];
    double a = x[terms - 1];
    double result = y[terms - 1];
    double u = (search - a) / h;
    for(int i = 1; i < terms; i++) {
        for(int j = (terms-1); j >= i; j--) {
            y[j] = y[j] - y[j-1];
        }
        p = p * (u + i - 1) / i;
        result = result + p * y[terms-1];
    }
    cout << "For = " << search << " result is: " << result << endl;
    return 0;
}