#include<bits/stdc++.h>
#define f(x) 1 / (1 + x * x)
using namespace std;
int main() {
    double lowerLimit, upperLimit, interval, h;
    cout << "Enter Lower Limit: ";
    cin >> lowerLimit;
    cout << "Enter Upper Limit: ";
    cin >> upperLimit;
    cout << "Enter number of intervals: ";
    cin >> interval;
    h = (upperLimit - lowerLimit) / interval;
    double result = (f(lowerLimit) + f(upperLimit)) / 2;
    for(int i = 1; i < interval; i++) {
        double value = lowerLimit + i * h;
        result = result + f(value);
    }
    result = result * h;
    cout << "Result is: " << result << endl;
    return 0;
}