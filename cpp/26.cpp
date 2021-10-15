//
//  26.cpp
//  LeetCode
//
//  Created by 윤하연 on 2021/10/15.
//
//  26. Remove Duplicates from Sorted Array
//
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

//  Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
//
//  Return k after placing the final result in the first k slots of nums.
//
//  Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if((int)nums.size() < 2) return (int)nums.size();
        
        int recentIndex = -1;
        int recentNumber = -101;
        int length = (int)nums.size();
        
        for (int i = 0; i < length; i++)
        {
            if(nums[i] == recentNumber) continue;
            
            recentNumber = nums[i];
            nums[++recentIndex] = recentNumber;
            
            if (recentIndex > length) break;
            if (nums[recentIndex] == nums[length-1])
            {
                recentIndex++;
                break;
            }
        }
        return recentIndex;
    }
};

int main (int argc, const char * argv[])
{
    Solution solution;
    std::vector<std::vector<int>> input = {{1, 2}, {1,1,2}, {1,2,2},{1},{0,0,1,1,1,2,2,3,3,4},{}};
    std::vector<int> result = {2,2,2,1,5,0};
    
    for (int i = 0; i < (int)result.size(); i++)
    {
        int answer = solution.removeDuplicates(input[i]);
        if (answer != result[i])
        {
            for(auto num : input[i]) std::cout << num << ", ";
            std::cout << "Count: " << answer << std::endl;
        }
    }
}
