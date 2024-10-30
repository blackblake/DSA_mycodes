#include <iostream>
#include <fstream>
using namespace std;
// 定义递归函数来计算第n年的母牛数量
int cowCount(int n) {
    // 基础条件
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    // 递推关系
    return cowCount(n - 1) + cowCount(n - 3);
}

int main() {
    std::ifstream infile("in.txt");
    int n;
    if (infile >> n && n > 0 && n < 55) {
        std::cout << cowCount(n) << std::endl;
    }
    infile.close();
    return 0;
}
