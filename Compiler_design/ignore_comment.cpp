#include <bits/stdc++.h>
using namespace std;
bool iscomment(string str) {
    int n = str.size();
    // Check for single-line comment starting with //
    if (n > 1 && str[0] == '/' && str[1] == '/') {
        return true;
    }
    // Check for multi-line comment starting with /* and ending with */
    if (n > 3 && str[0] == '/' && str[1] == '*' && str[n-2] == '*' && str[n-1] == '/') {
        return true;
    }
    return false;
}
int main() {
    string str;
    getline(cin, str);
    bool right = iscomment(str);
    if (right)
        cout << "comment";
    else
        cout << "no comment";
    return 0;
}
