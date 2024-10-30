#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

stack<pair<int, int>> stack1, stack2; 

int main() {
    ifstream infile("in.txt");
    string operation;
    int N;
    infile >> N;

    for (int i = 1; i <= N; i++) {
        infile >> operation;

        if (operation == "push") {
            string targetStack; infile >> targetStack;
            int value; infile >> value;
             

            if (targetStack == "A") {
                stack1.push(make_pair(i, value)); // 添加操作计数和值
            } else {
                stack2.push(make_pair(i, value));
            }

        } else if (operation == "pop") {
            string targetStack;
            infile >> targetStack;

            if (targetStack == "A") {
                cout << stack1.top().second << endl; // 输出栈顶元素的值
                stack1.pop(); // 删除栈顶元素
            } else {
                cout << stack2.top().second << endl;
                stack2.pop();
            }

        } else if (operation == "merge") {
            string stackA, stackB;
            infile >> stackA >> stackB;

            stack<pair<int, int>> mergedStack; // 中间栈来处理顺序

            // 比较两个栈的时间戳，将较晚的元素先入栈
            while (!stack1.empty() && !stack2.empty()) {
                if (stack1.top().first < stack2.top().first) {
                    mergedStack.push(stack2.top());
                    stack2.pop();
                } else {
                    mergedStack.push(stack1.top());
                    stack1.pop();
                }
            }

            // 把剩下的元素继续放入中间栈
            while (!stack1.empty()) {
                mergedStack.push(stack1.top());
                stack1.pop();
            }
            while (!stack2.empty()) {
                mergedStack.push(stack2.top());
                stack2.pop();
            }

            // 根据 merge 操作，把结果放回指定的栈
            while (!mergedStack.empty()) {
                if (stackA == "A") {
                    stack1.push(mergedStack.top());
                } else {
                    stack2.push(mergedStack.top());
                }
                mergedStack.pop();
            }
        }
    }

    return 0;
}
