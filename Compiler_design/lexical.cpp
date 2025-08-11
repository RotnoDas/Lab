#include<bits/stdc++.h>
using namespace std;
vector<string> keywords = {"int", "float", "char", "double", "if", "else", "while", "return", "continue"};
vector<char> operators = {'-', '+', '*', '/', '>'};
vector<char> specialSymbols = {',', ';', '(', ')', '{', '}', '[', ']'};
bool isKeyword(string word) {
    for(auto kw : keywords) {
        if(kw == word) {
            return true;
        }
    }
    return false;
}
bool isIdentifier(string identifier) {
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return false;
    }
    for (char c : identifier) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}
bool isOperator(char opr) {
    for(auto op : operators) {
        if(op == opr) {
            return true;
        }
    }
    return false;
}
bool isSpecial(char symbol) {
    for(auto sym : specialSymbols) {
        if(sym == symbol) {
            return true;
        }
    }
    return false;
}
bool isConstant(char c) {
    return isdigit(c);
}
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
    string comments, keywordsFound, identifierFound, operatorFound, specialFound, constantFound;
    while(i < code.size()) {
        // Single Line Comment
        if(code[i] == '/' && code[i+1] == '/') {
            i += 2;
            while(i < code.size() && code[i] != '\n') {
                comments += code[i];
                i++;
            }
            comments += ' ';
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
        }
        // Checking Keywords and identifiers
        else if(isalpha(code[i]) || code[i] == '_') {
            string word, identifier;
            //int j = i;
            while(i < code.size() && (isalnum(code[i]) || code[i] == '_')) {
                word += code[i];
                identifier += code[i];
                i++;
            }
            if (isKeyword(word)) {
                keywordsFound += word + ' ';
            }
            else if (isIdentifier(identifier)) {
                identifierFound += word + ' ';
            }
        }
        // Checking Operators
        else if (isOperator(code[i])) {
            operatorFound += code[i];
            operatorFound += ' ';
        }
        // Checking Special Symbols
        else if(isSpecial(code[i])) {
            specialFound += code[i];
            specialFound += ' ';
        }
        else if(isConstant(code[i])) {
            //int j = i;
            while (i < code.size() && isdigit(code[i])) {
                constantFound += code[i];
                i++;
            }
        }
        i++;
    }
    cout << "Keywords : " << keywordsFound << endl;
    cout << "Identifiers : " << identifierFound << endl;
    cout << "Operators : " << operatorFound << endl;
    cout << "Special Symbols : " << specialFound << endl;
    cout << "Constants : " << constantFound << endl;
    return 0;
}