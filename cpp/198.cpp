//
// 198. House Robber
// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed,
// the only constraint stopping you from robbing each of them is
// that adjacent houses have security systems connected and it will automatically contact the police
// if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        std::vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        sum[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            sum[i] = std::max(sum[i - 1], sum[i - 2] + nums[i]);
        }
        return std::max(sum[sum.size() - 1], sum[sum.size() - 2]);
    }
};

int main()
{
    Solution solution;
    std::vector<std::vector<int>> input = {{1, 2, 3, 1}, {2, 7, 9, 3, 1}};
    std::vector<int> answer = {4, 12};
    for (int i = 0; i < input.size(); i++)
    {
        int result = solution.rob(input[i]);
        if (result != answer[i])
        {
            std::cout << std::to_string(i) << "  Answer: " << answer[i] << "  My Answer: " << result << std::endl;
        }
    }
    return 0;
}
