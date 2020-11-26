# Given an array of integers nums and an integer target, return indices of the
# two numbers such that they add up to target. You may assume that each input
# would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        want = dict()  # target - num -> index
        for index, num in enumerate(nums):
            if num in want:
                return [want[num], index]
            want[target - num] = index


if __name__ == "__main__":
    assert Solution().twoSum([0, 4, 3, 0], 0) == [0, 3]
