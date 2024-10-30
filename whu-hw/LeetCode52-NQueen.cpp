#include <iostream>
#include <vector>
#include <fstream>

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<int> queens(n, -1); // queens[i] 表示第 i 行皇后所在的列
        backtrack(queens, 0, count, n);
        return count;
    }

private:
    void backtrack(std::vector<int>& queens, int row, int& count, int n) {
        if (row == n) { // 成功放置所有皇后
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(queens, row, col)) { // 检查当前位置是否合法
                queens[row] = col;
                backtrack(queens, row + 1, count, n);
                queens[row] = -1; // 回溯，重置当前行的皇后位置
            }
        }
    }

    bool isValid(const std::vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || // 检查列冲突
                queens[i] - i == col - row || // 检查左对角线冲突
                queens[i] + i == col + row) { // 检查右对角线冲突
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::ifstream infile("in.txt");
    int n;
    infile >> n;
    infile.close();

    Solution solution;
    int result = solution.totalNQueens(n);

    std::cout << result << std::endl;
    return 0;
}
