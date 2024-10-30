#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// 计算KMP算法的前缀函数（部分匹配表）
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

// KMP算法搜索pattern在text中出现的非重叠次数
int KMP(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    // 如果小饰条的长度大于花布条，直接返回0
    if (m > n) return 0;

    vector<int> pi = computePrefixFunction(pattern);
    int j = 0;  // 模式串中的索引
    int count = 0;  // 记录匹配的次数

    // 遍历主串text
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {  // 完全匹配
            count++;
            j = 0;  // 重置j，以确保非重叠匹配
        }
    }

    return count;
}

int main() {
    ifstream in("in.txt");
    string fabric, ornament;

    // 读取每对花布条和小饰条
    while (in >> fabric >> ornament) {
        if (fabric == "#" || ornament == "#") {
            break;  // 遇到#停止处理
        }

        // 通过KMP算法计算能剪出的最多小饰条的个数
        int result = KMP(fabric, ornament);
        
        // 输出结果
        cout << result << endl;
    }

    return 0;
}
