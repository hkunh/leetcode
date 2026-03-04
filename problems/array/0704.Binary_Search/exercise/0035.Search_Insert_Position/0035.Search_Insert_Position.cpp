/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */


#include <vector>
using namespace std;
#include <iostream>
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        // cout << right << endl;
        int middle = 0;
        for (middle = (left + right) / 2; left <= right; middle = (left + right) / 2)
        {
            
            if(nums[middle] == target)
                break;
            else if(nums[middle] > target)
            {
                right = middle - 1;
            }
            else if(nums[middle] < target)
            {
                left = middle + 1;
            }
            // cout << middle << endl;
        }
        if(nums[middle] == target)
            return middle;
        else
            return right + 1;
    }
};
// @lc code=end
int main(){

    vector<int> inputs = {1, 3, 5, 6};
    Solution sol;
    int target = 0;
    int result = sol.searchInsert(inputs, target);
    
    cout << "Result: " << result << endl;
    system("pause");
}
