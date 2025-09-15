#include<bits/stdc++.h>
#define f(x) 1 / (1 + x * x)
using namespace std;
int main() {
    double lowerLimit, upperLimit, interval;
    cout << "Enter Lower Limit: ";
    cin >> lowerLimit;
    cout << "Enter Upper Limit: ";
    cin >> upperLimit;
    cout << "Enter number of intervals: ";
    cin >> interval;
    double h = (upperLimit - lowerLimit) / interval;
    double result = f(lowerLimit) + f(upperLimit);
    for(int i = 1; i < interval; i++) {
        double value = lowerLimit + i * h;
        if(i % 3 == 0) {
            result = result + 2 * f(value);
        }
        else {
            result = result + 3 * f(value);
        }
    }
    result = result * (3 * h / 8);
    cout << "Result is: " << result << endl;
    return 0;
}
