#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// 计算KMP算法的前缀函数（部分匹配表）
vector<int> computePrefixFunction(const string &s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    ifstream in("in.txt");
    string s1, s2;
    in >> s1 >> s2;

    // 构造 "s1#s2"
    string combined = s1 + "#" + s2;

    // 计算KMP的前缀函数
    vector<int> pi = computePrefixFunction(combined);

    // 获取最长前缀的长度
    int commonLength = pi.back();

    // 输出结果
    if (commonLength == 0) {
        cout << "0\n";
    } else {
        cout << s1.substr(0, commonLength) << " " << commonLength << "\n";
    }

    return 0;
}
