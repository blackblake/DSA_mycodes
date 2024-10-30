#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 求next数组的函数
void getNext(vector<int>& next, const string& s) {
    int j = 0;          // j 表示当前匹配的前缀长度
    next[0] = 0;        // 初始化 next[0] 为 0

    for (int i = 1; i < s.size(); i++) { // 从第二个元素开始遍历
        while (j > 0 && s[i] != s[j]) {  // 如果不相等，回溯 j
            j = next[j - 1];             // 注意这里是 "j-1" 而不是 "i-1"
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;                     // 将 j（前缀的长度）赋给 next[i]
    }
}

// KMP主算法
int KMP(const string& s, const string& t) {
    int n = s.length(), m = t.length();
    if (m == 0) return 0;                // 如果模式串为空，返回0

    vector<int> next(m);                 
    getNext(next, t);                    // 生成模式串 t 的 next 数组

    int i = 0, j = 0;
    while (i < n) {                      // 遍历主串 s
        if (s[i] == t[j]) {              // 字符相同，继续匹配
            i++;
            j++;
        } else {
            if (j > 0) {
                j = next[j - 1];         // j 回退到上次匹配的位置
            } else {
                i++;                     // j == 0，i 前进
            }
        }
        if (j == m) return i - m;        // 匹配成功，返回起始位置
    }
    return -1;                           // 匹配不成功，返回 -1
}

// 测试函数
int main() {
    string s = "ababcabcacbab";   // 主串
    string t = "abcac";           // 模式串
    int position = KMP(s, t);
    
    if (position != -1)
        cout << "success!" << position << endl;
    else
        cout << "fail!" << endl;

    return 0;
}
