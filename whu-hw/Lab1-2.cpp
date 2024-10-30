#include <iostream>
#include <stack>
#include <string>
#include <cctype>//用于提供isdigit()、isalpha()、isspace()，判断一个char字符是字母、空格还是数字

using namespace std;

// 运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 计算值
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// 计算表达式的值
int evaluate(string expr) {
    stack<int> values;  
    stack<char> ops;    
    int n = expr.length();

    for (int i = 0; i < n; i++) {

        // 当前字符是一个数字
        if (isdigit(expr[i])) {
            int val = 0;
            // 处理多位数字
            while (i < n && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--; // 让循环退回到正确位置
        }
        // 当前字符是一个字母
        else if (isalpha(expr[i])) {
            // 使用字母的 ASCII 值
            values.push((int)expr[i]);//将字母转化为ASCII值的方法————强制类型转换
        }
        // 当前字符是左括号，直接压栈
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        // 当前字符是右括号，处理括号内的表达式
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // 弹出左括号
            ops.pop();
        }
        // 当前字符是运算符
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {//记得考虑优先级，才能入栈
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // 压入当前运算符
            ops.push(expr[i]);
        }
    }

    // 处理剩余的运算符
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    // 表达式的最终结果
    return values.top();
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    for (int i = 0; i < n; i++) {
        string expr1, expr2;
        getline(cin, expr1);
        getline(cin, expr2);

        // 计算两个表达式的值
        int result1 = evaluate(expr1);
        int result2 = evaluate(expr2);

        // 比较结果
        if (result1 == result2) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }
    return 0;
}
