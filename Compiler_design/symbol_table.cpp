#include<bits/stdc++.h>
using namespace std;
struct symbol {
    string name, idType, dataType, scope, value;
};
vector<symbol> symbolTable;
void insert(string name, string idType, string dataType, string scope, string value) {
    symbol sym = {name, idType, dataType, scope, value};
    symbolTable.push_back(sym);
}
void parseCode(string code) {
    stringstream codeStream(code);
    string line;
    string scope = "global";
    regex identifierPattern("(int|float|double|char|void)\\s+([a-zA-Z_][a-zA-Z0-9_]*)");
    while(getline(codeStream, line)) {
        smatch match;
        if(regex_search(line, match, identifierPattern)) {
            string dataType = match[1];
            string name = match[2];
            if(line.find('(') != string::npos && line.find(')') != string::npos) {
                insert(name, "function", dataType, scope, "");
                scope = name;
            }
            else {
                insert(name, "variable", dataType, scope, "");
            }
        }
        if(line.find('}') != string::npos) {
            scope = "global";
        }
    }
}
void display() {
    cout << "Symbol Table: \n";
    cout << "Name\tType\t\tDataType\tScope\tValue\n";
    for(auto sym : symbolTable) {
        cout << sym.name << "\t" << sym.idType << "\t" << sym.dataType << "\t\t" << sym.scope << "\t" << sym.value << endl;
    }
}
int main() {
    string code, line;
    cout << "Enter Code: \n";
    while(true) {
        getline(cin, line);
        if(line == "$") {
            break;
        }
        code = code + line + "\n";
    }
    parseCode(code);
    display();
    return 0;
}