#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        int x, y, result;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                x = operand.top(); operand.pop();
                y = operand.top(); operand.pop();
                result = x + y;
                operand.push(result);
            }
            else if (tokens[i] == "-") {
                x = operand.top(); operand.pop();
                y = operand.top(); operand.pop();
                result = y - x;  // 修正顺序
                operand.push(result);
            }
            else if (tokens[i] == "*") {
                x = operand.top(); operand.pop();
                y = operand.top(); operand.pop();
                result = x * y;
                operand.push(result);
            }
            else if (tokens[i] == "/") {
                x = operand.top(); operand.pop();
                y = operand.top(); operand.pop();
                result = y / x;  // 修正顺序
                operand.push(result);
            }
            else {
                int val = stoi(tokens[i]);
                operand.push(val);
            }
        }
    return operand.top();
}

int main() {
    //ifstream infile("in.txt");
    vector<string> tokens;
    string str;
    while (cin >> str) {  
        tokens.push_back(str);
    }

    cout << evalRPN(tokens) << endl;

    //infile.close();
    return 0;
}
