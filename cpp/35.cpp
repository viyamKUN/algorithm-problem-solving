//
//  35.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/10/10.
//
//  35. Search Insert Position
//
//  Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) return i;
        }
        return nums.size();
    }
};

int main(int argc, const char * argv[])
{
    Solution solution;
    std::vector<int> nums = {1,3,5,6};
    int target = 5;
    int result = 2;
    int answer = solution.searchInsert(nums, target);
    if(result != answer)
    {
        std::cout << "FAIL: " << answer << std::endl;
    }
}
