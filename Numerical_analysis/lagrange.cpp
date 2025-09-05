#include<bits/stdc++.h>
using namespace std;
int main() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;
    double x[terms], y[terms], search;
    cout << "Enter the value of x and y: ";
    for(int i = 0; i < terms; i++) {
        cin >> x[i] >> y[i];
    }
    double result = 0;
    cout << "Enter searching point: ";
    cin >> search;
    for(int i = 0; i < terms; i++) {
        double value = y[i];
        for(int j = 0; j < terms; j++) {
            if(i != j) {
                value = value * (search - x[j]) / (x[i] - x[j]);
            }
        }
        result = result + value;
    }
    cout << "For = " << search << " result is: " << result << endl;
    return 0;
}