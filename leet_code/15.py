# Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

# Notice that the solution set must not contain duplicate triplets.


class Solution(object):
    def threeSum(self, nums):
        if len(nums) < 3:
            return []

        result = []
        nums.sort()

        for index in range(len(nums) - 1):
            start = index + 1
            end = len(nums) - 1
            while start < end:
                if nums[index] * -1 == nums[start] + nums[end]:
                    result.append([nums[index], nums[start], nums[end]])
                    start += 1
                    end -= 1
                elif nums[index] * -1 < nums[start] + nums[end]:
                    end -= 1
                else:
                    start += 1

        print(list(set(tuple(row) for row in result)))
        print(result)
        return result


if __name__ == "__main__":
    assert Solution().threeSum([-1, 0, 1, 2, -1, -4]) == [[-1, -1, 2], [-1, 0, 1]]
    assert Solution().threeSum([0, 0, 0, 0]) == [[0, 0, 0]]
    assert Solution().threeSum([]) == []
    assert Solution().threeSum([-1, -1, 0, 1]) == [[-1, 0, 1]]
    assert Solution().threeSum([-2, 0, 0, 2, 2]) == [[-2, 0, 2]]
    assert Solution().threeSum([0]) == []
