#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
    // 如果当前排列已经包含所有元素，则将其加入结果集
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);            // 交换当前元素与起始位置
        backtrack(nums, result, start + 1);    // 递归生成后续排列
        swap(nums[start], nums[i]);            // 撤销交换
    }
}

int main() {
    ifstream infile("in.txt");
    
    vector<int> nums;
    int num;

   
    while (infile >> num) {
        nums.push_back(num);
    }

    vector<vector<int>> result;
    backtrack(nums, result, 0);

   
    for (const auto& permutation : result) {
        for (int n : permutation) {
            cout << n << " ";
        }
        cout << endl;
    }

    infile.close();
    return 0;
}
