#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // 从左到右填充上边界
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;

            // 从上到下填充右边界
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;

            // 从右到左填充下边界
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            // 从下到上填充左边界
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};

int main() {
    ifstream infile("in.txt");

    int n;
    infile >> n;

    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(n);

    cout << "[" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ","; // 不在最后一个元素后添加逗号
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ","; // 不在最后一行后添加逗号
        cout << endl;
    }
    cout << "]";

    infile.close();
    return 0;
}
