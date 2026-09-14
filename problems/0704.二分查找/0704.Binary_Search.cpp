/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //nums 的范围为左闭右闭 []
        int left = 0;
        int right = nums.size() - 1;
        int target_index = -1;
        for (int middle = (left + right) / 2; left <= right; middle = (left + right) / 2)
        {
            if (nums[middle] == target)
            {
                target_index = middle;
                break;     
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return target_index;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};

    int target = 9;
    int result = sol.search(nums, target);
    cout << "Result " << result << endl;
    //等价于
    // cout << "Hello" << "\n";  // 换行
    // cout.flush();             // 刷新输出缓冲区
    system("pause");
    return 0;
}
