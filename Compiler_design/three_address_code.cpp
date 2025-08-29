#include<bits/stdc++.h>
using namespace std;
void display(vector<string> three_address_code) {
    for(auto line : three_address_code) {
        cout << line << endl;
    }
}
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int precedence(char opr) {
    if(opr == '+' || opr == '-') {
        return 1;
    }
    else if(opr == '*' || opr == '/') {
        return 2;
    }
}
void threeAddressCode(string &expression) {
    stack<string> operands;
    stack<char> operators;
    vector<string> three_address_code;
    stringstream ss(expression);
    string token;
    while(ss >> token) {
        if(isOperator(token[0])) {
            while(operators.empty() == false && precedence(operators.top()) >= precedence(token[0])) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                string tempVariable = "t" + to_string(three_address_code.size());
                string temp = tempVariable + " = " + operand1 + " " + operators.top() + " " + operand2;
                three_address_code.push_back(temp);
                operands.push(tempVariable);
                operators.pop();
            }
            operators.push(token[0]);
        }
        else {
            operands.push(token);
        }
    }
    while(operators.empty() == false) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        string tempVariable = "t" + to_string(three_address_code.size());
        string temp = tempVariable + " = " + operand1 + " " + operators.top() + " " + operand2;
        three_address_code.push_back(temp);
        operands.push(tempVariable);
        operators.pop();
    }
    display(three_address_code);
}
int main() {
    string expression;
    cout << "Enter Expression: ";
    getline(cin, expression);
    threeAddressCode(expression);
    return 0;
}