// 287. Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1;
        int high = nums.size() - 1;
        int pivot = findMidNumber(low, high);

        while (low < high)
        {
            if (countLowerSameNumber(nums, pivot) > pivot)
            {
                high = pivot;
            }
            else
            {
                low = pivot + 1;
            }
            pivot = findMidNumber(low, high);
        }
        return pivot;
    }

private:
    int countLowerSameNumber(vector<int> &nums, int target)
    {
        int count = 0;
        for (int num : nums)
        {
            if (num <= target)
            {
                count++;
            }
        }
        return count;
    }

    int findMidNumber(int low, int high)
    {
        return (low + high) / 2;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> input = {{1, 3, 4, 2, 2}, {3, 1, 3, 4, 2}, {2, 2, 2, 2, 2}, {1, 1}, {1, 2, 2}};
    vector<int> answer = {2, 3, 2, 1, 2};
    for (int i = 0; i < input.size(); i++)
    {
        int result = solution.findDuplicate(input[i]);
        if (result != answer[i])
        {
            cout << to_string(i) << "  Answer: " << answer[i] << "  My Answer: " << result << endl;
        }
    }
}
