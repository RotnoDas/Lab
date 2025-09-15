#include<bits/stdc++.h>
using namespace std;
bool checkDuplicateIdentifiers(const string &filename) {
    ifstream fin(filename);
    string line, word, prev;
    set<string> identifiers;
    bool errorFound = false;
    while(getline(fin, line)) {
        stringstream ss(line);
        prev.clear();
        while(ss >> word) {
            if(prev == "int" || prev == "float" || prev == "double" || prev == "string" || prev == "char" || prev == "bool") {
                if(!word.empty() && word.back() == ';') {
                    word.pop_back();
                }
                size_t eqPos = word.find('=');
                if(eqPos != string::npos) {
                    word = word.substr(0, eqPos);
                }
                if(identifiers.find(word) != identifiers.end()) {
                    cout << "Duplicate identifier detected" << endl;
                    errorFound = true;
                }
                else {
                    identifiers.insert(word);
                }
            }
            prev = word;
        }
    }
    return errorFound;
}
bool checkBrackets(const string &filename) {
    ifstream fin(filename);
    string line;
    stack<char> st;
    int lineNumber = 0;
    bool errorFound = false;
    while(getline(fin, line)) {
        lineNumber++;
        for(char c : line) {
            if(c == '{' || c == '(' || c == '[') {
                st.push(c);
            }
            else if(c == '}' || c == ')' || c == ']') {
                if(st.empty()) {
                    cout << "BRACKET ERROR " << c << " at line " << lineNumber << endl;
                    errorFound = true;
                }
                else {
                    char open = st.top();
                    st.pop();
                    if((c == '}' && open != '{') || (c == ')' && open != '(') || (c == ']' && open != '[')) {
                        cout << "BRACKET ERROR " << c << " at line " << lineNumber << endl;
                        errorFound = true;
                    }
                }
            }
        }
    }
    while(!st.empty()) {
        cout << "BRACKET ERROR " << st.top() << endl;
        st.pop();
        errorFound = true;
    }
    return errorFound;
}
bool checkCompilerErrors(const string &filename) {
    string command = "g++ " + filename + " -o temp_exec 2> errors.txt";
    system(command.c_str());
    ifstream fin("errors.txt");
    string errorLine;
    bool hasError = false;
    while(getline(fin, errorLine)) {
        if(errorLine.find("expected") != string::npos || errorLine.find("undeclared") != string::npos || errorLine.find("else") != string::npos) {
            cout << "SYNTAX ERROR: " << errorLine << endl;
            hasError = true;
        }
    }
    fin.close();
    return hasError;
}
void getUserCode(const string &filename) {
    cout << "Enter code: \n";
    ofstream fout(filename);
    string line;
    while(true) {
        getline(cin, line);
        if(line == "END") {
            break;
        }
        fout << line << "\n";
    }
    fout.close();
}
int main() {
    string filename = "temp_code.cpp";
    getUserCode(filename);
    bool errorFound = false;
    if(checkCompilerErrors(filename)) {
        errorFound = true;
    }
    if(checkBrackets(filename)) {
        errorFound = true;
    }
    if(checkDuplicateIdentifiers(filename)) {
        errorFound = true;
    }
    if(!errorFound) {
        cout << "No syntax errors detected\n";
    }
    return 0;
}