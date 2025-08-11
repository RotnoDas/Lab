#include<bits/stdc++.h>
using namespace std;
int main() {
    string code, line;
    while(true) {
        getline(cin, line);
        if(line == "$") {
            break;
        }
        code = code + line + "\n";
    }
    int i = 0, commentsIndex = 0;
    string comments;
    bool isComment = false;
    int flag = 0;
    while(i < code.size()) {
        // Single Line Comment
        if(code[i] == '/' && code[i+1] == '/') {
            i += 2;
            while(i < code.size() && code[i] != '\n') {
                comments += code[i];
                i++;
            }
            comments += ' ';
            isComment = true;
            flag = 1;
        }
        // Multi Line Comment
        else if(code[i] == '/' && code[i+1] == '*') {
            i += 2;
            while(i < code.size() && !(code[i] == '*' && code[i+1] == '/')) {
                comments += code[i];
                i++;
            }
            i += 2;
            comments += ' ';
            isComment = true;
            flag = 2;
        }
        else {
            isComment = false;
            flag = 0;
        }
        i++;
    }
    if (isComment) {
        if(flag == 1) {
            cout << "It is a single line comment: " << comments << endl;
            cout << "Number of letters: " << comments.size() << endl;
        }
        else if (flag == 2) {
            cout << "It is a multi line comment: " << comments << endl;
            cout << "Number of letters: " << comments.size() << endl;
        }
    }
    else {
        cout << "It is not a comment\n";
    }
}